#include <cstdlib>
#include <cstring>
#include "cmd_pack.h"


uint16_t make_opcode(uint16_t ogf, uint16_t ocf) {

    uint16_t opcode = 0x000000;

    if(ogf <= 0x3F && ocf <= 0x03FF) {

        opcode = (ogf << 10) | ocf;
    }
    else {

        /*
         * TODO: error handling
         */
    }

    return opcode;
}


struct hci_cmd_packet *make_cmd_packet(uint16_t ogf, uint16_t ocf, uint8_t size) {

    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * size);
    struct hci_cmd_packet *packet = (struct hci_cmd_packet *)malloc(cmd_packet_size);

    if(data == nullptr && packet != nullptr) {

        free(packet);
        packet = nullptr;
    }
    else if(data != nullptr && packet == nullptr) {

        free(data);
    }
    else if(data != nullptr && packet != nullptr) {

        memset(data, 0, size);

        packet->data = data;
        packet->size = size;
        packet->opcode = make_opcode(ogf, ocf);
    }

    return packet;
}


void destroy_cmd_packet(struct hci_cmd_packet *packet) {

    free(packet->data);
    free(packet);
}
