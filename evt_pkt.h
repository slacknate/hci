#ifndef HCI_EVT_PKT_H
#define HCI_EVT_PKT_H

#include <cstdint>
#include <cstdlib>

const uint8_t EVT_CODE_VND = 0xFF;

struct hci_evt_pkt {

    uint8_t evt_code;
    uint8_t size;
    uint8_t data[];
};

const size_t evt_pkt_size = sizeof(struct hci_evt_pkt);

struct hci_evt_pkt *make_evt_pkt(uint8_t evt_code, uint8_t size);

#endif //HCI_EVT_PKT_H
