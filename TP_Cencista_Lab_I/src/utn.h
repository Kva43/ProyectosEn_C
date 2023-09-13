/*
 * funciones.h
 *
 *  Created on: 23 abr. 2022
 *      Author: USUARIO
 */

#ifndef UTN_H_
#define UTN_H_

/**
 *Obtiene un string, si cumple con su funcion static "esNumerica" lo transforma en int
 * @param pResultado		Puntero a la variable donde se guarda el dato cuando se la llama
 * @param mensaje			Mensaje pidiendo dato al usuario
 * @param mensajeError		Mensaje si ingresa un texto no valido
 * @param minimo			Valor minimo que permite
 * @param maximo			Valor maximo que permite
 * @param reintentos		Cantidad de intentos del usuario para ingresar un dato valido
 * @return					Retorno 0 si le ingresaron un dato valido, -1 en caso contrario
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos);

/**
 *	Obtiene un string, si cumple con su funcion static "esNombre" lo copia en la direccion de memoria a la que apunta pResultado
 * @param pResultado		Puntero a la variable donde se guarda el dato cuando se la llama
 * @param mensaje			Mensaje pidiendo dato al usuario
 * @param mensajeError		Mensaje si ingresa un texto no valido
 * @param longitud			Longitud maxima que tendra el texto ingresado por el usuario
 * @param reintentos		Cantidad de intentos del usuario para ingresar un dato valido
 * @return					Retorno 0 si le ingresaron un dato valido, -1 en caso contrario
 */
int utn_getNombre(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos);

/**
 *Obtiene un string, si cumple con su funcion static "esTelefono" lo copia en la direccion de memoria a la que apunta pResultado
 * @param pResultado		Puntero a la variable donde se guarda el dato cuando se la llama
 * @param mensaje			Mensaje pidiendo dato al usuario
 * @param mensajeError		Mensaje si ingresa un texto no valido
 * @param longitud			Longitud maxima que tendra el texto ingresado por el usuario
 * @param reintentos		Cantidad de intentos del usuario para ingresar un dato valido
 * @return					Retorno 0 si le ingresaron un dato valido, -1 en caso contrario
 */
int utn_getTelefono(int* pResultado,char* mensaje,char* mensajeError, int longitud,int reintentos);


/**
 *	Obtiene un string, si cumple con su funcion static "esCalle" lo copia en la direccion de memoria a la que apunta pResultado
 * @param pResultado		Puntero a la variable donde se guarda el dato cuando se la llama
 * @param mensaje			Mensaje pidiendo dato al usuario
 * @param mensajeError		Mensaje si ingresa un texto no valido
 * @param longitud			Longitud maxima que tendra el texto ingresado por el usuario
 * @param reintentos		Cantidad de intentos del usuario para ingresar un dato valido
 * @return					Retorno 0 si le ingresaron un dato valido, -1 en caso contrario
 */
int utn_getCalle(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos);

/**
 *	Recibe el valor de flag (aux) inicializado, si ese valor coincide con el valor de "ok" ret vale 0, caso contrario vale "ret" vale -1 e imprime un msj de error que tambien recibe por parametro
 * @param aux			recibe un valor,por nosotros, a comparar
 * @param ok			valor que ingresamos nosotros
 * @param error			valor de error
 * @param mensaje		Mensaje de error que ingresamos
 * @return				Retorno 0 si le ingresaron un dato valido, -1 en caso contrario
 */
int validarFlag(int aux,int ok,int error,char*mensaje);
#endif /* UTN_H_ */

