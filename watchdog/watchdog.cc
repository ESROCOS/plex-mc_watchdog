/* User code: This file will not be overwritten by TASTE. */

#include "watchdog.h"
#include "BipWrapper.h"
#include <thread>

void watchdog_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
    initialize_model();
		std::thread *thrd = new thread(start_engine);
}

void watchdog_PI_purge()
{
    /* Write your code here! */
    execute_purge();
}

void watchdog_PI_test_cmd(const asn1SccBase_commands_Motion2D *IN_cmd_val)
{
    /* Write your code here! */
    execute_port_test_cmd(IN_cmd_val);
}

