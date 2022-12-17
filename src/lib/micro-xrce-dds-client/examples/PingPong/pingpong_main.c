
#include "Header.h"
#include <ucdr/microcdr.h>
#include <uxr/client/client.h>

#include "hal/serial/serial.h"
#include <firmament.h>
#include <stdio.h>

#define STREAM_HISTORY 1
#define BUFFER_SIZE    UXR_CONFIG_SERIAL_TRANSPORT_MTU* STREAM_HISTORY

void on_topic(uxrSession* session, uxrObjectId object_id, uint16_t request_id, uxrStreamId stream_id, struct ucdrBuffer* ub, uint16_t length, void* args)
{
    (void)session;
    (void)object_id;
    (void)request_id;
    (void)stream_id;
    (void)length;
    (void)args;

    Header topic;
    Header_deserialize_topic(ub, &topic);
}

int pingpong_main(void)
{
    uxrSerialTransport transport;
    uxrSerialPlatform serial_platform;

    rt_device_t dev = rt_device_find("serial0");
    serial_dev_t serial_dev = (serial_dev_t)dev;

    if (!(dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
        rt_err_t err = rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
        if (err != RT_EOK) {
            printf("fail open serial0 device: %ld\n", err);
        }

        struct serial_configure pconfig = serial_dev->config;
        pconfig.baud_rate = 115200;
        if (rt_device_control(dev, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    if (!uxr_init_serial_transport(&transport, &serial_platform, (int)dev, 0, 1)) {
        printf("Error at create transport.\n");
        return 1;
    }

    // Session
    uxrSession session;
    uxr_init_session(&session, &transport.comm, 0xABCDABCD);
    uxr_set_topic_callback(&session, on_topic, NULL);
    if (!uxr_create_session(&session)) {
        console_printf("Error at create session.\n");
        return 1;
    }

    // Streams
    uint8_t output_reliable_stream_buffer[BUFFER_SIZE];
    uxrStreamId reliable_out = uxr_create_output_reliable_stream(&session, output_reliable_stream_buffer, BUFFER_SIZE, STREAM_HISTORY);

    uint8_t input_reliable_stream_buffer[BUFFER_SIZE];
    uxr_create_input_reliable_stream(&session, input_reliable_stream_buffer, BUFFER_SIZE, STREAM_HISTORY);

    // Create entities
    uxrObjectId participant_id = uxr_object_id(0x01, UXR_PARTICIPANT_ID);
    const char* participant_xml = "<dds>"
                                  "<participant>"
                                  "<rtps>"
                                  "<name>pingpong_node</name>"
                                  "</rtps>"
                                  "</participant>"
                                  "</dds>";
    uint16_t participant_req = uxr_buffer_create_participant_xml(&session, reliable_out, participant_id, 0, participant_xml, UXR_REPLACE);

    uxrObjectId topic_id = uxr_object_id(0x01, UXR_TOPIC_ID);
    const char* topic_xml = "<dds>"
                            "<topic>"
                            "<name>rt/microROS/ping</name>"
                            "<dataType>std_msgs::msg::dds_::Header_</dataType>"
                            "</topic>"
                            "</dds>";
    uint16_t topic_req = uxr_buffer_create_topic_xml(&session, reliable_out, topic_id, participant_id, topic_xml, UXR_REPLACE);

    uxrObjectId publisher_id = uxr_object_id(0x01, UXR_PUBLISHER_ID);
    const char* publisher_xml = "";
    uint16_t publisher_req = uxr_buffer_create_publisher_xml(&session, reliable_out, publisher_id, participant_id, publisher_xml, UXR_REPLACE);

    uxrObjectId datawriter_id = uxr_object_id(0x01, UXR_DATAWRITER_ID);
    const char* datawriter_xml = "<dds>"
                                 "<data_writer>"
                                 "<topic>"
                                 "<kind>NO_KEY</kind>"
                                 "<name>rt/microROS/ping</name>"
                                 "<dataType>std_msgs::msg::dds_::Header_</dataType>"
                                 "</topic>"
                                 "</data_writer>"
                                 "</dds>";
    uint16_t datawriter_req = uxr_buffer_create_datawriter_xml(&session, reliable_out, datawriter_id, publisher_id, datawriter_xml, UXR_REPLACE);

    // Send create entities message and wait its status
    uint8_t status[4];
    uint16_t requests[4] = { participant_req, topic_req, publisher_req, datawriter_req };
    if (!uxr_run_session_until_all_status(&session, 1000, requests, status, 4)) {
        console_printf("Error at create entities: participant: %i topic: %i publisher: %i darawriter: %i\n", status[0], status[1], status[2], status[3]);
        return 1;
    }

    // Write topics
    bool connected = true;
    uint32_t count = 0;
    Header topic;
    sprintf(topic.frame_id, "Hello RT-Thread!\n");
    DEFINE_TIMETAG(topic_send, 5000);
    while (connected && count < 100) {
        if (check_timetag(TIMETAG(topic_send))) {
            uint32_t time_now_ms = systime_now_ms();
            topic.stamp.sec = time_now_ms / 1000;
            topic.stamp.nanosec = (time_now_ms % 1000) * 1e6;

            ucdrBuffer ub;
            uint32_t topic_size = Header_size_of_topic(&topic, 0);
            uxr_prepare_output_stream(&session, reliable_out, datawriter_id, &ub, topic_size);
            Header_serialize_topic(&ub, &topic);

            printf("Send topic: %s at %ld\n", topic.frame_id, topic.stamp.sec);
            connected = uxr_run_session_until_confirm_delivery(&session, 1000);
        }
    }

    // Delete resources
    uxr_delete_session(&session);
    uxr_close_serial_transport(&transport);

    return 0;
}