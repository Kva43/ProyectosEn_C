#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_PelisFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* puntero = NULL;
	char id[4096],nombre[4096],edad[4096],pos[4096],nacion[4096],idSelec[4096];
	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,pos,nacion,idSelec);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,pos,nacion,idSelec) == 6)
			{
				puntero = jug_newParametros(id,nombre,edad,pos,nacion,idSelec);
				if(puntero != NULL)
				{
					if(ll_add(pArrayListJugador, puntero) == 0)
					{
						retorno = 0;
					}
				}
			}
			else
				break;
		} while(!feof(pFile));
	} fclose(pFile);
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{

	return 0;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* puntero = NULL;
	char id[4096],pais[4096],confederacion[4096],convocados[4096];
	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados) == 4)
			{
				puntero = selec_newParametros(id,pais,confederacion,convocados);
				if(puntero != NULL)
				{
					if(ll_add(pArrayListSeleccion, puntero) == 0)
					{
						retorno = 0;
					}
				}
			}
			else
				break;
		} while(!feof(pFile));
	} fclose(pFile);
	return retorno;
}
