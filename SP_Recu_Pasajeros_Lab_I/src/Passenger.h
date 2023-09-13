#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char apellido[50];
	char tipo[50];
	int promedio;
	float tiempo;
}eCorredor;

/**
 *Reserva memoria dinamica
 * @return	Devuelve puntero a eCorredor
 */
eCorredor* Compras_new();

/**
 * Setea los parametros recibidos con subfunciones para cada uno
 * @param idStr			Puntero a cadena de caracteres
 * @param apellidoStr	Puntero a cadena de caracteres
 * @param tipoStr		Puntero a cadena de caracteres
 * @param promedioStr	Puntero a cadena de caracteres
 * @param tiempoStr		Puntero a cadena de caracteres
 * @return				Retorna puntero inicializado en memoria dinamica con todos los datos seteados
 */
eCorredor* Compras_newParametros(char* idStr,char* apellidoStr,char* tipoStr,char* promedioStr,char* tiempoStr);

/**
 *Guarda el entero en el campo correspondiente del puntero a eCorredor recibido
 * @param this	Puntero a eCorredor
 * @param id	Entero a asignar
 * @return		Retorna 0 (bien).-1 (mal)
 */
int Corredor_setId(eCorredor* this,int id);

/**
 *Copia un campo en especifico de la estructura en el puntero recibido como parametro
 * @param this	Puntero a eCorredor
 * @param id	Puntero donde se copiara el campo correspondiente
 * @return		Retorna 0 (bien).-1 (mal)
 */
int Corredor_getId(eCorredor* this,int* id);

/**
 *Guarda el string en el campo correspondiente del puntero a eCorredor recibido
 * @param this		Puntero a eCorredor
 * @param apellido	String a asignar
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_setApellido(eCorredor* this,char* apellido);

/**
 *Copia un campo en especifico de la estructura en el puntero recibido como parametro
 * @param this		Puntero a eCorredor
 * @param apellido	Puntero donde se copiara el campo correspondiente
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_getApellido(eCorredor* this,char* apellido);

/**
 *Guarda el string en el campo correspondiente del puntero a eCorredor recibido
 * @param this	Puntero a eCorredor
 * @param tipo	String a asignar
 * @return		Retorna 0 (bien).-1 (mal)
 */
int Corredor_setTipo(eCorredor* this,char* tipo);

/**
 *Copia un campo en especifico de la estructura en el puntero recibido como parametro
 * @param this	Puntero a eCorredor
 * @param tipo	Puntero donde se copiara el campo correspondiente
 * @return		Retorna 0 (bien).-1 (mal)
 */
int Corredor_getTipo(eCorredor* this,char* tipo);

/**
 *Guarda el entero en el campo correspondiente del puntero a eCorredor recibido
 * @param this		Puntero a eCorredor
 * @param promedio	entero a asignar
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_setPromedio(eCorredor* this,int promedio);

/**
 *Copia un campo en especifico de la estructura en el puntero recibido como parametro
 * @param this		Puntero a eCorredor
 * @param promedio	Puntero donde se copiara el campo correspondiente
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_getPromedio(eCorredor* this,int* promedio);

/**
 *Guarda el float en el campo correspondiente del puntero a eCorredor recibido
 * @param this		Puntero a eCorredor
 * @param tiempo	Float a asignar
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_setTiempo(eCorredor* this,float tiempo);

/**
 *Copia un campo en especifico de la estructura en el puntero recibido como parametro
 * @param this		Puntero a eCorredor
 * @param tiempo	Puntero donde se copiara el campo correspondiente
 * @return			Retorna 0 (bien).-1 (mal)
 */
int Corredor_getTiempo(eCorredor* this,float* tiempo);

/**
 *Escribe el cabezal del menu
 */
void menu_escribirCabezal(void);

/**
 *Realiza el calculo y lo copia en un campo de la estructura
 * @param puntero	Puntero donde se copiara el campo correspondiente
 * @return			Retorna 0 (bien).-1 (mal)
 */
int asignarTotal(void* puntero);
#endif
