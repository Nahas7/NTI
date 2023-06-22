/*
 * main.c
 *
 * Created: 6/21/2023 5:05:32 PM
 *  Author: user
 */ 

#include <xc.h>
#define F_CPU	16000000UL

#include "AVO.h"


int main(void)
{
	AVO_vidInit();
	
	AVO_vidRun();
}