#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "confederacion.h"
#include "jugador.h"

#endif /* CONTROLLER_H_ */

int controller_Alta(eJugador* arrayJug, int cant, eConfederacion* arrayConf, int char_len);
int controller_listar(eJugador* arrayJug, int cant, int char_len, eConfederacion* arrayConfs);

int controller_darBaja(eJugador* arrayJug, int cant);
int controller_modificarJug(eJugador* arrayJug, int cant, int char_len, eConfederacion* arrayConf);



int harcodearJugadores(eJugador* arrayJug,eConfederacion* arrayConf);


int controller_informes(eJugador* arrayJugadores, int cantJug, eConfederacion* arrayConf);
int ordenarNombres(eJugador* arrayJug, int cant, int order, eConfederacion* arrayConf);
