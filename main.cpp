#include "cmd_pack.h"



int main() {

    struct hci_cmd_packet *p = make_cmd_packet(OGF_NOOP, OCF_NOOP, 10);
    destroy_cmd_packet(p);
    return 0;
}