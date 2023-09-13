#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int afc;
	int caf;
	int concacaf;
	int conmebol;
	int uefa;
	int ofc;
} Confederacion;

int conf_initConfederacion(Confederacion* this);
int conf_setAFC(Confederacion* this, int valor);
int conf_getAFC(Confederacion* this,int* valor);
int conf_setCAF(Confederacion* this, int valor);
int conf_getCAF(Confederacion* this,int* valor);
int conf_setCONCACAF(Confederacion* this, int valor);
int conf_getCONCACAF(Confederacion* this,int* valor);
int conf_setCONMEBOL(Confederacion* this, int valor);
int conf_getCONMEBOL(Confederacion* this,int* valor);
int conf_setUEFA(Confederacion* this, int valor);
int conf_getUEFA(Confederacion* this,int* valor);
int conf_setOFC(Confederacion* this, int valor);
int conf_getOFC(Confederacion* this,int* valor);

#endif /* CONFEDERACIONES_H_ */
