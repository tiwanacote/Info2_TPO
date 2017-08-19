																							/*
_______________________________________________________________________________________________

0) ACONDICIONAMIENTO de ENTORNO:
_______________________________________________________________________________________________

Usamos "volatile": De este modo garantizamos que las variables estén en RAM y
siempre se utilicen desde ahí 																*/


#define 	__RW				volatile
#define 	__W					volatile
#define 	__R					volatile const

typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;													/*


_______________________________________________________________________________________________

1) CONFIGURACIÓN de ACCESO a HARDWARE
_______________________________________________________________________________________________

*****************************************************************************
1.1) PINSEL
*****************************************************************************

Se selecciona la funcionaldad para cada PIN. La misma está compuesta por 2 bits

00 - GPIO      (Puede ser entrada o salida)
01 - Función 1 (Distinta a GPIO - Cambia con el PIN)
10 - Función 2 (Distinta a GPIO - Cambia con el PIN)
11 - Función 3 (Distinta a GPIO - Cambia con el PIN)

PINSEL0 ~ PINSEL9:
Cada uno está compuesto por 32 bits, con lo cual si uso 2 bits para
setear la funcionalidad de cada PIN, entonces por cada PINSELi configuro
15 solo PINs. A modo de ejemplo, el PORT0 es configurado con
PINSEL0 y PINSEL1 dado que el mismo tiene 30 PINS												*/


#define		PINSEL		( ( _RW uint32_t  * ) 0x4002C000UL )


#define		PINSEL0		PINSEL[0]	// PINSEL0--->P0[15:0] 	(0x4002C000)
#define		PINSEL1		PINSEL[1]	// PINSEL1--->P0[31:16]	(0x4002C004)
#define		PINSEL2		PINSEL[2]	// PINSEL2--->P1[15:0] 	(0x4002C008)
#define		PINSEL3		PINSEL[3]	// PINSEL3--->P1[31:16]	(0x4002C00C)
#define		PINSEL4		PINSEL[4]	// PINSEL4--->P2[15:0] 	(0x4002C010)
#define		PINSEL5		PINSEL[5]	// PINSEL5--->P2[31:16]   NOT USED
#define		PINSEL6		PINSEL[6]	// PINSEL6--->P3[15:0] 	  NOT USED
#define		PINSEL7		PINSEL[7]	// PINSEL7--->P3[31:16] (0x4002C01C)
#define		PINSEL8		PINSEL[8]	// PINSEL8--->P4[15:0]    NOT USED
#define		PINSEL9		PINSEL[9]	// PINSEL9--->P4[31:16]	(0x4002C024)

																								/*
Estados de PINSEL:
																								*/
#define		PINSEL_GPIO			0 // 00
#define		PINSEL_FUNC1		1 // 01
#define		PINSEL_FUNC2		2 // 10
#define		PINSEL_FUNC3		3 // 11


																								/*
*****************************************************************************
1.2) PINMODE
*****************************************************************************

Tiene dos bits. Se configura igual que el PINSEL. Los estados pueden ser:

00 - Pull Up resistor enable (reset value)
01 - Repeated mode enable (Si la señal es bajo se activa Pull-Down y viseversa)
10 - Ni Pull Up ni Pull DOwn (Se pone a nivel hardware)
11 - Pull Down resistor enable

PINMODE0 ~ PINMODE9
																								 */

#define	PINMODE		( ( __RW uint32_t  * ) 0x4002C040UL )

#define		PINMODE0	PINMODE[0]		//!< 0x4002C040
#define		PINMODE1	PINMODE[1]		//!< 0x4002C044
#define		PINMODE2	PINMODE[2]		//!< 0x4002C048
#define		PINMODE3	PINMODE[3]		//!< 0x4002C04C
#define		PINMODE4	PINMODE[4]		//!< 0x4002C050
#define		PINMODE5	PINMODE[5]		//!< 0x4002C054
#define		PINMODE6	PINMODE[6]		//!< 0x4002C058
#define		PINMODE7	PINMODE[7]		//!< 0x4002C05C
#define		PINMODE9	PINMODE[9]		//!< 0x4002C064
																								 /*
Estados de PINMODE:
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 */
#define		PINMODE_PULLUP 		0		// 00 - Pull Up resistor enable (reset value)
#define		PINMODE_REPEAT 		1		// 01 - Repeated mode enable
#define		PINMODE_NONE 		2		// 10 - Ni Pull Up ni Pull DOwn
#define		PINMODE_PULLDOWN 	3		// 11 - Pull Down resistor enable


																								 /*
*****************************************************************************
1.3) PINMODE_OD
*****************************************************************************

PREGUNTARRR!!!! Confuso

Para cuando configuramos el puerto SOLO como SALIDA
Tiene 1 bit. Direccion de inicio de los registros de control del modo OPEN DRAIN

El modo de open drain hace que el pin se vaya a estado bajo si está configurado
como salida y el valor del dato es 0

0 - Not open drain
1 - Open drain

PINMODE_OD0 ~ PINMODE_OD4: Se configura uno a uno con los pines de cada puerto.
																								*/

#define		PINMODE_OD		( ( __RW uint32_t  * ) 0x4002C068UL )

#define		PINMODE_OD0		PINMODE_OD[0]
#define		PINMODE_OD1		PINMODE_OD[1]
#define		PINMODE_OD2		PINMODE_OD[2]
#define		PINMODE_OD3		PINMODE_OD[3]
#define		PINMODE_OD4		PINMODE_OD[4]


																								/*
*****************************************************************************
1.4) GPIO Resister
*****************************************************************************

Esta estructurado de la siguiente manera:


	*************************
	*		FIODIR			*	0x2009C000
	*************************
	*		RESERVED		*	0x2009C004
	*************************
	*		RESERVED		*	0x2009C008
	*************************
	*		RESERVED		*	0x2009C00C
	*************************
	*		FIOMASK			*	0x2009C010
	*************************
	*		FIOPIN			*	0x2009C014
	*************************
	*		FIOSET			*	0x2009C018
	*************************
	*		FIOCLR			*	0x2009C01C
	*************************
	*						*

Todos los registros se completan con 1 BIT por PIN

FIODIR: Define si es entrada o salida
0 - Entrada
1 - Salida

FIOMASK: Es una mascara de proteccion de registro que se usa con FIOPIN, FIOSET y FIOCLR. Como los
registros pueden ser escritos, leidos o borrados, si la misma esta aplicada, solo se podran escribir,
leer o borrar los que esten "permitidos" en 0 con FIOMASK
0 - Permitido escribir, leer o borrar
1 - NO permitido


FIOPIN, FIOSET, FIOCLR no son excluyentes entre sí, dejemos libertad al programador que de que utilice
los que le resulten más cómodos para su tarea.

FIOPIN(?): Lectura o escritura del registro del puerto. Este registro siempre se puede leer
independientemente si esta seteado como entrada, salida u otra funcion que se haya otorgado.
El valor mostrado en este registro es REG & (~ (FIOMASK)). Es decir, solo se muestra el estado
de los pines en donde FIOMASK es 0. En los que FIOMASK es 1 coloca ceros independiente al valor
que realmente tenia.

FIOSET(?): Registro de salida de PINs. Lo que escribo es lo que sale. Solamente los PINs en 0 en FIOMASK
seran permtidos escribir

FIOCLR: Si se ponen "unos" borra todos los PINs de salida habilitados con "0" en FIOMASK			*/


#define	GPIOs			( ( __RW uint32_t  * ) 0x2009C000UL )

#define		FIO0DIR		GPIOs[0]	//!< 0x2009C000
#define		FIO1DIR		GPIOs[8]	//!< 0x2009C020
#define		FIO2DIR		GPIOs[16]	//!< 0x2009C040
#define		FIO3DIR		GPIOs[24]	//!< 0x2009C060
#define		FIO4DIR		GPIOs[32]	//!< 0x2009C080

#define		FIO0MASK	GPIOs[4]	//!< 0x2009C010
#define		FIO1MASK	GPIOs[12]	//!< 0x2009C030
#define		FIO2MASK	GPIOs[20]	//!< 0x2009C050
#define		FIO3MASK	GPIOs[28]	//!< 0x2009C070
#define		FIO4MASK	GPIOs[36]	//!< 0x2009C090

#define		FIO0PIN		GPIOs[5]	//!< 0x2009C014
#define		FIO1PIN		GPIOs[13]	//!< 0x2009C034
#define		FIO2PIN		GPIOs[21]	//!< 0x2009C054
#define		FIO3PIN		GPIOs[29]	//!< 0x2009C074
#define		FIO4PIN		GPIOs[37]	//!< 0x2009C094

#define		FIO0SET		GPIOs[6]	//!< 0x2009C018
#define		FIO1SET		GPIOs[14]	//!< 0x2009C038
#define		FIO2SET		GPIOs[22]	//!< 0x2009C058
#define		FIO3SET		GPIOs[30]	//!< 0x2009C078
#define		FIO4SET		GPIOs[38]	//!< 0x2009C098

#define		FIO0CLR		GPIOs[7]	//!< 0x2009C01C
#define		FIO1CLR		GPIOs[15]	//!< 0x2009C03C
#define		FIO2CLR		GPIOs[23]	//!< 0x2009C05C
#define		FIO3CLR		GPIOs[31]	//!< 0x2009C07C
#define		FIO4CLR		GPIOs[39]	//!< 0x2009C09C

																								/*
Dirección en FIODIR
																								*/
#define 	ENTRADA			0
#define 	SALIDA			1


																								/*
_______________________________________________________________________________________________

2) CONFIGURACIÓN de INTERRUPCIONES - REGISTROS NVIC
_______________________________________________________________________________________________

Controlador de Interrupciones:
El NVIC (Nested Vectorized Interrupt Controller) es un controlador de interrupciones que está
en el CORE, es parte de lo que los fabricantes compran a ARM al licenciar el Cortex M3.
El NVIC puede trabajar con interrupciones anidadas y con interrupciones encadenadas. Lleva la
cuenta de las que están pendientes. Además puede desplazar de la ejecución a una interrupción
para dar paso a otra más prioritaria.

En el NVIC hay 5 grupos de registros que controlan su funcionamiento:

ISER e ICER 0 y 1: sirven para habilitar y deshabilitar cada fuente de interrupción. Hay 32 por cada ISER
ISPR e ICPR 0 y 1: sirven para setear y resetear los flags de interrupciones pendientes. Hay 32 por cada ISER
IABR 0 y 1: sirven para indicar las interrupciones activas.
IPR 0 al 8: sirven para configurar el nivel de prioridad de cada interrupción.
STIR: permite generar interrupciones de software. Para cualquier vector o fuente externa

Las ISR (Interrupt Service Rutine) son las rutinas a donde va a la ejecución del programa
cuando el CPU atiende una interrupción.

WEAK significa que esa función será pisada por otra con el mismo nombre.
Si no hay otra con el mismo nombre, entonces es válida.
Se usa esto para definir funciones default

ALIAS significa que el nombre de la función definida refiere a otra función.
Se usa para hacer que muchas funciones se refieran a un misma función. Es una función default
que debe estar definida si o si por seguridad.El modificador ALIAS está definido para que
incluya también al atributo weak, por lo tanto las funciones ISR (Rutinas de servicio de
interrupciones) están declaradas por default como  ALIAS lo que implica que todas se refieren
a otra común y que son válidas siempre y cuando no se defina otra con el mismo nombre que no
sea WEAK

El LPC1769 tiene 4 fuentes de interrupción externa. Estas fuentes se identifican de 0 a 3.
																								*/


#define		ISER 		( ( __RW uint32_t  * ) 0xE000E100UL )
#define 	ISER0		ISER[0]
#define 	ISER1		ISER[1]

#define		ICER 		( ( __RW uint32_t  * ) 0xE000E180UL )
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

#define		ISPR 		( ( __RW uint32_t  * ) 0xE000E200UL )
#define		ISPR0		ISPR[0]
#define		ISPR1		ISPR[1]

#define		ICPR 		( ( __RW uint32_t  * ) 0xE000E280UL )
#define		ICPR0		ICPR[0]
#define		ICPR1		ICPR[1]

#define		IABR 		( ( __RW uint32_t  * ) 0xE000E300UL )
#define		IABR0		IABR[0]
#define		IABR1		IABR[1]

/* Nunca escuchamos de estos nombres
#define		IPR 		( ( __RW uint32_t  * ) 0xE000E400UL )
#define		IPR0		IPR[0]
#define		IPR1		IPR[1]
#define		IPR2		IPR[2]
#define		IPR3		IPR[3]
#define		IPR4		IPR[4]
#define		IPR5		IPR[5]
#define		IPR6		IPR[6]
#define		IPR7		IPR[7]
#define		IPR8		IPR[8]

#define		STIR_ 		( ( __RW uint32_t  * ) 0xE000EF00UL )
#define		STIR 		STIR_[0]
*/


																									/*
*****************************************************************************
2.1) Interrupciones Externas
*****************************************************************************

EXTINT: Es un FLAG register de 32 bit que solo se usan los primeros 4 bits.
Es una buena practica limpiar el flag cada vez que se atiende la interrupcion
de la siguiente manera:
"This bit is cleared by writing a one to it"
EXTINT = EXTINT | (0x01<<EINT0);			//!< Limpia Flag interrupcion

EXTMODE: Selectionamos si la interrupcion se da por FLANCO o NIVEL de tension.
Es un registro de 32 bits de los cuales solo se usan los primeros 4.
0 - Level sensitive
1 - Edge sensitive


EXTPOLAR: Se define si la interrupción es generada en el flanco ascendente o descendente, si
previamente se selecciono EXTMODE = 1, caso contrario, se selecciona si es low-active o high-active
0 - low-active o falling edge
1 - high-active o rising edge


																									*/
#define		EXTINT_ 	( ( __RW uint32_t  * ) 0x400FC140UL )
#define		EXTINT		EXTINT_[0]

#define		EXTMODE_ 	( ( __RW uint32_t  * ) 0x400FC148UL )
#define		EXTMODE		EXTMODE_[0]

#define		EXTPOLAR_ 	( ( __RW uint32_t  * ) 0x400FC14CUL )
#define 	EXTPOLAR	EXTPOLAR_[0]

/* es para correr lugares. No está muy bueno
#define EINT0  0
#define EINT1  1
#define EINT2  2
#define EINT3  3
*/

//#define	    PORT0 		( ( _RW uint32_t  * ) 0x2009C000UL )
//#define	    PORT1		PORT0+8
//#define	    PORT2		PORT0+16
//#define	    PORT3		PORT0+24
//#define	    PORT4		PORT0+32


																									/*
_______________________________________________________________________________________________

3) CONFIGURACIÓN de SYSTICK
_______________________________________________________________________________________________

El Systic no depende del NVIC

STCTRL: Es un registro de 32 bits que solo se modifican los primeros 3 bits y el nro 16. Este registro
SIEMPRE se inicializa con un 7 generalmente.

	ENABLE: Habilita o no el Systick
	0 - Deshabilita el Systick
	1 - Habilita
	TICKINT: Habilita la interrupción cuando llega a cero. Esto llama a la función de interrupción.
	0 - No disparo interrupciones
	1 - Llamo a la interrupcion
	CLKSOURCE: Defino fuente de clock
	0 - Clock externo del P3.26 (Configurar GPIO)
	1 - Clock interno que puede ser el CCLK o RC
	COUNTERFLG: No se toca en la inicilizacion, solo se lee en la funcion de interrupcion para avisar.

STRLOAD: Es el valor desde el cual se comienza a decrementar. (CCLK/100)-1 o para 10mseg se
usa (STCLIB/n)-1   con n=1 y CCLK=100mhz

STRCURR: Devuelve la cuenta actual del contador

STCALIB: Es un valor pre-seteado para establecer el Systick con interrupciones cada 10mseg
(Si el Clock=100Mhz)

   	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define	 SysTick 		( (__RW uint32_t * )  0xE000E010UL  )

#define  STCTRL			SysTick[0]
#define  STRELOAD		SysTick[1]
#define  STCURR			SysTick[2]
#define  STCALIB		SysTick[3]

#define TMR_TICK		1000		// Defino Clock
#define CCLK			3000000		// Defino Clock

																									/*
_______________________________________________________________________________________________

4) CONFIGURACIÓN de TIMERS
_______________________________________________________________________________________________



*****************************************************************************
4.1) Timer 0
*****************************************************************************

TxIR: Es el registro de interrupciones. Nos indica si fue por el Mach0, Mach1, Mach2, Mach3
CaptureChannel0 o CaptureChannel1. Así es como se usa...

void TIMER0_IRQHandler (void)
{
	if((T0IR & MR0))  // MR0 es un define = 0x01. Verifico que la interrupcion fue por un MACH0
	{
		// Si interrumpio match 0
		T0IR |= MR0; 		//!< Borro flag del Match 0. Suponemos que se escribe para avisar que se atendio la interrupcion
		flagTimer++;		//!< Incrmeento flag
	}

TxTCR:


																									*/
#define		TIMER0 		( ( __RW uint32_t  * ) 0x40004000UL )

#define		T0IR		TIMER0[0]
#define		T0TCR		TIMER0[1]
#define		T0TC		TIMER0[2]
#define		T0PR		TIMER0[3]	// NO sabemos que es. No aparece en el documento de la catedra
#define		T0PC		TIMER0[4]	// NO sabemos que es. No aparece en el documento de la catedra
#define		T0MCR		TIMER0[5]
#define		T0MR0		TIMER0[6]
#define		T0MR1		TIMER0[7]
#define		T0MR2		TIMER0[8]
#define		T0MR3		TIMER0[9]
#define		T0CCR		TIMER0[10]
#define		T0CR0		TIMER0[11]	// NO sabemos que es. No aparece en el documento de la catedra
#define		T0CR1		TIMER0[12]	// NO sabemos que es. No aparece en el documento de la catedra

#define		_T0EMR	( ( __RW uint32_t  * ) 0x4000403CUL )
#define		T0EMR	_T0EMR[0]

#define		_T0CTCR	( ( __RW uint32_t  * ) 0x40004070UL )
#define		T0CTCR	_T0CTCR[0]

																									/*
*****************************************************************************
4.2) Timer 1
*****************************************************************************
																									*/

#define		TIMER1 		( ( __RW uint32_t  * ) 0x40008000UL )
#define		T1IR		TIMER1[0]
#define		T1TCR		TIMER1[1]
#define		T1TC		TIMER1[2]
#define		T1PR		TIMER1[3]
#define		T1PC		TIMER1[4]
#define		T1MCR		TIMER1[5]
#define		T1MR0		TIMER1[6]
#define		T1MR1		TIMER1[7]
#define		T1MR2		TIMER1[8]
#define		T1MR3		TIMER1[9]
#define		T1CCR		TIMER1[10]
#define		T1CR0		TIMER1[11]
#define		T1CR1		TIMER1[12]

#define		_T1EMR	( ( __RW uint32_t  * ) 0x4000803CUL )
#define		T1EMR	_T1EMR[0]

#define		_T1CTCR	( ( __RW uint32_t  * ) 0x40008070UL )
#define		T1CTCR	_T1CTCR[0]

																								/*
*****************************************************************************
4.3) Timer 2
*****************************************************************************
																								*/

#define		TIMER2 		( ( __RW uint32_t  * ) 0x40090000UL )
#define		T2IR		TIMER2[0]
#define		T2TCR		TIMER2[1]
#define		T2TC		TIMER2[2]
#define		T2PR		TIMER2[3]
#define		T2PC		TIMER2[4]
#define		T2MCR		TIMER2[5]
#define		T2MR0		TIMER2[6]
#define		T2MR1		TIMER2[7]
#define		T2MR2		TIMER2[8]
#define		T2MR3		TIMER2[9]
#define		T2CCR		TIMER2[10]
#define		T2CR0		TIMER2[11]
#define		T2CR1		TIMER2[12]

#define		_T2EMR	( ( __RW uint32_t  * ) 0x4009003CUL )
#define		T2EMR	_T2EMR[0]

#define		_T2CTCR	( ( __RW uint32_t  * ) 0x40090070UL )
#define		T2CTCR	_T2CTCR[0]


																								/*
*****************************************************************************
4.4) Timer 3
*****************************************************************************
																								*/

#define		TIMER3 		( ( __RW uint32_t  * ) 0x40094000UL )
#define		T3IR		TIMER3[0]
#define		T3TCR		TIMER3[1]
#define		T3TC		TIMER3[2]
#define		T3PR		TIMER3[3]
#define		T3PC		TIMER3[4]
#define		T3MCR		TIMER3[5]
#define		T3MR0		TIMER3[6]
#define		T3MR1		TIMER3[7]
#define		T3MR2		TIMER3[8]
#define		T3MR3		TIMER3[9]
#define		T3CCR		TIMER3[10]
#define		T3CR0		TIMER3[11]
#define		T3CR1		TIMER3[12]

#define		_T3EMR	( ( __RW uint32_t  * ) 0x4009403CUL )
#define		T3EMR	_T3EMR[0]

#define		_T3CTCR	( ( __RW uint32_t  * ) 0x40094070UL )
#define		T3CTCR	_T3CTCR[0]



																							 /*
_______________________________________________________________________________________________

5) CONFIGURCIÓN de PLL - "Caja negra"
_______________________________________________________________________________________________
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 */

//////////////Registros del CLOCK y de sistema/////////////////
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
//0x400FC104UL: Registro de configuracion del clock:
#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
//0x400FC10CUL: Registro de seleccion del clock:
#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
//0x400FC1C8UL: Clock Output Config register:
#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
//0x400FC000UL: Flash access configuration:
#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

/////////////////Registros de los PLL///////////////////////////
//0x400FC080UL: Registro de control del PLL0:
#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
//0x400FC084UL: Registro de configuracion del PLL0:
#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
//0x400FC088UL: Registro de estado del PLL0:
#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
//0x400FC08CUL: Registro de control del PLL0:
#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
//0x400FC0A0UL: Registro de control del PLL1:
#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
//0x400FC0A8UL: Registro de estado del PLL1:
#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
//0x400FC0ACUL: Registro de control del PLL1:
#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

//Registro de status y configuracion del sistema:
#define		SCS			DIR_SCS[0]
#define 	FLASHCFG	DIR_FLASHCFG[0]

//Registros de control del CLOCK:
#define		CCLKCFG		DIR_CCLKCFG[0]
#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
#define		CLKOUTCFG	DIR_CLKOUTCFG[0]

//PLL0:
#define		PLL0CON		DIR_PLL0CON[0]
#define		PLL0CFG		DIR_PLL0CFG[0]
#define		PLL0STAT	DIR_PLL0STAT[0]
#define		PLL0FEED	DIR_PLL0FEED[0]

//PLL1:
#define		PLL1CON		DIR_PLL1CON[0]
#define		PLL1CFG		DIR_PLL1CFG[0]
#define		PLL1STAT	DIR_PLL1STAT[0]
#define		PLL1FEED	DIR_PLL1FEED[0]



																									/*
_______________________________________________________________________________________________

X) PCLKSEL0 - Peripheral Clock Selection registers
_______________________________________________________________________________________________

PCLKSEL0: Se selecciona un divisor de clock para cada periferico (Timers, I2C, UART). Son 26 bits
y se llenan de a dos bits por cada periferico segun lo siguiente. Previamente, en el PLL se
define CCLK

00 - CCLK/4
01 - CCLK/1
10 - CCLK/2
11 - CCLK/8
																									*/
#define		PCLKSEL		( ( registro  * ) 0x400FC1A8UL )

#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

																									/*
_______________________________________________________________________________________________

X) PCONP - Power Control for Peripherals register
_______________________________________________________________________________________________


PCONP: Alimenta o apaga cada periferico. Se coloca un 1 o 0 para cada periferico (Se usa corrimiento)
1 - Encendido
0 - Apagado 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   */

#define 	PCONP	(* ( ( registro  * ) 0x400FC0C4UL ))





// Constantes
#define CLOCK_SETUP_Value 	    1
#define SCS_Value				0x00000020
#define CLKSRCSEL_Value         0x00000001
#define PLL0_SETUP_Value        1
#define PLL0CFG_Value           0x00050063
#define PLL1_SETUP_Value        1
#define PLL1CFG_Value           0x00000023
#define CCLKCFG_Value           0x00000003
#define USBCLKCFG_Value         0x00000000
#define PCLKSEL0_Value          0x00000000
#define PCLKSEL1_Value          0x00000000
#define PCONP_Value             0x042887DE
#define CLKOUTCFG_Value         0x00000000
#define FLASHCFG_Value			0x00004000
