#ifndef HCI_SYNC_DATA_PACK_H
#define HCI_SYNC_DATA_PACK_H

#include <cstdint>
#include <cstdlib>

/*
 * TODO: give these real names?
 */
const uint8_t PKT_STATUS_0 = 0x00;
const uint8_t PKT_STATUS_1 = 0x01;
const uint8_t PKT_STATUS_2 = 0x02;
const uint8_t PKT_STATUS_3 = 0x03;

struct hci_sync_data_pkt {

    uint16_t hnd_and_flags;
    uint8_t  size;
    uint8_t  data[];
};

const size_t sync_data_pkt_size = sizeof(struct hci_sync_data_pkt);

struct hci_sync_data_pkt *make_sync_data_pkt(uint16_t handle, uint8_t flags, uint16_t size);

#endif //HCI_SYNC_DATA_PACK_H
