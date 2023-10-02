#include <stdio.h>
#include <stdint.h>
#include "Helpers/header.h"

int main() {
    header rec;

    rec.header_array[0] = 0b00111101;
    rec.header_array[1] = 0b01010101;

    rec.header_array[2] = 0b11101010;
    rec.header_array[3] = 0b11111111;
    rec.header_array[4] = 0b10101010;
    rec.header_array[5] = 0b10101010;

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
    printf("Data length: %u\n",rec.data_length);

    return 0;
}