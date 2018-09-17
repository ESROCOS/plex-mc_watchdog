/* User code: This file will not be overwritten by TASTE. */

#include "dummy_producer.h"
#include <base/Time.hpp>
#include <math.h>
#include <iostream>

#define N_SAMPLES 10000
#define TARGET 2*M_PI
#define STEP TARGET/N_SAMPLES
base::Time start;
base::Time now;
base::Time last_break;
base::Time break_every;
base::Time break_dur;
int i_sample;


void dummy_producer_startup()
{
    start = base::Time::now();
    last_break = base::Time::now();
    break_every = base::Time::fromSeconds(20);
    break_dur = base::Time::fromSeconds(5);
    i_sample = 0;
}

void dummy_producer_PI_trigger()
{
    now = base::Time::now();
    if(now - last_break >= break_every){
    	if(now > last_break+break_every+break_dur){
    		last_break = now;
    	}
    	std::cout << "Braking" << std::endl;
    	return;
    }

    asn1SccBase_commands_Motion2D val;
    val.translation = sin(STEP * i_sample);
    val.rotation = 0.5+sin(STEP * i_sample);
    val.heading.rad = 1+sin(STEP * i_sample++);
    std::cout << "Transmitting" << std::endl;
    dummy_producer_RI_test_cmd(&val);

}

