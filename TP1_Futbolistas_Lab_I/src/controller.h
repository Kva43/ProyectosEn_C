#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "controller.h"
#include "mantenimiento.h"
#include "posiciones.h"
#include "confederaciones.h"
#include "promedios.h"

int ImprimirMenu(Mantenimiento* pMantenimiento, Posiciones* pPosiciones);
int controller_calcularPromJug(void* pConferacion, void* pPromedio);
int controller_imprimirValores(void* pPromedios);
#endif /* CONTROLLER_H_ */
