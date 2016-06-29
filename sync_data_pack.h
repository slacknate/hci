#ifndef HCI_SYNC_DATA_PACK_H
#define HCI_SYNC_DATA_PACK_H

#include <cstdint>
#include <cstdlib>
#include "sync_data_defs.h"

struct hci_sync_data_packet {

    uint16_t hnd_and_flags;
    uint8_t  size;
    uint8_t  data[];
};

const size_t sync_data_packet_size = sizeof(struct hci_sync_data_packet);

struct hci_sync_data_packet *make_sync_data_packet(uint16_t handle, uint8_t flags, uint16_t size);
void destroy_sync_data_packet(struct hci_sync_data_packet *packet);

#endif //HCI_SYNC_DATA_PACK_H
