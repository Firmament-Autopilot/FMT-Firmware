/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <FMS.h>
#include <firmament.h>

#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/mission_data.h"

MCN_DEFINE(mission_data, sizeof(Mission_Data_Bus));
MCN_DECLARE(fms_output);
MCN_DECLARE(pilot_cmd);
MCN_DECLARE(gcs_cmd);

static struct mission_item* mission_data;
static uint16_t mission_count;
static Mission_Data_Bus data_bus;
static uint16_t cur_seq;
static McnNode_t fms_out_nod;
static McnNode_t pilot_cmd_nod;
static McnNode_t gcs_cmd_nod;
static uint8_t loop_mission;
const static uint16_t mission_data_size = sizeof(data_bus.seq) / sizeof(data_bus.seq[0]);

static int mission_data_echo(void* param)
{
    Mission_Data_Bus mission_data;
    int i;

    mcn_copy_from_hub((McnHub*)param, &mission_data);

    printf("timestamp:%u\n", mission_data.timestamp);
    printf("valid items: %d\n", mission_data.valid_items);

    printf("seq: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.seq[i]);
    }
    printf("]\n");

    printf("command: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.command[i]);
    }
    printf("]\n");

    printf("frame: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.frame[i]);
    }
    printf("]\n");

    printf("current: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.current[i]);
    }
    printf("]\n");

    printf("autocontinue: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.autocontinue[i]);
    }
    printf("]\n");

    printf("mission_type: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.mission_type[i]);
    }
    printf("]\n");

    printf("mission_type: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.mission_type[i]);
    }
    printf("]\n");

    printf("param1: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%.3f,", mission_data.param1[i]);
    }
    printf("]\n");

    printf("param2: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%.3f,", mission_data.param2[i]);
    }
    printf("]\n");

    printf("param3: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%.3f,", mission_data.param3[i]);
    }
    printf("]\n");

    printf("param4: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%.3f,", mission_data.param4[i]);
    }
    printf("]\n");

    printf("x: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.x[i]);
    }
    printf("]\n");

    printf("y: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%d,", mission_data.y[i]);
    }
    printf("]\n");

    printf("z: [");
    for (i = 0; i < mission_data.valid_items; i++) {
        printf("%.3f,", mission_data.z[i]);
    }
    printf("]\n");

    printf("------------------------------------------\n");

    return 0;
}

inline static uint16_t increase_seq(uint16_t seq)
{
    seq++;

    if (loop_mission) {
        seq = seq % mission_count;
    }

    return seq;
}

uint16_t get_mission_count(void)
{
    return mission_count;
}

struct mission_item* get_mission_item(uint16_t seq)
{
    if (seq >= mission_count || mission_data == NULL) {
        return NULL;
    }

    return &mission_data[seq];
}

fmt_err_t mission_reset(void)
{
    /* reset current sequence number */
    cur_seq = 0;

    data_bus.timestamp = systime_now_ms();

    if (loop_mission) {
        data_bus.valid_items = (mission_count > 0) ? mission_data_size : 0;
    } else {
        data_bus.valid_items = (mission_count > mission_data_size) ? mission_data_size : mission_count;
    }

    for (uint16_t i = 0; i < data_bus.valid_items; i++) {

        /* skip some command which is not waypoint */
        if (loop_mission) {
            /* skip some command which is not waypoint */
            if (loop_mission) {
                while (mission_data[cur_seq].command != MAV_CMD_NAV_WAYPOINT) {
                    if (mission_data[cur_seq].command == MAV_CMD_NAV_TAKEOFF && i == 0) {
                        /* allow the first takeoff command */
                        break;
                    }
                    /* increase current sequence */
                    cur_seq = increase_seq(cur_seq);
                }
            }
        }

        data_bus.seq[i] = mission_data[cur_seq].seq;
        data_bus.command[i] = mission_data[cur_seq].command;
        data_bus.frame[i] = mission_data[cur_seq].frame;
        data_bus.current[i] = mission_data[cur_seq].current;
        data_bus.autocontinue[i] = mission_data[cur_seq].autocontinue;
        data_bus.mission_type[i] = mission_data[cur_seq].mission_type;
        data_bus.param1[i] = mission_data[cur_seq].param1;
        data_bus.param2[i] = mission_data[cur_seq].param2;
        data_bus.param3[i] = mission_data[cur_seq].param3;
        data_bus.param4[i] = mission_data[cur_seq].param4;
        data_bus.x[i] = mission_data[cur_seq].x;
        data_bus.y[i] = mission_data[cur_seq].y;
        data_bus.z[i] = mission_data[cur_seq].z;

        /* increase current sequence */
        cur_seq = increase_seq(cur_seq);
    }
    /* publish the initial mission data */
    FMT_TRY(mcn_publish(MCN_HUB(mission_data), &data_bus));

    return FMT_EOK;
}

fmt_err_t clear_mission_data(const char* path)
{
    if (unlink(path) != 0) {
        printf("fail to remove mission file %s\n", path);
        return FMT_ERROR;
    }

    mission_count = 0;

    if (mission_data != NULL) {
        rt_free(mission_data);
        mission_data = NULL;
    }

    return FMT_EOK;
}

fmt_err_t load_mission_data(const char* path)
{
    FILE* fp;
    uint16_t cnt = 0;
    struct mission_item* mdp;

    fp = fopen(path, "r");

    if (fp != NULL) {
        /* read mission count, which is in the first line */
        fscanf(fp, "%hu", &mission_count);
        if (mission_count == 0) {
            fclose(fp);
            return FMT_EOK;
        }
        /* malloc memory for mission data */
        if (mission_data != NULL) {
            rt_free(mission_data);
            mission_data = NULL;
        }
        mission_data = (struct mission_item*)rt_malloc(mission_count * sizeof(struct mission_item));
        if (mission_data == NULL) {
            fclose(fp);
            return FMT_ENOMEM;
        }

        mdp = mission_data;
        while (!feof(fp) && cnt < mission_count) {
            /* Mission file format:
            * <INDEX> <CURRENT WP> <COORD FRAME> <COMMAND> <PARAM1> <PARAM2> <PARAM3> <PARAM4> 
            * <PARAM5/X/LATITUDE> <PARAM6/Y/LONGITUDE> <PARAM7/Z/ALTITUDE> <AUTOCONTINUE> 
            */
            fscanf(fp, "%hu %hhu %hhu %hu %f %f %f %f %ld %ld %f %hhu", &mdp->seq, &mdp->current, &mdp->frame, &mdp->command, &mdp->param1, &mdp->param2, &mdp->param3, &mdp->param4, &mdp->x, &mdp->y, &mdp->z, &mdp->autocontinue);

            mdp++;
            cnt++;
        }
        fclose(fp);
    }

    return FMT_EOK;
}

void dump_mission_data(void)
{
    uint16_t i;
    struct mission_item* mdp = mission_data;

    for (i = 0; i < mission_count; i++, mdp++) {
        printf("%hu\t%hhu\t%hhu\t%hu\t%f\t%f\t%f\t%f\t%ld\t%ld\t%f\t%hhu\n", mdp->seq, mdp->current, mdp->frame, mdp->command, mdp->param1, mdp->param2, mdp->param3, mdp->param4, mdp->x, mdp->y, mdp->z, mdp->autocontinue);
    }
}

fmt_err_t mission_data_collect(void)
{
    /* The default vehicle status is Disarm */
    static FMS_Out_Bus old_fms_out = { .status = VehicleStatus_Disarm };

    if (mcn_poll(fms_out_nod)) {
        FMS_Out_Bus fms_out;
        uint16_t i;

        FMT_TRY(mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out));

        if (fms_out.status != old_fms_out.status) {
            old_fms_out.status = fms_out.status;
            if (fms_out.status == VehicleStatus_Disarm) {
                /* if the vehicle disarmed, reset mission */
                mission_reset();
            }
        }

        if (fms_out.mode == PilotMode_Mission) {
            /* check if there are comsumed waypoints */
            if (fms_out.wp_consume > 0) {
                /* update timestamp */
                data_bus.timestamp = systime_now_ms();

                /* first move items which are still valid from back to the front */
                for (i = 0; i < data_bus.valid_items - fms_out.wp_consume; i++) {
                    data_bus.seq[i] = data_bus.seq[fms_out.wp_consume + i];
                    data_bus.command[i] = data_bus.command[fms_out.wp_consume + i];
                    data_bus.frame[i] = data_bus.frame[fms_out.wp_consume + i];
                    data_bus.current[i] = data_bus.current[fms_out.wp_consume + i];
                    data_bus.autocontinue[i] = data_bus.autocontinue[fms_out.wp_consume + i];
                    data_bus.mission_type[i] = data_bus.mission_type[fms_out.wp_consume + i];
                    data_bus.param1[i] = data_bus.param1[fms_out.wp_consume + i];
                    data_bus.param2[i] = data_bus.param2[fms_out.wp_consume + i];
                    data_bus.param3[i] = data_bus.param3[fms_out.wp_consume + i];
                    data_bus.param4[i] = data_bus.param4[fms_out.wp_consume + i];
                    data_bus.x[i] = data_bus.x[fms_out.wp_consume + i];
                    data_bus.y[i] = data_bus.y[fms_out.wp_consume + i];
                    data_bus.z[i] = data_bus.z[fms_out.wp_consume + i];
                }

                /* then add new data to mission item list if any */
                if (data_bus.valid_items < mission_data_size) {
                    /* no new mission item, just consume current item in the list*/
                    if (data_bus.valid_items > fms_out.wp_consume) {
                        data_bus.valid_items = data_bus.valid_items - fms_out.wp_consume;
                    } else {
                        /* mission completed */
                        data_bus.valid_items = 0;
                    }
                } else { /* data_bus.valid_items == mission_data_size */
                    /* add new mission item */
                    uint16_t num_to_add = fms_out.wp_consume;
                    uint16_t start = data_bus.valid_items - fms_out.wp_consume;

                    /* if there aren't enough data, only left data added */
                    if (!loop_mission && num_to_add > (mission_count - cur_seq)) {
                        num_to_add = mission_count - cur_seq;
                    }

                    for (i = start; i < start + num_to_add; i++) {

                        /* skip some command which is not waypoint */
                        if (loop_mission) {
                            while (mission_data[cur_seq].command != MAV_CMD_NAV_WAYPOINT) {
                                /* increase current sequence */
                                cur_seq = increase_seq(cur_seq);
                            }
                        }

                        data_bus.seq[i] = mission_data[cur_seq].seq;
                        data_bus.command[i] = mission_data[cur_seq].command;
                        data_bus.frame[i] = mission_data[cur_seq].frame;
                        data_bus.current[i] = mission_data[cur_seq].current;
                        data_bus.autocontinue[i] = mission_data[cur_seq].autocontinue;
                        data_bus.mission_type[i] = mission_data[cur_seq].mission_type;
                        data_bus.param1[i] = mission_data[cur_seq].param1;
                        data_bus.param2[i] = mission_data[cur_seq].param2;
                        data_bus.param3[i] = mission_data[cur_seq].param3;
                        data_bus.param4[i] = mission_data[cur_seq].param4;
                        data_bus.x[i] = mission_data[cur_seq].x;
                        data_bus.y[i] = mission_data[cur_seq].y;
                        data_bus.z[i] = mission_data[cur_seq].z;

                        /* increase current sequence */
                        cur_seq = increase_seq(cur_seq);
                    }

                    data_bus.valid_items = start + num_to_add;
                }

                /* publish new mission data */
                FMT_TRY(mcn_publish(MCN_HUB(mission_data), &data_bus));
            }
        }
    }

    return FMT_EOK;
}

fmt_err_t mission_data_init(void)
{
    FMT_TRY(mcn_advertise(MCN_HUB(mission_data), mission_data_echo));

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    if (fms_out_nod == NULL) {
        return FMT_ERROR;
    }

    pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    if (pilot_cmd_nod == NULL) {
        return FMT_ERROR;
    }

    gcs_cmd_nod = mcn_subscribe(MCN_HUB(gcs_cmd), NULL, NULL);
    if (gcs_cmd_nod == NULL) {
        return FMT_ERROR;
    }

    /* loop_mission will only be updated when system reboot */
    loop_mission = PARAM_GET_UINT8(SYSTEM, LOOP_MISSION);

    FMT_TRY(load_mission_data(MISSION_FILE));
    FMT_TRY(mission_reset());

    return FMT_EOK;
}