#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "string.h"
#include "post.h"
#include "validaciones.h"

#define USER_LEN 100

static int compararFollowers(void* a, void* b);

/** \brief Carga los datos de los post desde el archivo post.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeTexto(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && pArrayList != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL && parser_PostFromText(pFile, pArrayList) == 0)
			retorno = 0;
		else
			printf("\nNo se pudo abrir el archivo");
	}
	fclose(pFile);
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listar(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id, like, dislike, follower = 0;
	char user[USER_LEN];
	Post* b;

	if(pArrayListJugador != NULL)
	{
		menu_escribirCabezal();
		for(int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			b = ll_get(pArrayListJugador, i);

			if(b != NULL)
			{
				if( post_getId(b, &id) == 0 &&
					post_getUser(b, user) == 0 &&
					post_getLike(b, &like) == 0 &&
					post_getDislike(b, &dislike) == 0 &&
					post_getFollower(b, &follower) == 0)
				{
					printf("   %-5d      %-25s 	%-5d 	     %-5d	      %-5d\n", id, user, like, dislike, follower);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarModoTexto(char* path , LinkedList* pArrayListPeliculas)
{
	int retorno = -1;
	FILE* pFile;
	int id, like, dislike, follower;
	char user[100];
	Post* post_Aux;

	if (path != NULL && pArrayListPeliculas != NULL )
	{
		pFile = fopen(path, "w");
		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		fprintf(pFile, "id,user,likes,dislikes,followers\n");

		for (int i = 0; i < ll_len(pArrayListPeliculas); i++)
		{
			post_Aux = ll_get(pArrayListPeliculas, i);
			if( post_getId(post_Aux, &id) == 0 &&
				post_getUser(post_Aux, user) == 0 &&
				post_getLike(post_Aux, &like) == 0 &&
				post_getDislike(post_Aux, &dislike) == 0 &&
				post_getFollower(post_Aux, &follower) == 0)
			{
				fprintf(pFile, "%d,%s,%d,%d,%d\n", id, user, like, dislike, follower);
				retorno = 0;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_asignarEstadisticas(LinkedList* pArrayLinkedList)
{
	int retorno = -1;
	void (*pFunc)(void* element);
	if(pArrayLinkedList != NULL)
	{
		pFunc= post_asignarEstadisticas;
		ll_map(pArrayLinkedList, pFunc);
		retorno = 0;
	}
	return retorno;
}

int controller_filtroMejoresPost(LinkedList* pArrayLinkedList)
{
    int retorno = -1;
    LinkedList* listaFiltrada = NULL;
    if(pArrayLinkedList != NULL)
    {
		listaFiltrada = ll_filter(pArrayLinkedList, post_filtroMejoresPosteos);
		controller_listar(listaFiltrada);
		controller_guardarModoTexto("postDos.csv",listaFiltrada);
		retorno = 0;
    }
    return retorno;
}

int controller_filtroHaters(LinkedList* pArrayLinkedList)
{
    int retorno = -1;
    LinkedList* listaFiltrada = NULL;
    if(pArrayLinkedList != NULL)
    {
		listaFiltrada = ll_filter(pArrayLinkedList, post_filtroHaters);
		controller_listar(listaFiltrada);
		controller_guardarModoTexto("postDos.csv",listaFiltrada);
		retorno = 0;
    }
    return retorno;
}


int controller_ordenarFollowers(LinkedList* pArrayPost)
{
	int retorno = -1;
	if (pArrayPost != NULL)
	{
		ll_sort(pArrayPost, compararFollowers, 0);	//0 es de mayor a menor
		controller_listar(pArrayPost);
		retorno = 0;
	}
    return retorno;
}

static int compararFollowers(void* a, void* b)
{
	int retorno = 0;
	int auxA;
	int auxB;
	if(a != NULL && b != NULL)
	{
		post_getFollower(a, &auxA);
		post_getFollower(b, &auxB);
		if(auxA > auxB)
			retorno = 1;
		else
			retorno = -1;
	}
	return retorno;
}

int controller_posteoMasLikeado(LinkedList* pArrayPost)
{
	Post* postAux = NULL;
	int auxUno = 0;
	int auxDos = 0;
	int retorno = -1;
	if(pArrayPost != NULL)
	{
		for(int i = 0; i < ll_len(pArrayPost); i++)
		{
			postAux = ll_get(pArrayPost, i);
			post_getLike(postAux, &auxUno);
			if(auxUno > auxDos)
			{
				auxDos = auxUno;
				retorno = i;
			}
		}
	}
	return retorno;
}


int menu(void)
{
	int opcion;
	int retorno = -1;
	if(utn_getNumero(&opcion,
			"\n=========================================\n"
			"|     Menu Principal    			|\n"
			"|  1   Carga de archivos			|\n"
			"|  2   Imprimir					|\n"
			"|  3   Asignar estadisticas			|\n"
			"|  4   Filtrar por mejores posteos		|\n"
			"|  5   Filtrar por haters			|\n"
			"|  6   Ordenar por nivel de cant followers	|\n"
			"|  7   Mostrar más popular			|\n"
			"|  8 	Salir					|\n"
			"=========================================\n"
			,"\nERROR. Ingrese un numero del 1 al 8\n",1,8,2) == 0)
	{
		retorno = opcion;
	}
	return retorno;
}
