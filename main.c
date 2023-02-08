/*
 * On-demand Traffic Light Control.c
 *
 * Created: 1/16/2023 12:07:19 PM
 * Author : Nezar
 */ 

/* Includes */
//#include <avr/io.h>
#include "App/app.h"

/* Main Function Definition */
int main(void)
{
	//APP_testTimer();
		
	//APP_testModule();
    
	APP_init();
	
    for(;;)
    {
		APP_start();
    }
}

