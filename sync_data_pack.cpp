#include <cstring>
#include "sync_data_pack.h"


static uint16_t make_hnd_and_flags(uint16_t handle, uint8_t flags) {

    uint16_t hnd_and_flags = 0x000000;

    if(handle <= 0x0FFF && flags <= 0x03) {

        hnd_and_flags = (handle << 4) | (flags << 2);
    }
    else {

        /*
         * TODO: error handling
         */
    }

    return hnd_and_flags;
}


struct hci_sync_data_packet *make_sync_data_packet(uint16_t handle, uint8_t flags, uint8_t size) {

    struct hci_sync_data_packet *packet = (struct hci_sync_data_packet *)malloc(sync_data_packet_size + size);

    if(packet != nullptr) {

        packet->size = size;
        packet->hnd_and_flags = make_hnd_and_flags(handle, flags);

        memset(packet->data, 0, size);
    }

    return packet;
}


void destroy_sync_data_packet(struct hci_sync_data_packet *packet) {

    free(packet);
}
