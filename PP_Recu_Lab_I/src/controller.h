#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "alquiler.h"
#include "cliente.h"

#endif /* CONTROLLER_H_ */

/**
 * Pide algunos datos al usuario, otros los hardcodeo
 * @param arrayMotos
 * @param cant
 * @return
 */
int controller_altaCliente(Cliente* array, int cant);

/**
 * Imprime los datos de las motos(isEmpty == 0 ->'true' quiere decir que NO esta vacia)
 * @param arrayMotos
 * @param cantMotos
 * @return
 */
//int controller_listarMotos(Moto* arrayMotos, int cantMotos);

/**
 * Modifica color y/o puntaje
 * @param arrayMotos
 * @param cantMotos
 * @return
 */
int controller_modificarCliente(Cliente* array, int cant);

/**
 * Cambia el campo isEmpty(de, este caso, arrayMotos) de -1(false) a 0(true)
 * @param arrayMotos
 * @param cantMotos
 * @return
 */
int controller_darBaja(Cliente* array, int cant);

/**
 * Asigna un trabajo
 * @param arrayMotos
 * @param cantMotos
 * @param arrayTrabajo
 * @param arrayServicio
 * @param idIncremental
 * @return
 */
//int controller_altaTrabajo(Moto* arrayMotos, int cantMotos, Trabajo* arrayTrabajo, Servicio* arrayServicio, int idIncremental);
//int controller_imprimirTrabajos(Trabajo* arrayTrabajo, int cant, Moto* arrayMotos, Servicio* arrayServicio);

/**
 * Imprime lista de motos de un solo tipo que el usuario elige previamente
 * @param arrayMotos
 * @param cantMotos
 * @return
 */
//int controller_listarTiposDeMotos(Moto* arrayMotos, int cantMotos);

/**
 * Imprime lista de motos de un solo color que el usuario elige previamente
 * @param arrayMotos
 * @param cantMotos
 * @return
 */
//int controller_listarColoresDeMotos(Moto* arrayMotos, int cantMotos);

//MENU 2
//int controller_promPuntajeDeTipo(Moto* arrayMotos, int cantMotos);
//int controller_imprimirMotosMayorCilindrada(Moto* arrayMotos, int cantMotos);
//
//int controller_listarColoresTiposDeMotos(Moto* arrayMotos, int cantMotos);
//int controller_listarColoresMasElegido(Moto* arrayMotos, int cantMotos);
//int controller_imprimirTrabajosPorID(Trabajo* arrayTrabajo, int cant, Moto* arrayMotos, Servicio* arrayServicio, int idIncremental);
//int harcodear_trabajo(Moto* arrayMotos, int cantMotos, Trabajo* arrayTrabajo, Servicio* arrayServicio, int idIncremental,int i,int id);

void menu_escribirCabezalServicios(void);
int menu();


int controller_listarClientes(Cliente* array, int cant);


int controller_altaAlquiler(Alquiler* array, Cliente* arrayClientes, int cant);

int controller_listarClienteAlquileres(Cliente* array, Alquiler* arrayAlq, int cant);
int controller_listar(Cliente* array, Alquiler* arrayAlq, int cant);
int controller_darBajaAlquiler(Cliente* array, Alquiler* arrayAlq, int cant);
