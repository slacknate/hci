#include <cstring>
#include "acl_data_pkt.h"


static uint16_t make_hnd_and_flags(uint16_t handle, uint8_t flags) {

    uint16_t hnd_and_flags = 0x000000;

    if(handle <= 0x0FFF && flags <= 0x0F) {

        hnd_and_flags = (handle << 4) | flags;
    }
    else {

        /*
         * TODO: error handling
         */
    }

    return hnd_and_flags;
}


struct hci_acl_data_pkt *make_acl_data_pkt(uint16_t handle, uint8_t flags, uint16_t size) {

    struct hci_acl_data_pkt *pkt = (struct hci_acl_data_pkt *)malloc(acl_data_pkt_size + size);

    if(pkt != nullptr) {

        pkt->size = size;
        pkt->hnd_and_flags = make_hnd_and_flags(handle, flags);

        memset(pkt->data, 0, size);
    }

    return pkt;
}


void destroy_acl_data_pkt(struct hci_acl_data_pkt *pkt) {

    free(pkt);
}
