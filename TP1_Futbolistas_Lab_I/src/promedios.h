#ifndef PROMEDIOS_H_
#define PROMEDIOS_H_

typedef struct {
	float promAFC;
	float promCAF;
	float promCONCACAF;
	float promCONMEBOL;
	float promUEFA;
	float promOFC;
} Promedio;

int prom_setPromAFC(Promedio* this, float valor);
int prom_getPromAFC(Promedio* this,float* valor);
int prom_setPromCAF(Promedio* this, float valor);
int prom_getPromCAF(Promedio* this,float* valor);
int prom_setPromCONMEBOL(Promedio* this, float valor);
int prom_getPromCONMEBOL(Promedio* this,float* valor);
int prom_setPromUEFA(Promedio* this, float valor);
int prom_getPromUEFA(Promedio* this,float* valor);
int prom_setPromOFC(Promedio* this, float valor);
int prom_getPromOFC(Promedio* this,float* valor);
int prom_setPromCONCACAF(Promedio* this, float valor);
int prom_getPromCONCACAF(Promedio* this,float* valor);

#endif /* PROMEDIOS_H_ */
