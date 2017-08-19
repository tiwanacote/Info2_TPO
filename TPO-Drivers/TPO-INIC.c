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
	SetPINSEL( 0 , 22 , 0 ); 	// puerto = 0 , pin =  22 ; seleccion = GPIO
	SetDIR( 0 , 22 , 1 ); 		// puerto = 0 , pin =  22 ; Direccion = SALIDA
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

	T0MR0 = 0x838; //000409;    //0x7fffff;		// Configuro el tiempo del match 0 (Número de cuenta)
	T0MR1 = 0xffffff;//1E8480; //ffffff ;		// Configuro el tiempo del match 1

	//...............;	// Contador de pulsos falling edge en P1.26
	//...............;	// Pone en cero los bits de control del CAP0.0

	T0MCR  = ( ( 1 << MR0I ) | ( 0 << MR0R ) | ( 0 << MR0S ) ) ;
	T0MCR |= ( ( 1 << MR1I ) | ( 1 << MR1R ) | ( 0 << MR1S ) ) ;

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
