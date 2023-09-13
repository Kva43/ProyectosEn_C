#ifndef MANTENIMIENTO_H_
#define MANTENIMIENTO_H_

#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "utn.h"

typedef struct {
	int hospedaje;
	int comida;
	int transporte;
} Mantenimiento;

void InicializarCostos(Mantenimiento* pMantenimiento);
int mant_setHospedaje(Mantenimiento* this,int valor);
int mant_setComida(Mantenimiento* this,int valor);
int mant_setTransporte(Mantenimiento* this,int valor);
int mant_getHospedaje(Mantenimiento* this,int* valor);
int mant_getComida(Mantenimiento* this,int* valor);
int mant_getTransporte(Mantenimiento* this,int* valor);

/**
 * Recibe un puntero a la estructura "Mantenimieto", pide datos al usuario y los guarda con SETTERS
 * @param pMantenimiento		Puntero a una estructura tipo MANTENIMIETO
 * @return						Retorno 0 si se pide y guarda los datos correctamente
 * 										-1 si no
 */
int mant_MostrarSubMenuMantenimiento(Mantenimiento* pMantenimiento);

#endif /* MANTENIMIENTO_H_ */


