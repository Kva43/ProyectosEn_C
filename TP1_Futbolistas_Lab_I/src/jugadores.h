#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct {
	int camiseta;
	int posicion;
	int confederacion;
} Jugadores;

int jug_setCamiseta(Jugadores* this, int valor);
int jug_getCamiseta(Jugadores* this,int* valor);
int peli_setGenero(Jugadores* this, int valor);
int peli_getGenero(Jugadores* this,int* valor);
int jug_setConfederacion(Jugadores* this, int valor);
int jug_getConfederacion(Jugadores* this,int* valor);
int ingresarJug(Jugadores* pJug, void* pPosicion, void* pConfederacion);

#endif /* JUGADORES_H_ */

