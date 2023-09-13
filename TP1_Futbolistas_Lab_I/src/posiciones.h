#ifndef POSICIONES_H_
#define POSICIONES_H_

typedef struct {
	int arquero;
	int defensor;
	int mediocampista;
	int delantero;
} Posiciones;

void inicializarPosiciones(Posiciones* posiciones);
int pos_setArquero(Posiciones* this, int valor);
int pos_getArquero(Posiciones* this,int* valor);
int pos_setDefensor(Posiciones* this, int valor);
int pos_getDefensor(Posiciones* this,int* valor);
int pos_setMediocampista(Posiciones* this, int valor);
int pos_getMediocampista(Posiciones* this,int* valor);
int pos_setDelantero(Posiciones* this, int valor);
int pos_getDelantero(Posiciones* this,int* valor);
int main_ingresarJugadores(Posiciones* a);

#endif /* POSICIONES_H_ */
