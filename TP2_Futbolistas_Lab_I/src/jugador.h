#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct {
	int id;
	char nombre[50];
	char posicion[50];
	int numeroCamiseta;
	int idConfederacion;
	float salario;
	int aniosContrato;
	int isEmpty;
} eJugador;

#endif /* JUGADOR_H_ */

void menu_escribirCabezal(void);
int initArrayJug(eJugador* pStruct, int cant);
