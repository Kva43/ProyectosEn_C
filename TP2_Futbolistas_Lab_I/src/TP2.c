#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "jugador.h"
#include "confederacion.h"
#include "validaciones.h"
#include "string.h"
#define CANT_JUGADORES 30
#define CANT_CONFEDERACIONES 10
#define CHAR_LEN 50

void mensajeError(void);
int menu(void);

 int main(void) {
 	setbuf(stdout, NULL);
 	int opcion;
 	eJugador arrayJugadores[CANT_JUGADORES];
 	eConfederacion arrayConfederaciones[CANT_CONFEDERACIONES];
 	int flag = 0;

 	//inicializo en 0(true) los campos "isEmpty" de todas las posiciones de mi array de estructuras
 	initArrayJug(arrayJugadores, CANT_JUGADORES);
 	initArrayConf(arrayConfederaciones, CANT_CONFEDERACIONES);
 	harcodearJugadores(arrayJugadores, arrayConfederaciones);
 	do {
 		switch(opcion = menu()) {
 		case 1:
 			if(controller_Alta(arrayJugadores, CANT_JUGADORES, arrayConfederaciones,CHAR_LEN) == 0)
 			{
 				controller_listar(arrayJugadores, CANT_JUGADORES, CHAR_LEN, arrayConfederaciones);
 				flag = -1;
 			}
 			else
 				mensajeError();
 			break;
 		case 2:
 			if(flag == -1)
 			{
 				controller_listar(arrayJugadores, CANT_JUGADORES, CHAR_LEN, arrayConfederaciones); //si no hay jugadores en el ARRAY no mostrar nada
 				controller_darBaja(arrayJugadores, CANT_JUGADORES);
 			}
 			else
 				mensajeError();
 			break;
 		case 3:
 			if(flag == -1)
 				controller_modificarJug(arrayJugadores, CANT_JUGADORES, CHAR_LEN, arrayConfederaciones);
 			else
 				mensajeError();
 			break;
 		case 4:
 			if(flag == -1)
 			{
 				controller_informes(arrayJugadores, CANT_JUGADORES, arrayConfederaciones);
 			}
 			else
 				mensajeError();
 			break;
 		case 5:
 			printf("\nCerrando sesión");
 			break;
 		}
 	} while(opcion != 5);
 	return 0;
 }

 int menu(void) {
 	int opcion;
 	printf("===========================\n"
 	"|     Menu Principal      |\n");
 	utn_getNumero(&opcion,  "|  1   Alta               |\n"
 							"|  2   Baja               |\n"
 							"|  3   Modificacion       |\n"
 							"|  4   Informes           |\n"
 							"|  5   Salir              |\n"
 							"===========================\n","\nERROR. Ingrese un numero del 1 al 5",1,5,2);
 	return opcion;
 }

 void mensajeError(void)
 {
 	printf("\nIngrese jugadores al sistema antes de ingresar a esta opcion\n");
 }
