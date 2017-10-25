/*
 * TPO_TIMER.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Maximiliano
 */

//#include "../../../../Documents/Info_II/Info2_TPO/TPO-Headers/Infotronic.h"
//#include <Infotronic.h>
#include <global_variables.h>
//uint32_t cont_periodo = 0;  						// Contador de la cantidad de períodos de 20ms - Global
//uint32_t pos_motor[8] = {54,54,54,54,54,54,54,54}; 	// Vector que guarda la posición instantanea de los motores. Arranca en 54 cuentas que es equivalente a cero grados
////uint32_t pos_motor[8] = {1000,1000,1000,1000,1000,1000,1000,1000}; 	// Vector que guarda la posición instantanea de los motores. Arranca en 54 cuentas que es equivalente a cero grados
//uint8_t flag_dead_time = 0; 						// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición


void TIMER0_IRQHandler (void)
{

	static uint32_t cont_match0 = 0;
	static uint8_t vector[8]; // Agregar #define CANT_MOTORES 8. Vector que guarda los estados de cada pin de cada motor (On/Off)


	T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0

	cont_match0++;

	for(int i=0; i<8 ; i++)
		if(cont_match0 == pos_motor[i])
			vector[i]=0;

	SetPINes(0,vector);

	// ATENCIÓN: DEBE IR EN 250 PERO LO PONEMOS EN 1100!!!!!!!! Quiere decir que arriba de 250 recien hace cuentas
	if(cont_match0 == 250 )
	//if(cont_match0 == 1100 )
		flag_dead_time = 1;


	// llego al final del ciclo de 20ms o 2000 cuentas de mach0
	if(cont_match0 == 2000 )
	{
		cont_match0 = 0;
		cont_periodo ++;
		flag_dead_time = 0;

		// lleno el vector con unos: Estados alto
		for(int i=0; i<8 ; i++)
			vector[i]=1;

		//SetPIN(0,21,1);
		//SetPIN(0,22,1);
		SetPINes( 0 , vector );   // Levanto los pulsos
	}


	// Protege que cont_periodo haga overflow cuando los motores no se usan
	if (cont_periodo == 1000)  // Poner #DEFINE
		cont_periodo = 0;

}
