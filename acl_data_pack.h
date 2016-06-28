#ifndef HCI_ACL_DATA_PACK_H
#define HCI_ACL_DATA_PACK_H

#include <cstdint>
#include <cstdlib>

struct hci_acl_data_packet {

    uint16_t hnd_and_flags;
    uint16_t size;
    uint8_t  *data;
};

const size_t acl_data_packet_size = sizeof(struct hci_acl_data_packet);

struct hci_acl_data_packet *make_acl_data_packet(uint16_t handle, uint8_t flags, uint16_t size);
void destroy_acl_data_packet(struct hci_acl_data_packet *packet);

#endif //HCI_ACL_DATA_PACK_H
