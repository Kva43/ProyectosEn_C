#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menus.h"
#include "utn.h"
#define CHAR_LEN 50

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listCorredores = ll_newLinkedList();
    int flagPrimerCargaTxt = 0;
    char nombre[CHAR_LEN];
    do
    {
        switch(menuOpcion())
        {
        case 1:
			if(utn_getAlfanumerica(nombre, CHAR_LEN, "\nNombre del archivo: ", "\nERROR", 2) == 0 && flagPrimerCargaTxt == 0)
			{
				controller_loadFromText(nombre,listCorredores);
				flagPrimerCargaTxt = 1;
			}
			else
				printf("Ya se cargo \n");
			break;
		case 2:
			controller_List(listCorredores);
			break;
		case 3:
			listCorredores = controller_map(listCorredores);
			controller_List(listCorredores);
			break;
		case 4:
			if(controller_saveAsText(nombre, listCorredores) == 0)
				printf("\nSE CARGÓ CORRECTAMENTE\n");
			break;
		case 5:
			printf("Salir\n");
			break;
        }
    } while(option != 6);
    ll_deleteLinkedList(listCorredores);
    return 0;
}
