#ifndef HCI_ACL_DATA_PACK_H
#define HCI_ACL_DATA_PACK_H

#include <cstdint>
#include <cstdlib>

/*
 * TODO: give these real names?
 */
const uint8_t PB_FLAG_0 = 0x00;
const uint8_t PB_FLAG_1 = 0x01;
const uint8_t PB_FLAG_2 = 0x02;
const uint8_t PB_FLAG_3 = 0x03;

/*
 * TODO: give these real names?
 */
const uint8_t BC_FLAG_0 = 0x00;
const uint8_t BC_FLAG_1 = 0x01;
const uint8_t BC_FLAG_2 = 0x02;
const uint8_t BC_FLAG_3 = 0x03;

struct hci_acl_data_pkt {

    uint16_t hnd_and_flags;
    uint16_t size;
    uint8_t  data[];
};

const size_t acl_data_pkt_size = sizeof(struct hci_acl_data_pkt);

struct hci_acl_data_pkt *make_acl_data_pkt(uint16_t handle, uint8_t flags, uint16_t size);

#endif //HCI_ACL_DATA_PACK_H
