#ifndef HCI_CMD_PACK_H
#define HCI_CMD_PACK_H

#include <cstdint>
#include <cstdlib>
#include "cmd_defs.h"

struct hci_cmd_pkt {

    uint16_t opcode;
    uint8_t  size;
    uint8_t  data[];
};

const size_t cmd_pkt_size = sizeof(struct hci_cmd_pkt);

struct hci_cmd_pkt *make_cmd_pkt(uint16_t ogf, uint16_t ocf, uint8_t size);

#endif //HCI_CMD_PACK_H
