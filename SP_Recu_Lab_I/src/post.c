#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "post.h"
#include "validaciones.h"

#define USER_LEN 100

Post* post_new()
{
	Post* auxiliarP = NULL;
	auxiliarP = (Post*) malloc(sizeof(Post));
	return auxiliarP;
}

Post* post_newParametros(char* idStr,char* userStr, char* likesStr, char* dislikesStr, char* followersStr)
{
	Post* this = NULL;
	this = post_new();
	if(this != NULL && idStr != NULL && userStr != NULL && dislikesStr != NULL && likesStr != NULL && followersStr != NULL)
	{
		if(esNumerica(idStr,10) && esNumerica(likesStr,10) && esNumerica(dislikesStr,10) && esNumerica(followersStr,10))
		{
			if(	post_setId(this, atoi(idStr)) == -1 ||
				post_setUser(this, userStr) == -1 ||
				post_setLike(this, atoi(likesStr)) == -1 ||
				post_setDislike(this, atoi(dislikesStr)) == -1 ||
				post_setFollower(this, atoi(followersStr)) == -1)
			{
				post_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}

void post_delete(Post* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int post_setId(Post* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int post_getId(Post* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int post_setUser(Post* this,char* user)
{
	int retorno = -1;
	if(this != NULL && user != NULL)
	{
		if(esAlfanumerica(user,USER_LEN))
		{
			retorno = 0;
			strncpy(this->user,user,USER_LEN);
		}
	}
	return retorno;
}

int post_getUser(Post* this,char* user)
{
	int retorno = -1;
	if(this != NULL && user != NULL)
	{
		retorno = 0;
		strncpy(user,this->user,USER_LEN);
	}
	return retorno;
}

int post_setLike(Post* this,int like)
{
	int retorno = -1;
	if(this != NULL && like >= 0)
	{
		retorno = 0;
		this->likes = like;
	}
	return retorno;
}

int post_getLike(Post* this,int* like)
{
	int retorno = -1;
	if(this != NULL && like != NULL)
	{
		retorno = 0;
		*like = this->likes;
	}
	return retorno;
}

int post_setDislike(Post* this,int dislike)
{
	int retorno = -1;
	if(this != NULL && dislike >= 0)
	{
		retorno = 0;
		this->dislikes = dislike;
	}
	return retorno;
}

int post_getDislike(Post* this,int* dislike)
{
	int retorno = -1;
	if(this != NULL && dislike != NULL)
	{
		retorno = 0;
		*dislike = this->dislikes;
	}
	return retorno;
}

int post_setFollower(Post* this,int follower)
{
	int retorno = -1;
	if(this != NULL && follower >= 0)
	{
		retorno = 0;
		this->followers = follower;
	}
	return retorno;
}

int post_getFollower(Post* this,int* follower)
{
	int retorno = -1;
	if(this != NULL && follower != NULL)
	{
		retorno = 0;
		*follower = this->followers;
	}
	return retorno;
}

void menu_escribirCabezal(void)
{
	printf("==============================================================================\n");
	printf("| ID |  	 USERS  		 |   LIKES    |   DISLIKES   |   FOLLOWERS   |\n");
	printf("------------------------------------------------------------------------------\n");
}

void post_asignarEstadisticas(void* this)
{
	post_setLike(this, (rand() % 4400) + 600);
	post_setDislike(this, (rand() % 3200) + 300);
	post_setFollower(this, (rand() % 10000) + 10000);
}

int post_filtroMejoresPosteos(void* elemento)
{
	Post* aux = NULL;
	int retorno = -1;
	aux = (Post*)elemento;
	if(aux != NULL)
	{
		if(aux->likes > 4000)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int post_filtroHaters(void* elemento)
{
	Post* aux = NULL;
	int retorno = -1;
	aux = (Post*)elemento;
	if(aux != NULL)
	{
		if(aux->likes < aux->dislikes)
		{
			retorno = 0;
		}
	}
	return retorno;
}
