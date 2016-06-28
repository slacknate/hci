#include <cstring>
#include "acl_data_pack.h"


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


struct hci_acl_data_packet *make_acl_data_packet(uint16_t handle, uint8_t flags, uint16_t size) {

    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * size);
    struct hci_acl_data_packet *packet = (struct hci_acl_data_packet *)malloc(acl_data_packet_size);

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
        packet->hnd_and_flags = make_hnd_and_flags(handle, flags);
    }

    return packet;
}


void destroy_acl_data_packet(struct hci_acl_data_packet *packet) {

    free(packet->data);
    free(packet);
}
