#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	eCorredor* pAuxPassenger = NULL;
	int r = 0;
	char var1[50],var2[50],var3[50],var4[50],var5[50];
	if(pFile == NULL)
	{
		printf("Archivo nulo");
	}
	else
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);

		while(!feof(pFile))
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
			if(r!=5)
			{
				break;
			}
			pAuxPassenger = Compras_newParametros(var1,var2,var3,var4,var5);

			if(pAuxPassenger!=NULL)
			{
				if(ll_add(pArrayListPassenger, pAuxPassenger)==0)
				{
					retorno = 0;
				}
			}
		}
	}
	  return retorno;
}
