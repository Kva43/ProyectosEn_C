#ifndef POSICIONES_H_
#define POSICIONES_H_

typedef struct {
	int idCliente;
	char equipo[50];
	int tiempoEstimado;
	char operador[100];
	int isEmpty;
} Alquiler;

#endif

/**
 * Inicializa campo isEmpty en 0 en todas las posiciones del array de structs
 * @param pMoto
 * @param cant
 * @return
 */
int initArrayAlquiler(Alquiler* array, int cant);

int alquiler_pedirCliente(Alquiler* array, int pos, int cant);

int alquiler_pedirEquipo(Alquiler* array, int pos);

int alquiler_pedirTiempo(Alquiler* array, int pos);

int alquiler_pedirOperador(Alquiler* array, int pos);
