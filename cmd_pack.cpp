#include <cstring>
#include "cmd_pack.h"


static uint16_t make_opcode(uint16_t ogf, uint16_t ocf) {

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


struct hci_cmd_pkt *make_cmd_pkt(uint16_t ogf, uint16_t ocf, uint8_t size) {

    struct hci_cmd_pkt *pkt = (struct hci_cmd_pkt *)malloc(cmd_pkt_size + size);

    if(pkt != nullptr) {

        pkt->size = size;
        pkt->opcode = make_opcode(ogf, ocf);

        memset(pkt->data, 0, size);
    }

    return pkt;
}


void destroy_cmd_pkt(struct hci_cmd_pkt *pkt) {

    free(pkt);
}
