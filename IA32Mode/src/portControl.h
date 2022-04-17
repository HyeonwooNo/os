#ifndef __PORT_CONTROL_H__
#define __PORT_CONTROL_H__
#include "Type.h"

BYTE getPort(WORD port);
void setPort(WORD port, BYTE data);

#endif
