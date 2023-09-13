/*
 * vivienda.h
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_
#include "censista.h"

#define CALLE_LEN 25
#define CANT_VIVIENDAS 5

typedef struct
{
	int idVivienda;
	char calle[CALLE_LEN];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
} eVivienda;

#endif /* VIVIENDA_H_ */

/**
 * Inicializo todas las posiciones de mi array en vacias. isEmpty=-1
 * @param aux		Puntero a la variable donde se cargaran los dato
 * @param limite	Cantidad de veces que itera el for()
 * @return			Retorna 0 si se logro cargar los datos, -1 en caso contrario
 */
int vivienda_inicializarArray(eVivienda*aux, int limite);

/**
 * Recorro el array de estructura buscando una posición vacía
 * @param aux		Puntero a la variable donde se cargarán los datos
 * @param limite	Cantidad de veces que itera el for()
 * @return			Retorno la posición que encontré vacía
 */
int vivienda_buscarPosicionVacia(eVivienda*aux,int limite);

/**
 * Pide al usuario cada campo, de la estructura, de la posicion que recibe como parametro
 * @param aux			Puntero a la variable de tipo estructura donde se cargarán los datos
 * @param id			Valor recibido(no por el usuario)
 * @param posicion		Posicion de la array de estructura donde se guardaran los datos
 * @param legajo		Identificar que recibe por parametro
 * @return				Retorna 0 si se logro cargar los datos, -1 en caso contrario
 */
int vivienda_pedirCargarDatos(eVivienda*aux,int id,int posicion,int valor);

/**
 * Imprime todas las posiciones con datos(.isEmpty=-1)
 * @param aux		Puntero a la variable de tipo estructura donde se cargarán los datos
 * @param limite	Cantidad de veces que itera el for()
 * @return			Retorna 0 si se logro mostrar los datos, -1 en caso contrario
 */
int vivienda_imprimirTodos(eVivienda* aux,int limite);

/**
 * Recibe un id. Recorre el array de estructuras comparandolo, si hay coincidencia, llama a una funcion para mostrar los datos de la posicion de ese id.
 *  Muestra un submenu para que el usuario elija que campo modificar
 * @param aux		Puntero a la variable de tipo estructura donde se cargarán los datos
 * @param limite	Cantidad de veces que itera el for()
 * @param id		Valor recibido(por el usuario)
 * @return			Retorna 0 si se logro modificar los datos, -1 en caso contrario
 */
int vivienda_modificarPorId(eVivienda* aux, int limite,int id);

/**
 * Recibe un id. Recorre el array de estructuras comparandolo, si hay coincidencia, llama a una funcion para mostrar los datos de la posicion de ese id.
 * Luego pregunta al usuario si quiere dar de baja esa posicion
 * @param aux		Puntero a la variable de tipo estructura donde se dará de baja los datos
 * @param limite	Cantidad de veces que itera el for()
 * @param id		Valor recibido(por el usuario)
 * @return			Retorna 0 si se logro dar de baja los datos, -1 en caso contrario
 */
int vivienda_darDeBaja(eVivienda*aux, int limite, int id);

/**
 * Ordena de menor a mayor las posiciones de mi array de estructuras
 * @param aux			Puntero a la variable de tipo estructura donde se dará de baja los datos
 * @param limite		Cantidad de veces que itera el for()
 * @param longitud		Longitud de la cadena de caracteres del campo a la variable de tipo estructura a la que apunta
 * @return				Retorna -1 si no cumple las condiciones != NULL o >=0, retorna 0 si no hace falta ordenar, y retornar 1 si ordena
 */
int vivienda_ordenar(eVivienda*aux, int limite,int longitud);

/**
 * Cuenta las posiciones del array de estructura que tienen en -1(false) el .isEmpty. Usa un cont inicializado en 0
 * @param aux		Puntero a la variable de tipo estructura donde se dará de baja los datos
 * @param limite	Cantidad de veces que itera el for()
 * @return			Retorna la cantidad de veces que se cumple con la condicion
 */
int vivienda_contarPosicionesLlenas(eVivienda*aux,int limite);


int vivienda_imprimirPorLegajo(eVivienda*aux,int limite,int legajo);



