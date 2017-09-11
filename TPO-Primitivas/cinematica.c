
#include <cinematica.h>

extern uint32_t cont_periodo;
extern uint8_t pos_motor[8];
extern uint8_t flag_dead_time;	// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición


void mover_motor(uint8_t motor , uint8_t pos_ini , uint8_t pos_final , uint8_t velocidad , uint8_t aceleracion )
{


	// LO DE TEMP=POS_INI DEBE DE SER RESUELTO POR FUERA CON UNA VARIABLE GLOBAL DESDE LA FUNCION
	// "MOVER_MOTORES", A LA CUAL SE LE ENTREGARÍA UN VECTOR DE POSICIONES Y EJECUTARÍA "MOVER_MOTOR"
	// PARA TODOS LOS MOTORES!!!!!!!!!!!!!!!!!!!!!!
	// TAMBIEN PUEDE SER QUE ESTA FUNCION DEVUELVA UN "1" SI SE ESTA MOVIENDO Y UN "0" SI TERMINO


	static uint8_t temp ;//pos_ini;

	static uint8_t primera_vez = 0;
	// Poner afuera. La primera vez que llega una posición nueva o instrucción (Abrir mano), el cont_periodo
	// se pone en cero
	//
	if (primera_vez == 0)
		{
		temp = pos_ini;
		primera_vez = 1;
		}


	// Solamente incrementar posición
	if (flag_dead_time == 1)
	{
		// Si la posción inicial es menor a la final
		if(pos_final-pos_ini < 0)
		{
			// Si no se llega a la posición final
			if (temp < pos_final)
				temp = pos_ini + velocidad * cont_periodo;
			// Si se llega
			else
				temp = pos_final;
		}
		// Si la posición inicial es mayor a la final
		else
		{

			// Si no se llega a la posición final
			if (temp > pos_final)
				temp = pos_ini - velocidad * cont_periodo;
				// Si se llega
			else
				temp = pos_final;
		}
		// Se carga la posicion transitoria en el vector de posiciones
		pos_motor[motor - 1] = temp;
	}
}
