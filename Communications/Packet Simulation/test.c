#include <stdio.h>
#include <stdint.h>
#include "Helpers/header.h"

int main() {
    header rec, send;

    rec.header_array[0] = 0b00111101;
    rec.header_array[1] = 0b01010101;

    rec.header_array[2] = 0b11101010;
    rec.header_array[3] = 0b11111111;
    rec.header_array[4] = 0b11111010;
    rec.header_array[5] = 0b10101111;

    /* Unpack Header Information */
    rec.version_number = get_version_number(rec.header_array);
    rec.packet_type = get_packet_type(rec.header_array);
    rec.sec_header_flag = get_sec_header_flag(rec.header_array);
    rec.APID = get_APID(rec.header_array);
    rec.sequence_flag = get_sequence_flag(rec.header_array);
    rec.sequence_count = get_sequence_count(rec.header_array);
    rec.data_length = get_data_length(rec.header_array);

    printf("Version number: %u\n",rec.version_number);
    printf("Packet type: %u\n",rec.packet_type);
    printf("Secondary header flag: %u\n",rec.sec_header_flag);
    printf("APID: %u\n",rec.APID);

    printf("Sequence flag: %u\n",rec.sequence_flag);
    printf("Sequence count: %u\n",rec.sequence_count);
    printf("Data length: %u\n\n",rec.data_length);

    /* Package Header Information */
    send.header_array[0] = 0;
    send.version_number = rec.version_number;
    send.packet_type = rec.packet_type;
    send.sec_header_flag = rec.sec_header_flag;
    send.APID = rec.APID;
    send.sequence_flag = rec.sequence_flag;
    send.sequence_count = rec.sequence_count;
    send.data_length = rec.data_length;

    set_version_number(send.version_number, send.header_array);
    set_packet_type(send.packet_type, send.header_array);
    set_sec_header_flag(send.sec_header_flag, send.header_array);
    set_APID(send.APID, send.header_array);
    set_sequence_flag(send.sequence_flag, send.header_array);
    set_sequence_count(send.sequence_count, send.header_array);
    set_data_length(send.data_length, send.header_array);

    printf("Header array - byte 0: %u\n", send.header_array[0]);
    printf("Header array - byte 1: %u\n", send.header_array[1]);
    printf("Header array - byte 2: %u\n", send.header_array[2]);
    printf("Header array - byte 3: %u\n", send.header_array[3]);
    printf("Header array - byte 4: %u\n", send.header_array[4]);
    printf("Header array - byte 5: %u\n", send.header_array[5]);

    return 0;
}