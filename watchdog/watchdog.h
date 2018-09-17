/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_watchdog__
#define __USER_CODE_H_watchdog__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void watchdog_startup();

void watchdog_PI_purge();

void watchdog_PI_test_cmd(const asn1SccBase_commands_Motion2D *);

extern void watchdog_RI_mot_cmd(const asn1SccBase_commands_Motion2D *);

#ifdef __cplusplus
}
#endif


#endif
