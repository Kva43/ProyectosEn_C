#include "controller.h"

int controller_calcularPromJug(void* pConferacion, void* pPromedio)
{
	int retorno = -1;
	int respuesta;
	char mensaje[200] = "\n1- Calcular promedio de jugadores de cada mercado\n2. Calcular el costo de mantenimiento\n3. Costo mantenimiento mayoria europea";
	char mensajeError[100] = "\nERROR";
	utn_getNumero(&respuesta, mensaje, mensajeError, 1, 3, 2);
	int conf1, conf2, conf3, conf4, conf5, conf6, totalJug;
	float prom1, prom2, prom3, prom4, prom5, prom6;

	switch(respuesta)
	{
	case 1:
		if( conf_getAFC((Confederacion*) pConferacion, &conf1) == 0 &&
			conf_getCAF((Confederacion*) pConferacion, &conf2) == 0 &&
			conf_getCONCACAF((Confederacion*) pConferacion, &conf3) == 0 &&
			conf_getCONMEBOL((Confederacion*) pConferacion, &conf4) == 0 &&
			conf_getUEFA((Confederacion*) pConferacion, &conf5) == 0 &&
			conf_getOFC((Confederacion*) pConferacion, &conf6) == 0)
		{
			totalJug = conf1 + conf2 + conf3 + conf4 + conf5 + conf6;
			prom1 = conf1 * 100 / totalJug;
			prom2 = conf2 * 100 / totalJug;
			prom3 = conf3 * 100 / totalJug;
			prom4 = conf4 * 100 / totalJug;
			prom5 = conf5 * 100 / totalJug;
			prom6 = conf6 * 100 / totalJug;
			prom_setPromAFC((Promedio*)pPromedio, prom1);
			prom_setPromCAF((Promedio*)pPromedio, prom2);
			prom_setPromCONCACAF((Promedio*)pPromedio, prom3);
			prom_setPromCONMEBOL((Promedio*)pPromedio, prom4);
			prom_setPromUEFA((Promedio*)pPromedio, prom5);
			prom_setPromOFC((Promedio*)pPromedio, prom6);
		}
		break;
	case 2:
		break;
	case 3:
		break;
	}

	return retorno;
}


int controller_imprimirValores(void* pPromedios)
{
	int retorno = -1;
	float prom1, prom2, prom3, prom4, prom5, prom6;

	if(prom_getPromAFC((Promedio*)pPromedios, &prom1) == 0 &&
	prom_getPromCAF((Promedio*)pPromedios, &prom2) == 0 &&
	prom_getPromCONCACAF((Promedio*)pPromedios, &prom3) == 0 &&
	prom_getPromCONMEBOL((Promedio*)pPromedios, &prom4) == 0 &&
	prom_getPromOFC((Promedio*)pPromedios, &prom5) == 0 &&
	prom_getPromUEFA((Promedio*)pPromedios, &prom6) == 0)
	{
		printf("\nPromedio AFC: %.1f", prom1);
		printf("\nPromedio CAF: %.1f", prom2);
		printf("\nPromedio CONCACAF: %.1f", prom3);
		printf("\nPromedio CONMEBOL: %.1f", prom4);
		printf("\nPromedio OFC: %.1f", prom5);
		printf("\nPromedio UEFA: %.1f", prom6);
		retorno = 0;
	}
	return retorno;
}

int ImprimirMenu(Mantenimiento* pMantenimiento, Posiciones* pPosiciones)
{
	int opcion, comida, hospedaje, transporte, arquero, defensor, mediocampista, delantero;

	mant_getHospedaje(pMantenimiento, &hospedaje);
	mant_getComida(pMantenimiento, &comida);
	mant_getTransporte(pMantenimiento, &transporte);
	pos_getArquero(pPosiciones, &arquero);
	pos_getDefensor(pPosiciones, &defensor);
	pos_getMediocampista(pPosiciones, &mediocampista);
	pos_getDelantero(pPosiciones, &delantero);

	printf("\n#########################################"
			"\n 	Menu Principal""\n\n"
			"1. Ingreso de los costos de Mantenimiento.\n"
			"   Costo de Hospedaje -> $%d\n"
			"   Costo de Comida -> $%d\n"
			"   Costo de Transporte -> $%d\n\n"
			"2.  Carga de jugadores:\n"
			"   Arqueros -> $%d\n"
			"   Defensores -> $%d\n"
			"   Mediocampistas -> $%d\n"
			"   Delanteros -> $%d\n\n"
			"3. Realizar todos los cálculos.\n"
			"4. Informar todos los resultados.\n"
			"5. Salir\n"
			"\n#########################################\n", hospedaje, comida, transporte, arquero, defensor, mediocampista, delantero);
	scanf("%d", &opcion);

	return opcion;
}
