/*
===============================================================================
RegsLPC1769
===============================================================================
*/
#ifndef REGS_H_
#define REGS_H_

#define		__RW				volatile
typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	unsigned char 		bool;
typedef 	__RW uint32_t 		registro_t;  //!< defino un tipo 'registro'.


// REGISTROS ------------------------------------------------------------------------------------------------------------------------
#define		PINSEL			( ( registro_t  * ) 0x4002C000UL )		//!< Direccion de inicio de los registros PINSEL
#define		PINMODE			( ( registro_t  * ) 0x4002C040UL )		//!< Direccion de inicio de los registros de modo de los pines del GPIO
#define		GPIO			( ( registro_t  * ) 0x2009C000UL )		//!< Direccion de inicio de los registros de GPIOs

#define		TIMER0			( ( registro_t  * ) 0x40004000UL )

#define		T0IR			TIMER0[ 0 ]			/** IR - INTERRUPT REGISTER */
	#define		IRMR0		0
	#define		IRMR1		1
	#define		IRMR2		2
	#define		IRMR3		3
	#define		IRCR0		4
	#define		IRCR1		5
#define		T0TCR			TIMER0[ 1 ]			/** TCR - TIMER CONTROL REGISTER */
	#define		CE			0
	#define		CR			1
#define		T0TC			TIMER0[ 2 ]			/** TC - TIMER COUNTER REGISTER */
#define		T0PR			TIMER0[ 3 ]			/** PR - PRESCALE REGISTER */
#define		T0PC			TIMER0[ 4 ]			/** PC - PRESCALE COUNTER REGISTER */
#define		T0MCR			TIMER0[ 5 ]			/** MCR - MATCH CONTROL REGISTER */
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2
	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5
	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8
	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11
#define		T0MR0			TIMER0[ 6 ]			/** MR - MATCH CONTROL REGISTER */
#define		T0MR1			TIMER0[ 7 ]
#define		T0MR2			TIMER0[ 8 ]
#define		T0MR3			TIMER0[ 9 ]
#define		T0CCR			TIMER0[ 10 ]
#define		T0CR0			TIMER0[ 11 ]
#define		T0CR1			TIMER0[ 12 ]
//los siguientes dos registros NO estan contigüos. Por ende no se continúa con
//el offset
#define		T0EMR			( * ( ( registro_t  * ) 0x4000403CUL ) )
#define		T0CTCR			( * ( ( registro_t  * ) 0x40004070UL ) )/** CTCR - COUNT CONTROL REGISTER */
	#define		TCM			0
	#define		CIS			2


// NVIC ----------------------------------------------------------------------------------------------
#define		NVIC_TIMER0		1
// Nested Vectored Interrupt Controller (NVIC)
// 0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
#define		ISER		( ( registro_t  * ) 0xE000E100UL )
//!< 0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
#define		ICER		( ( registro_t  * ) 0xE000E180UL )

// Registros ISER:
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

// Registros ICER:
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

//  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
// 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	PCONP	(* ( ( registro_t  * ) 0x400FC0C4UL ))

// Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
// 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( ( registro_t  * ) 0x400FC1A8UL )
// Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

#endif
