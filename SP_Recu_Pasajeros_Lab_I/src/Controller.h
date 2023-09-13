#include "Passenger.h"
#include "LinkedList.h"

/**
 * Carga los datos de los pasajeros desde el archivo (modo texto).
 * @param path				Puntero al nombre del archivo
 * @param pArrayList		Puntero a la LinkedList
 * @return					Retorna 0 (bien).-1 (mal)
 */
int controller_loadFromText(char* path, LinkedList* pArrayList);

/**
 * Listar elementos
 * @param pArrayList	Puntero al nombre del archivo
 * @return				Retorna 0 (bien).-1 (mal)
 */
int controller_List(LinkedList* pArrayList);

/**
 * Guarda los datos de los pasajeros en el archivo (modo texto)
 * @param path			Puntero al nombre del archivo
 * @param pArrayList	Puntero a la LinkedList
 * @return				Retorna 0 (bien).-1 (mal)
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);

/**
 *	Imprime list
 * @param pPassenger
 * @return
 */
int controller_imprimir(eCorredor* pStruct);

/**
 *
 * @param pArrayListPassenger	Puntero a la LinkedList
 * @return						Retorna una LinkedList
 */
LinkedList* controller_map(LinkedList* pArrayList);
