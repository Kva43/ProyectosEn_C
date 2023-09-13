#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "validaciones.h"
#include "post.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagCargaCsv = -1;
    int flagEstadisticas = -1;
    LinkedList* listaPost = ll_newLinkedList();
    int id, likes, dislikes, followers;
    char user[100];
    Post* auxPost = NULL;
    int i;
    char mensajeError[200] = "\nNo hay jugadores cargados en el sistema o no se han cargado las estadisticas aún. Intente nuevamente...\n";

    do {
        switch(option = menu()) {
		case 1:
			if(flagCargaCsv == -1)
			{
				if(controller_cargarDesdeTexto("posts.csv",listaPost) == 0)
				{
					printf("\nSe cargó los datos de la lista.\n");
					flagCargaCsv = 0;
				}
			}
			else
				printf("\nLos datos del archivo ya fueron cargados.\n");
			break;
		case 2:
			if(flagCargaCsv == 0)
				controller_listar(listaPost);
			else
				printf(mensajeError);
			break;
		case 3:
			if(flagCargaCsv == 0)
			{
				if(controller_asignarEstadisticas(listaPost) == 0)
				{
					controller_listar(listaPost);
					flagEstadisticas = 0;
				}
			}
			else
				printf(mensajeError);
			break;
		case 4:
			if(flagCargaCsv == 0 && flagEstadisticas == 0)
				controller_filtroMejoresPost(listaPost);
			else
				printf(mensajeError);
			break;
		case 5:
			if(flagCargaCsv == 0 && flagEstadisticas == 0)
				controller_filtroHaters(listaPost);
			else
				printf(mensajeError);
			break;
		case 6:
			if(flagCargaCsv == 0 && flagEstadisticas == 0)
				controller_ordenarFollowers(listaPost);
			else
				printf(mensajeError);
			break;
		case 7:
			if(flagCargaCsv == 0 && flagEstadisticas == 0)
			{
				i = controller_posteoMasLikeado(listaPost);
				if(i >= 0)
				{
					auxPost = ll_get(listaPost, i);
					post_getId(auxPost, &id);
					post_getUser(auxPost, user);
					post_getLike(auxPost, &likes);
					post_getDislike(auxPost, &dislikes);
					post_getFollower(auxPost, &followers);
					menu_escribirCabezal();
					printf("   %-5d      %-25s 	%-5d 	     %-5d	      %-5d\n", id, user, likes, dislikes, followers);
				}
			}
			else
				printf(mensajeError);
			break;
		case 8:
			printf("\nCerrando sesión...");
			break;
        }
    } while(option != 8);
    ll_deleteLinkedList(listaPost);
    return 0;
}

