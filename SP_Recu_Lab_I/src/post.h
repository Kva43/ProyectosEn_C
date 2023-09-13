#ifndef PELICULAS_H_
#define PELICULAS_H_

typedef struct
{
	int id;
	char user[100];
	int likes;
	int dislikes;
	int followers;
} Post;

#endif /* PELICULAS_H_ */

Post* post_new();

Post* post_newParametros(char* idStr,char* userStr, char* likesStr, char* dislikesStr, char* followersStr);


void post_delete(Post* this);

int post_setId(Post* this,int id);

int post_getId(Post* this,int* id);

int post_setUser(Post* this,char* user);

int post_getUser(Post* this,char* user);

int post_setLike(Post* this,int like);

int post_getLike(Post* this,int* like);

int post_setDislike(Post* this,int dislike);

int post_getDislike(Post* this,int* dislike);

int post_setFollower(Post* this,int follower);

int post_getFollower(Post* this,int* follower);

void menu_escribirCabezal(void);

void post_asignarEstadisticas(void* this);

int post_filtroMejoresPosteos(void* elemento);

int post_filtroHaters(void* elemento);
