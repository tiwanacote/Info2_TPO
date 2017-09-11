
#include <cinematica.h>

extern uint32_t cont_periodo;
extern uint8_t pos_motor[8];
extern uint8_t flag_dead_time;	// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición


void mover_motor(uint8_t motor , uint8_t pos_ini , uint8_t pos_final , uint8_t velocidad , uint8_t aceleracion )
{

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
		if (temp < pos_final)
			temp = pos_ini + velocidad * cont_periodo;
		else
			temp = pos_final;

		pos_motor[motor - 1] = temp;
	}
}
