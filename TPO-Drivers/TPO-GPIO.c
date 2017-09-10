/*
===============================================================================
TPO-GPIO
===============================================================================
*/
//#include "../../../../Documents/Info_II/Info2_TPO/TPO-Headers/Infotronic.h"
#include <Infotronic.h>

/********************************************************************************
	\fn  void void SetDIR( uint8_t puerto , uint8_t pin , uint8_t dir )
	\brief Establece si un determinado PIN de un determinado PUERTO (previamente
			configurado como GPIO) es entrada o salida.
	\author & date: Informatica II
 	\param [in] puerto: 	puerto con el que se va a trabajar
 	\param [in] pin:		pin a configurar sentido
 	\param [in] dir:		Direccion 0 = entrada - 1 = salida.
	\return void
*/
void SetDIR( uint8_t puerto , uint8_t pin , uint8_t dir )
{
	puerto = puerto * 8;

	GPIO[ puerto ] = GPIO[ puerto ] & ( ~ ( 1 << pin ) );
	GPIO[ puerto ] = GPIO[ puerto ] | ( dir << pin );
}

/********************************************************************************
	\fn  void SetPIN( uint8_t puerto , uint8_t pin , uint8_t estado )
	\brief Establece un ESTADO en un determinado PIN de un determinado PUERTO.
	\author & date: Informatica II
 	\param [in] puerto: puerto con el que se va a trabajar
 	\param [in] pin:	pin a activar estado
 	\param [in] estado:	valor a establecer en el PIN del PUERTO [0-1].
	\return void
*/
void SetPIN( uint8_t puerto , uint8_t pin , uint8_t estado )
{
	puerto = puerto * 8 + 5;

	GPIO[ puerto ] = GPIO[ puerto ] & ( ~ ( 1 << pin ) );
	GPIO[ puerto ] = GPIO[ puerto ] | ( estado << pin );
}

/********************************************************************************
	\fn  void void SetPINes( uint8_t puerto , uint8_t estado_motores[])
	\brief Función en la que entra un vector con los estados (0=bajo o 1=alto) para
		los pines de salida (En total son 8). La información es concatenada en una
		variable de 8bits, luego es acomoada en una variable de 32 bits (Del tamaño
		del puerto de salida) y finalmente se escriben los estados de una sola vez
	\author & date: 10/09/2017 - Maximiliano Bertotto
 	\param [in] puerto: 	puerto con el que se va a trabajar
 	\param [in] estado_motores[]: vector con los estados (0=bajo o 1=alto) para
		los pines de salida de los servos
	\return void
*/
void SetPINes( uint8_t puerto , uint8_t estado_motores[] )
{
	uint8_t temp1 = 0;
	uint32_t temp2 = 0;
	uint8_t i = 0;


	puerto = puerto * 8 + 5;

	// Convierto el vector "estado_motores[7]" en un entero de 8 bits
	for (i=0 ; i < 8 ; i++)  // Agregar #define CANT_MOTORES 8
	{
		temp1 = temp1 & ( ~ ( estado_motores[i] << i ) );
		temp1 = temp1 | ( estado_motores[i] << i );
	}

	temp2 = GPIO[ puerto ] & ( ~ ( 0xff << 16 ) );	// Aseguro 8 ceros a partir del bit 16: "Máscara"
	GPIO[ puerto ] = temp2 | ( temp1 << 16 );		// Escribo en el puerto temp2 con los pines del 16 al 24 modificados

}

/********************************************************************************
	\fn  uint8_t GetPIN( uint8_t puerto , uint8_t pin , uint8_t actividad )
	\brief Devuelve el ESTADO de un determinado PIN de un determinado PUERTO.
	\author & date: Informatica II
 	\param [in] puerto: puerto con el que se va a trabajar
 	\param [in] pin:	pin a consultar estado
	\param [in] actividad:	ALTO = 1, BAJO = 0
	\return:	estado del pin consultado (uint_8)
*/
uint8_t GetPIN( uint8_t puerto , uint8_t pin , uint8_t actividad )
{
	puerto = puerto * 8 + 5;

	return ( ( ( GPIO[ puerto ] >> pin ) & 1 ) == actividad ) ? 1 : 0;

}








