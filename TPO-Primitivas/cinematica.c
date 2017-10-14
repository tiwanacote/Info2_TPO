
#include <cinematica.h>

#include <global_variables.h>
//extern uint32_t cont_periodo;
//extern uint32_t pos_motor[8];
//extern uint8_t flag_dead_time;	// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición
//extern uint8_t flag_stop[8];


bool mover_motor(uint8_t motor , uint32_t pos_ini , uint32_t pos_final , uint32_t velocidad , uint32_t aceleracion )
{

	/*
		\fn  bool mover_motor(uint8_t motor , uint8_t pos_ini , uint8_t pos_final , uint8_t velocidad , uint8_t aceleracion )
		\brief Realiza el cálculo de cinemático período a período que usará TIMER0_IRQHandler para controlar el PWM del motor en cuestión.
		\author & date: Maximiliano Bertotto - 15-09-2017
	 	\param uint8_t motor: Número de motor que se pretende mover
	 	\param uint8_t pos_int: Posición inicial del mismo expresado en número de cuenta del timer
	 	\param uint8_t pos_final: Posición final buscada del motor expresado en número de cuenta del timer
	 	\param uint8_t velocidad: En cuentas/período (Posee su equivalente en grados/segundo)
	 	\param uint8_t aceleracion: Aún no implementado
		\return: Bool - Si se está moviendo devuelve "True"
	*/


	uint32_t temp = 0 ;
	bool moving = 1;
	float delta_temp = 0;


	// Solamente incrementar posición cuando estoy arriba del 12% del rendimiento de ciclo de PWM del servo
	if (flag_dead_time == 1)
	{
		// Si la posción inicial es menor a la final
		if(pos_final > pos_ini)
		{
			// Si se genera alguna parada de emergencia o los sensores de corriente de los servos se disparan
			if (flag_stop[motor] != 1)
			{
				// Si aún no se llegó a la posición final
				if ( pos_motor[motor - 1] < pos_final)
				{

					temp = pos_ini + velocidad * cont_periodo;

					// Si en la siguiente cuenta me paso entonces adelanto ahora. Busca que el error sea lo menor posible
					delta_temp = (pos_ini + velocidad * (cont_periodo + 1)) - temp;
					if ( ((float)(pos_ini + velocidad * (cont_periodo + 1))) > ((float)pos_final + (delta_temp/2)))
					{
						temp = pos_final;
						moving = 0;
					}

					pos_motor[motor - 1] = temp; // Escribo en el vector pos_motor[] que usara TIMER0_IRQHandler
				}
				// Si se llega
				else
					moving = 0;
			}

			// flag_stop[motor] == 0.  pos_motor[motor - 1] se mantendrá todo el tiempo en su última posición
			else
				moving = 0;

		}

		// IDEM anterior pero si la posición inicial es mayor a la final
		else
		{

			// Si se genera alguna parada de emergencia o los sensores de corriente de los servos se disparan
			if (flag_stop[motor] != 1)
			{

				// Si aún no se llegó a la posición final
				if ( pos_motor[motor - 1] >= pos_final)
				{
					temp = pos_ini - velocidad * cont_periodo;

					// Si en la siguiente cuenta me paso entonces adelanto ahora
					delta_temp = temp - (pos_ini - velocidad * (cont_periodo + 1));
					if ( (float)(pos_ini - velocidad * (cont_periodo + 1)) < ((float)pos_final - (delta_temp/2)) )
					{
						temp = pos_final;
						moving = 0;
					}

					pos_motor[motor - 1] = temp; // Escribo en el vector pos_motor[] que usara TIMER0_IRQHandler
				}
				// Si se llega
				else
					moving = 0;
			}
			// flag_stop[motor] == 0.  pos_motor[motor - 1] se mantendrá todo el tiempo en su última posición
			else
				moving = 0;
		}

	}



	return moving;
}


/*
void mover_motores (uint8_t pos_iniciales[], uint8_t pos_finales[] , uint8_t velocidades[], uint8_t aceleraciones )
{
	cont_periodo =0;
	uint8_t suma = 0;

	for (int i = 0; i < 8 ; i++)
		moving += mover_motor(i , pos_iniciales[i] , pos_finales[i] , velocidades[i] , aceleraciones[i] );

}
*/
