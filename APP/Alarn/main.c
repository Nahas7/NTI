



#define F_CPU 16000000UL
#include "alarm.h"


int main(void)
{
	alarm_init();
	alarm_run();
}

