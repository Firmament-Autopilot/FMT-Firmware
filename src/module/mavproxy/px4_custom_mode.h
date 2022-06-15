
#ifndef PX4_CUSTOM_MODE_H_
#define PX4_CUSTOM_MODE_H_

enum PX4_CUSTOM_MAIN_MODE {
    PX4_CUSTOM_MAIN_MODE_MANUAL = 1,
    PX4_CUSTOM_MAIN_MODE_ALTCTL,
    PX4_CUSTOM_MAIN_MODE_POSCTL,
    PX4_CUSTOM_MAIN_MODE_AUTO,
    PX4_CUSTOM_MAIN_MODE_ACRO,
    PX4_CUSTOM_MAIN_MODE_OFFBOARD,
    PX4_CUSTOM_MAIN_MODE_STABILIZED,
    PX4_CUSTOM_MAIN_MODE_RATTITUDE,
    PX4_CUSTOM_MAIN_MODE_SIMPLE /* unused, but reserved for future use */
};

enum PX4_CUSTOM_SUB_MODE_AUTO {
    PX4_CUSTOM_SUB_MODE_AUTO_READY = 1,
    PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF,
    PX4_CUSTOM_SUB_MODE_AUTO_LOITER,
    PX4_CUSTOM_SUB_MODE_AUTO_MISSION,
    PX4_CUSTOM_SUB_MODE_AUTO_RTL,
    PX4_CUSTOM_SUB_MODE_AUTO_LAND,
    PX4_CUSTOM_SUB_MODE_AUTO_RESERVED_DO_NOT_USE, // was PX4_CUSTOM_SUB_MODE_AUTO_RTGS, deleted 2020-03-05
    PX4_CUSTOM_SUB_MODE_AUTO_FOLLOW_TARGET,
    PX4_CUSTOM_SUB_MODE_AUTO_PRECLAND
};

enum PX4_CUSTOM_SUB_MODE_POSCTL {
    PX4_CUSTOM_SUB_MODE_POSCTL_POSCTL = 0,
    PX4_CUSTOM_SUB_MODE_POSCTL_ORBIT
};

enum VEHICLE_MODE_FLAG {
    VEHICLE_MODE_FLAG_CUSTOM_MODE_ENABLED = 1,   /* 0b00000001 Reserved for future use. | */
    VEHICLE_MODE_FLAG_TEST_ENABLED = 2,          /* 0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations. | */
    VEHICLE_MODE_FLAG_AUTO_ENABLED = 4,          /* 0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation. | */
    VEHICLE_MODE_FLAG_GUIDED_ENABLED = 8,        /* 0b00001000 guided mode enabled, system flies MISSIONs / mission items. | */
    VEHICLE_MODE_FLAG_STABILIZE_ENABLED = 16,    /* 0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around. | */
    VEHICLE_MODE_FLAG_HIL_ENABLED = 32,          /* 0b00100000 hardware in the loop simulation. All motors / actuators are blocked, but internal software is full operational. | */
    VEHICLE_MODE_FLAG_MANUAL_INPUT_ENABLED = 64, /* 0b01000000 remote control input is enabled. | */
    VEHICLE_MODE_FLAG_SAFETY_ARMED = 128,        /* 0b10000000 MAV safety set to armed. Motors are enabled / running / can start. Ready to fly. | */
    VEHICLE_MODE_FLAG_ENUM_END = 129,            /*  | */
};

#endif