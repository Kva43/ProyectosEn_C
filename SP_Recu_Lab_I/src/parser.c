#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"

#include "post.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_PostFromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;
	Post* puntero = NULL;
	char id[4096], user[4096], likes[4096], dislikes[4096], followers[4096];
	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes, followers);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes, followers) == 5)
			{
				puntero = post_newParametros(id, user, likes, dislikes, followers);
				if(puntero != NULL && ll_add(pArrayList, puntero) == 0)
					retorno = 0;
			}
			else
				break;
		} while(!feof(pFile));
	} fclose(pFile);
	return retorno;
}
