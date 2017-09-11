/*
 * TPO_TIMER.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Maximiliano
 */

#include "../../../../Documents/Info_II/Info2_TPO/TPO-Headers/Infotronic.h"


uint32_t cont_periodo = 0;  						// Contador de la cantidad de períodos de 20ms - Global
uint8_t pos_motor[8] = {54,54,54,54,54,54,54,54}; 	// Vector que guarda la posición instantanea de los motores. Arranca en 54 cuentas que es equivalente a cero grados
uint8_t flag_dead_time = 0; 						// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición


void TIMER0_IRQHandler (void)
{

	static uint32_t cont_match0 = 0;
	static uint8_t vector[7]; // Agregar #define CANT_MOTORES 8


	T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0

	cont_match0++;

	// Cuando definamos el vector de posición dejar el ciclo FOR y sacar el resto de los IF
	for(int i = 0; i<8 ; i++)
		if(cont_match0 == pos_motor[i])
			vector[i]=0;
/*
	if(cont_match0 == pos_m0)
		vector[0] = 0; // P0.16
	if(cont_match0 == pos_m1)
		vector[1] = 0;  // P0.17
	if(cont_match0 == pos_m0)
		vector[2] = 0; // P0.18
	if(cont_match0 == pos_m1)
		vector[3] = 0;  // P0.19
	if(cont_match0 == pos_m0)
		vector[4] = 0; // P0.20
	if(cont_match0 == pos_m1)
		vector[5] = 0;  // P0.21
	if(cont_match0 == pos_m0)
		vector[6] = 0; // P0.22
	if(cont_match0 == pos_m1)
		vector[7] = 0;  // P0.23
*/

	SetPINes( 0 , vector );


	if(cont_match0 == 250 )
		flag_dead_time = 1;


	// llego al final del ciclo de 20ms
	if(cont_match0 == 2000 )
	{
		cont_match0 = 0;
		cont_periodo ++;
		flag_dead_time = 0;

		// lleno el vector con unos: Estados alto
		for(int i=0; i<8 ; i++)
			vector[i]=1;

		SetPINes( 0 , vector );   // Levanto los pulsos
	}


	// Protege que cont_periodo haga overflow cuando los motores no se usan
	if (cont_periodo == 10000)  // Poner #DEFINE
		cont_periodo = 0;

}



