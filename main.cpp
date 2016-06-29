#include "cmd_pack.h"



int main() {

    struct hci_cmd_pkt *p = make_cmd_pkt(OGF_NOOP, OCF_NOOP, 10);
    destroy_cmd_pkt(p);
    return 0;
}