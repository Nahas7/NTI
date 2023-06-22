



#define F_CPU 8000000UL
#include "alarm.h"


int main(void)
{
	
	alarm_init();
	alarm_run();
}

