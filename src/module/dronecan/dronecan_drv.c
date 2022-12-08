#include "dronecan_drv.h"

int16_t dronecanTransmit(rt_device_t dronecan_dev, const CanardCANFrame* frame)
{
    can_msg msg;

    msg.id = frame->id; // TODO: Map flags properly
    msg.len = frame->data_len;
    memcpy(msg.data, frame->data, frame->data_len);

    const ssize_t nbytes = rt_device_write(dronecan_dev, 0, &msg, sizeof(can_msg));

    if (nbytes < 0) {
        return RT_ERROR;
    }

    return nbytes;
}

int16_t dronecanReceive(rt_device_t dronecan_dev, CanardCANFrame* out_frame)
{
    can_msg receive_frame;

    const ssize_t nbytes = rt_device_read(dronecan_dev, 0, &receive_frame, sizeof(receive_frame));
    if (nbytes < 0) {
        return RT_ERROR;
    }

    out_frame->id = receive_frame.id; // TODO: Map flags properly
    out_frame->data_len = receive_frame.len;
    memcpy(out_frame->data, &receive_frame.data, receive_frame.len);

    out_frame->id |= CANARD_CAN_FRAME_EFF;

    // printf("out_frame->id=0x%x\n", out_frame->id);
    // printf("out_frame->data_len=%d\n", out_frame->data_len);

    // printf("receive_frame.data:");
    // for (uint8_t i = 0; i < out_frame->data_len; i++)
    //     printf("0x%x ", out_frame->data[i]);
    // printf("\n");

    return 1;
}
