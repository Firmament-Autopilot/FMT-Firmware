#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define CUAV_EQUIPMENT_POWER_CBAT_MAX_SIZE 124
#define CUAV_EQUIPMENT_POWER_CBAT_SIGNATURE (0xB4DACE3A38E09A74ULL)
#define CUAV_EQUIPMENT_POWER_CBAT_ID 20300

#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_IN_USE 1
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_CHARGING 2
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_CHARGED 4
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_TEMP_HOT 8
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_TEMP_COLD 16
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_OVERLOAD 32
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_BAD_BATTERY 64
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_NEED_SERVICE 128
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_BMS_ERROR 256
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_RESERVED_A 512
#define CUAV_EQUIPMENT_POWER_CBAT_STATUS_FLAG_RESERVED_B 1024

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class cuav_equipment_power_CBAT_cxx_iface;
#endif

struct cuav_equipment_power_CBAT {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = cuav_equipment_power_CBAT_cxx_iface;
#endif
    float temperature;
    float voltage;
    struct { uint8_t len; float data[15]; }voltage_cell;
    uint8_t cell_count;
    float current;
    float average_current;
    float average_power;
    float available_energy;
    float remaining_capacity;
    float full_charge_capacity;
    float design_capacity;
    uint16_t average_time_to_empty;
    uint16_t average_time_to_full;
    uint8_t state_of_health;
    uint8_t state_of_charge;
    uint8_t max_error;
    uint16_t serial_number;
    uint16_t manufacture_date;
    uint16_t cycle_count;
    uint16_t over_discharge_count;
    float passed_charge;
    float nominal_voltage;
    bool is_powering_off;
    uint16_t interface_error;
    uint16_t status_flags;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t cuav_equipment_power_CBAT_encode(struct cuav_equipment_power_CBAT* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool cuav_equipment_power_CBAT_decode(const CanardRxTransfer* transfer, struct cuav_equipment_power_CBAT* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _cuav_equipment_power_CBAT_encode(uint8_t* buffer, uint32_t* bit_ofs, struct cuav_equipment_power_CBAT* msg, bool tao);
static inline void _cuav_equipment_power_CBAT_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct cuav_equipment_power_CBAT* msg, bool tao);
void _cuav_equipment_power_CBAT_encode(uint8_t* buffer, uint32_t* bit_ofs, struct cuav_equipment_power_CBAT* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->temperature);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->voltage);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 4, &msg->voltage_cell.len);
    *bit_ofs += 4;
    for (size_t i=0; i < msg->voltage_cell.len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 32, &msg->voltage_cell.data[i]);
        *bit_ofs += 32;
    }
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->cell_count);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->current);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->average_current);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->average_power);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->available_energy);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->remaining_capacity);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->full_charge_capacity);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->design_capacity);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->average_time_to_empty);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->average_time_to_full);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 7, &msg->state_of_health);
    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 7, &msg->state_of_charge);
    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 7, &msg->max_error);
    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->serial_number);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->manufacture_date);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->cycle_count);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->over_discharge_count);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->passed_charge);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->nominal_voltage);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->is_powering_off);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->interface_error);
    *bit_ofs += 16;
    canardEncodeScalar(buffer, *bit_ofs, 11, &msg->status_flags);
    *bit_ofs += 11;
}

void _cuav_equipment_power_CBAT_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct cuav_equipment_power_CBAT* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->temperature);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->voltage);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 4, false, &msg->voltage_cell.len);
    *bit_ofs += 4;
    for (size_t i=0; i < msg->voltage_cell.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->voltage_cell.data[i]);
        *bit_ofs += 32;
    }

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->cell_count);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->current);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->average_current);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->average_power);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->available_energy);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->remaining_capacity);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->full_charge_capacity);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->design_capacity);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->average_time_to_empty);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->average_time_to_full);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->state_of_health);
    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->state_of_charge);
    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->max_error);
    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->serial_number);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->manufacture_date);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->cycle_count);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->over_discharge_count);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->passed_charge);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->nominal_voltage);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->is_powering_off);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->interface_error);
    *bit_ofs += 16;

    canardDecodeScalar(transfer, *bit_ofs, 11, false, &msg->status_flags);
    *bit_ofs += 11;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct cuav_equipment_power_CBAT sample_cuav_equipment_power_CBAT_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(cuav_equipment_power_CBAT, CUAV_EQUIPMENT_POWER_CBAT_ID, CUAV_EQUIPMENT_POWER_CBAT_SIGNATURE, CUAV_EQUIPMENT_POWER_CBAT_MAX_SIZE);
#endif
#endif
