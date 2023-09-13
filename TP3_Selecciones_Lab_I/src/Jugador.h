#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void peli_delete(Jugador* this);

int peli_setId(Jugador* this,int id);
int peli_getId(Jugador* this,int* id);

int peli_setTitulo(Jugador* this,char* nombreCompleto);
int peli_getTitulo(Jugador* this,char* nombreCompleto);

int peli_setGenero(Jugador* this,char* posicion);
int peli_getGenero(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int peli_setDuracion(Jugador* this,int edad);
int peli_getDuracion(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

void menu_escribirCabezal();

Jugador* searchID(LinkedList* pArrayListJugador,int id);

#endif // jug_H_INCLUDED
