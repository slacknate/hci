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


struct hci_sync_data_pkt *make_sync_data_pkt(uint16_t handle, uint8_t flags, uint8_t size) {

    struct hci_sync_data_pkt *pkt = (struct hci_sync_data_pkt *)malloc(sync_data_pkt_size + size);

    if(pkt != nullptr) {

        pkt->size = size;
        pkt->hnd_and_flags = make_hnd_and_flags(handle, flags);

        memset(pkt->data, 0, size);
    }

    return pkt;
}


void destroy_sync_data_pkt(struct hci_sync_data_pkt *pkt) {

    free(pkt);
}
