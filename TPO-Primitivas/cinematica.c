
#include <cinematica.h>

extern uint32_t cont_periodo;
extern uint8_t pos_motor[8];
extern uint8_t flag_dead_time;	// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición


bool mover_motor(uint8_t motor , uint8_t pos_ini , uint8_t pos_final , uint8_t velocidad , uint8_t aceleracion )
{


/* Devuelve un bool moving si uando sale aún no se alcanzó la posición final
 *
 *
 */

	//static uint8_t temp ;//pos_ini;
	uint8_t temp = 0 ; //MAXI
	bool moving = 1; // MAXI
	float delta_temp = 0; //MAXI

	//static uint8_t primera_vez = 0;
	// Poner afuera. La primera vez que llega una posición nueva o instrucción (Abrir mano), el cont_periodo
	// se pone en cero
	//

	/* MAXI
	if (primera_vez == 0)
		{
		temp = pos_ini;
		primera_vez = 1;
		}*/


	// Solamente incrementar posición cuando estoy arriba del 12% del rendimiento de ciclo (O sea, no hago nada en el)
	if (flag_dead_time == 1)
	{
		// Si la posción inicial es menor a la final
		if(pos_final-pos_ini > 0)
		{
			// Si no se llega a la posición final
			//if (temp < pos_final)// MAXI
			if ( pos_motor[motor - 1] < pos_final)
				temp = pos_ini + velocidad * cont_periodo;

				// Si en la siguiente cuenta me paso entonces adelanto ahora
			/* AQUÏ HAY UN ERROR
				delta_temp = (pos_ini + velocidad * (cont_periodo + 1)) - temp;
				if ( (pos_ini + velocidad * (cont_periodo + 1)) > ((float)pos_final + (delta_temp/2)))
				{
					temp = pos_final;
					moving = 0;
				}*/
			// Si se llega
			else
			{
				temp = pos_final;
				moving = 0;
			}
		}
		// Si la posición inicial es mayor a la final
		else
		{

			// Si no se llega a la posición final
			// if (temp > pos_final) MAXI
			if ( pos_motor[motor - 1] > pos_final)
				temp = pos_ini - velocidad * cont_periodo;

				// Si en la siguiente cuenta me paso entonces adelanto ahora
				delta_temp = (pos_ini + velocidad * (cont_periodo + 1)) - temp;
				if ( (pos_ini - velocidad * (cont_periodo + 1)) < ((float)pos_final - (delta_temp/2)) )
				{
					temp = pos_final;
					moving = 0;
				}

				// Si se llega
			else
			{
				temp = pos_final;
				moving = 0;
			}
		}
		// Se carga la posicion transitoria en el vector de posiciones
		pos_motor[motor - 1] = temp;
	}

	return moving;
}

/*
void mover_motores (uint8_t pos_iniciales[], uint8_t pos_finales[] , uint8_t velocidades[], uint8_t aceleraciones )
{
	uint8_t moving[8] = {0,0,0,0,0,0,0,0};
	uint8_t suma = 0;

	for (int i = 0; i < 8 ; i++)
		moving[i] = mover_motor(i , pos_iniciales[i] , pos_finales[i] , velocidades[i] , aceleraciones[i] );

	for (int i = 0; i < 8 ; i++)
		suma = moving[i];

	//is_moving = suma;
}
*/
