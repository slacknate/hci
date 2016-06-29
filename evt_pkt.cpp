#include <cstring>
#include "evt_pkt.h"


struct hci_evt_pkt *make_evt_pkt(uint8_t evt_code, uint8_t size) {

    struct hci_evt_pkt *pkt = (struct hci_evt_pkt *)malloc(evt_pkt_size + size);

    if(pkt != nullptr) {

        pkt->size = size;
        pkt->evt_code = evt_code;

        memset(pkt->data, 0, size);
    }

    return pkt;
}
