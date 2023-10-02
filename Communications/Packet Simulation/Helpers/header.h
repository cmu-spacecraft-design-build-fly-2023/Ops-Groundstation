#include <stdint.h>

#ifndef UNPACK
#define UNPACK

typedef struct spp_header {
    uint8_t header_array[6];
    uint8_t version_number;
    uint8_t packet_type;
    uint8_t sec_header_flag;
    uint16_t APID;
    uint8_t sequence_flag;
    uint16_t sequence_count;
    uint16_t data_length;
} header;

uint8_t get_version_number(uint8_t array[6]) {
    return (array[0] >> 5) & (uint8_t)(7);
}

uint8_t get_packet_type(uint8_t array[6]) {
    return (array[0] >> 4) & (uint8_t)(1);
}

uint8_t get_sec_header_flag(uint8_t array[6]) {
    return (array[0] >> 3) & (uint8_t)(1);
}

uint16_t get_APID(uint8_t array[6]) {
    return (((uint16_t)(array[0]) & (uint16_t)(7)) << 8) + array[1];
}

uint8_t get_sequence_flag(uint8_t array[6]) {
    return (array[2] >> 6) & (uint8_t)(3);
}

uint16_t get_sequence_count(uint8_t array[6]) {
    return (((uint16_t)(array[2]) & (uint16_t)(63)) << 8) + array[3];
}

uint16_t get_data_length(uint8_t array[6]) {
    return ((uint16_t)(array[4]) << 8) + array[5];
}

#endif