#include <stdint.h>

#ifndef UNPACK
#define UNPACK

/* ---------- Header Struct ---------- */
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

/* ---------- Getter functions ---------- */
/** Function: get_version_number
 *  Address Info: Byte 0, Bits 0-2
 */
uint8_t get_version_number(uint8_t array[6]) {
    return (array[0] >> 5) & (uint8_t)(7);
}

/** Function: get_packet_type
 *  Address Info: Byte 0, Bit 3
 */
uint8_t get_packet_type(uint8_t array[6]) {
    return (array[0] >> 4) & (uint8_t)(1);
}

/** Function: get_secondary_header
 *  Address Info: Byte 0, Bit 4
 */
uint8_t get_sec_header_flag(uint8_t array[6]) {
    return (array[0] >> 3) & (uint8_t)(1);
}

/** Function: get_APID
 *  Address Info: 
 *      MSB - Byte 0, Bits 5-7
 *      LSB - Byte 1, Bits 0-7
 */
uint16_t get_APID(uint8_t array[6]) {
    return (((uint16_t)(array[0]) & (uint16_t)(7)) << 8) + array[1];
}

/** Function: get_sequence_flag
 *  Address Info: Byte 2, Bits 0-1
 */
uint8_t get_sequence_flag(uint8_t array[6]) {
    return (array[2] >> 6) & (uint8_t)(3);
}

/** Function: get_sequence_count
 *  Address Info: 
 *      MSB - Byte 2, Bits 2-7
 *      LSB - Byte 3, Bits 0-7
 */
uint16_t get_sequence_count(uint8_t array[6]) {
    return (((uint16_t)(array[2]) & (uint16_t)(63)) << 8) + array[3];
}

/** Function: get_data_length
 *  Address Info: 
 *      MSB - Byte 4, Bits 0-7
 *      LSB - Byte 5, Bits 0-7
 */
uint16_t get_data_length(uint8_t array[6]) {
    return ((uint16_t)(array[4]) << 8) + array[5];
}

/* ---------- Setter functions ---------- */
/** Function: set_version_number
 *  Address Info: Byte 0, Bits 0-2
 */
void set_version_number(uint8_t version_number, uint8_t *array) {
    array[0] = ((array[0] & (uint8_t)0b00011111) | (version_number << 5));
} 

/** Function: set_packet_type
 *  Address Info: Byte 0, Bits 3
 */
void set_packet_type(uint8_t packet_type, uint8_t *array) {
    array[0] = ((array[0] & (uint8_t)0b11101111) | (packet_type << 4));
} 

/** Function: set_secondary_header
 *  Address Info: Byte 0, Bit 4
 */
void set_sec_header_flag(uint8_t sec_header_flag, uint8_t *array) {
    array[0] = ((array[0] & (uint8_t)0b11110111) | (sec_header_flag << 3));
}

/** Function: set_APID
*  Address Info: 
 *      MSB - Byte 0, Bits 5-7
 *      LSB - Byte 1, Bits 0-7
 */ 
void set_APID(uint16_t APID, uint8_t *array) {
    array[0] = ((array[0] & (uint8_t)0b11111000) | (uint8_t)((APID >> 8) & 0b00000111));
    array[1] = (uint8_t)(APID & 0b11111111);
}

/** Function: set_sequence_flag
*   Address Info: Byte 2, Bits 0-1
 */ 
void set_sequence_flag(uint8_t sequence_flag, uint8_t *array) {
    array[2] = ((array[2] & (uint8_t)0b00111111) | (sequence_flag << 6));
}

/** Function: set_sequence_count
 *  Address Info: 
 *      MSB - Byte 2, Bits 2-7
 *      LSB - Byte 3, Bits 0-7
*/
void set_sequence_count(uint16_t sequence_count, uint8_t *array) {
    array[2] = ((array[2] & (uint8_t)0b11000000) | (uint8_t)((sequence_count >> 8) & 0b00111111));
    array[3] = (uint8_t)(sequence_count & 0b11111111);
}

/** Function: set_data_length
 *  Address Info: 
 *      MSB - Byte 4, Bits 0-7
 *      LSB - Byte 5, Bits 0-7
*/
void set_data_length(uint16_t data_length, uint8_t *array) {
    array[4] = (uint8_t)((data_length >> 8) & 0b11111111);
    array[5] = (uint8_t)(data_length & 0b11111111);
}

#endif