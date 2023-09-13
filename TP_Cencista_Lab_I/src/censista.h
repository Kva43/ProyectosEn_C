/*
 * censista.h
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#define NOMBRE_LEN 20
#define TELEFONO_LEN 12
#define CANT_CENSISTAS 3

typedef struct
{
	int legajoCensista;
	char nombre[NOMBRE_LEN];
	int edad;
	char telefono[TELEFONO_LEN];
} eCensista;

#endif /* CENSISTA_H_ */

/**
 * Carga los datos en la posicion que recibe
 * @param aux		Puntero a la variable donde se cargaran los datos
 * @param len		Posicion donde se carga los datos
 * @param legajo	Dato que se cargará en su respectivo campo
 * @param nombre	Dato que se cargará en su respectivo campo
 * @param edad		Dato que se cargará en su respectivo campo
 * @param telefono 	Dato que se cargará en su respectivo campo
 * @return			Retorna 0 si se logro cargar los datos, -1 en caso contrario
 */
int censista_harcodearDatos(eCensista*aux,int len,int legajo,char*nombre,int edad, char*telefono);

/**
 * Imprime los datos de cada posicion del array
 * @param aux		Puntero a la variable donde se cargaran los datos
 * @param limite	Cantidad de veces que itera el for()
 * @return			Retorna 0 si se logro cargar los datos, -1 en caso contrario
 */
int censista_imprimirDatos(eCensista* aux,int limite);


int retornarLegajoAuto(eCensista*aux,int pos);

int censista_mostrarPosicionIndividual(eCensista*aux, int i);

