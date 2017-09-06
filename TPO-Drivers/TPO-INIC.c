/*
===============================================================================
TPO-INIC
===============================================================================
*/
#include "../../../../Documents/Info_II/Info2_TPO/TPO-Headers/Infotronic.h"

/********************************************************************************
	\fn  void Inicializar ( void )
	\brief Inicializacion de Hardware.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void Inicializar ( void )
{
	InitPLL ( ) ;
	InitGPIOs ( ) ;
	Inicializar_Timer( ) ;

}

/********************************************************************************
	\fn  void InitGPIOs ( void )
	\brief Inicialización de GPIO.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void InitGPIOs ( void )
{
	// Salida Motor 0
	SetPINSEL( 0 , 16 , 0 ); 	// puerto = 0 , pin =  16 ; seleccion = GPIO
	SetDIR( 0 , 16 , 1 ); 		// puerto = 0 , pin =  16 ; Direccion = SALIDA

	// Salida Motor 1
	SetPINSEL( 0 , 17 , 0 ); 	// puerto = 0 , pin =  17 ; seleccion = GPIO
	SetDIR( 0 , 17 , 1 ); 		// puerto = 0 , pin =  17 ; Direccion = SALIDA

	// Salida Motor 2
	SetPINSEL( 0 , 18 , 0 ); 	// puerto = 0 , pin =  18 ; seleccion = GPIO
	SetDIR( 0 , 18 , 1 ); 		// puerto = 0 , pin =  18 ; Direccion = SALIDA

	// Salida Motor 3
	SetPINSEL( 0 , 19 , 0 ); 	// puerto = 0 , pin =  19 ; seleccion = GPIO
	SetDIR( 0 , 19 , 1 ); 		// puerto = 0 , pin =  19 ; Direccion = SALIDA

	// Salida Motor 4
	SetPINSEL( 0 , 20 , 0 ); 	// puerto = 0 , pin =  20 ; seleccion = GPIO
	SetDIR( 0 , 20 , 1 ); 		// puerto = 0 , pin =  20 ; Direccion = SALIDA

	// Salida Motor 5
	SetPINSEL( 0 , 21 , 0 ); 	// puerto = 0 , pin =  21 ; seleccion = GPIO
	SetDIR( 0 , 21 , 1 ); 		// puerto = 0 , pin =  21 ; Direccion = SALIDA

	// Salida Motor 6
	SetPINSEL( 0 , 22 , 0 ); 	// puerto = 0 , pin =  22 ; seleccion = GPIO
	SetDIR( 0 , 22 , 1 ); 		// puerto = 0 , pin =  22 ; Direccion = SALIDA

	// Salida Motor 7
	SetPINSEL( 0 , 23 , 0 ); 	// puerto = 0 , pin =  23 ; seleccion = GPIO
	SetDIR( 0 , 23 , 1 ); 		// puerto = 0 , pin =  23 ; Direccion = SALIDA

}

/********************************************************************************
	\fn  void Inicializar_Timer(void)
	\brief Inicialización de Interrupcion y funcionamiento del T/C 0.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void Inicializar_Timer(void)
{
	SetPINSEL( 1 , 26 , 3 );

	PCONP |= 1 << 1 ;
	PCLKSEL0 |= 0 << 2 ;

	T0MR0 = 0x000409;    //0x7fffff;		// Configuro el tiempo del match 0 (Número de cuenta)
	//T0MR1 = 0xffffff;//1E8480; //ffffff ;		// Configuro el tiempo del match 1

	//...............;	// Contador de pulsos falling edge en P1.26
	//...............;	// Pone en cero los bits de control del CAP0.0

	T0MCR  = ( ( 1 << MR0I ) | ( 1 << MR0R ) | ( 0 << MR0S ) ) ; // Mach0 salta la interrupción y resetea
	//T0MCR |= ( ( 1 << MR1I ) | ( 1 << MR1R ) | ( 0 << MR1S ) ) ;

	T0TCR &= ( ~( 1 << CE ) ) ;
	T0TCR |= (    1 << CR ) ;

	T0TCR &= ( ~( 1 << CR ) ) ;
	T0TCR |= (    1 << CE ) ;

	ISER0 |= ( 1 << NVIC_TIMER0 ) ;
}

/*void TIMER0_IRQHandler (void)
{
    if( T0IR & ( 1 << IRMR0 ) )	// Si interrumpio Match 0
	{
    	T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0
    	SetPIN( 0 , 22 , 1 ) ;			// puerto = 0 , pin =  22 ; estado = 1
	}

    if( T0IR & ( 1 << IRMR1 ) )	// Si interrumpio Match 1
    {
    	T0IR = ( 1 << IRMR1 ); 	// Borro flag del Match 1
    	SetPIN( 0 , 22 , 0 ) ;			// puerto = 0 , pin =  22 ; estado = 0
    }
}
*/
