#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MAX_CHAR 20

typedef struct {
	int id;
	int dni;
	char nombre[MAX_CHAR];
	char apellido[MAX_CHAR];
	int isEmpty;
} Cliente;

#endif /* CLIENTE_H_ */

int modificarIdCliente(int num, char* pAEscribir);

/**
 * Pide marca de la moto al usuario
 * @param arrayMotos
 * @param pos
 * @return
 */
int cliente_pedirNombre(Cliente* arrayMotos, int pos);

/**
 * Asigna automatica con rand()
 * @param arrayMotos
 * @param pos
 * @return
 */
int cliente_pedirApellido(Cliente* arrayMotos, int pos);

/**
 * Asigna automatica con rand()
 * @param arrayMotos
 * @param pos
 * @return
 */
int cliente_pedirDNI(Cliente* arrayMotos, int pos);



int initArrayClientes(Cliente* array, int cant);
