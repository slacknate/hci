#ifndef HCI_CMD_DEFS_H
#define HCI_CMD_DEFS_H

#include <cstdint>

/*
 * OpCode Group Field constants.
 */
const uint16_t OGF_NOOP      = 0x00;
const uint16_t OGF_LINK_CTL  = 0x01;
const uint16_t OGF_LINK_POL  = 0x02;
const uint16_t OGF_HC_BB     = 0x03;
const uint16_t OGF_INFO      = 0x04;
const uint16_t OGF_STATUS    = 0x05;
const uint16_t OGF_TESTING   = 0x06;

const uint16_t OGF_LOGO_TEST = 0x3E;
const uint16_t OGF_VND_COMM  = 0x3F;


/*
 * OpCode Command Field constants.
 */
const uint16_t OCF_NOOP = 0x0000;
/*
 * TODO: finish implementing!
 */

#endif //HCI_COMM_DEFS_H
