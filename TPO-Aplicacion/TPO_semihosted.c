/*
===============================================================================
 Name        : TPO_semihosted.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <stdio.h>



#include "Infotronic.h"
#include <global_variables.h>
#include <maquina_estado.h>
#include <defines.h>


int main(void) {

    printf("Hello World\n");

    Inicializar ( );

    uint8_t is_moving = 1;



   	while(1)
   	{
   		maquina_estado();
   	}


    return 0 ;
}
