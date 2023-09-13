#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct {
	int id;
	char nombre[50];
	char region[50];
	int aniosCreacion;
	int isEmpty;
} eConfederacion;

#endif /* CONFEDERACION_H_ */

void menu_escribirCabezalConf(void);

int initArrayConf(eConfederacion* pConf, int cant);
int modificarIdConf(int num, char* pAEscribir);
int listarConf(eConfederacion* arrayConf, int cant);


/*Nota 4: La entidad eConfederaciones deberá contar con sus funciones de alta, baja y
modificación, pero para trabajar en el main solo usaremos los valores hardcodeados que se
ven en la *imagen02.*/

int altaConfederacion(eConfederacion* arrayConf, int cant, int char_len);
int darDeBajaConf(eConfederacion* arrayConf, int cant);
int modificarNuevaConf(eConfederacion* arrayConf, int cant, int char_len);
