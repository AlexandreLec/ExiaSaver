#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int alea(int a, int b);
char* picImg();
void start(char* nameExec, char* param);

int main(int argc, char *argv)
{
	int nbRand;
	char *pathImg;

	system("clear");
	
	nbRand = alea(1,3);

	switch(nbRand)
	{
		case 1:
		//statique
		pathImg = picImg();
		start("statique",pathImg);
		break;
		
		case 2:
		//dynamique
		start("dynamique", NULL);
		break;
		
		case 3:
		//interactif
		start("interactif", NULL);
		break;
	}
	
	return 1;
}

char* picImg()
{
	char *pathImg;
	char *nameImg;
	char **tabImg;
	
	int nbImg=0;
	int nbAlea=0;
	
	tabImg = (char**)malloc(10*(sizeof(char*)));
	
	pathImg = getenv("EXIASAVER1_PBM");
	
	struct dirent *contenuRep;
	DIR *rep;
	
	rep = opendir(pathImg);
	
	if(rep == NULL)
	{
		printf("Openning rep failed");
	}
	
	while((contenuRep = readdir(rep)) != NULL)
	{
		if(strcmp(contenuRep->d_name, ".") == 0 || strcmp(contenuRep->d_name, "..") == 0){}
			
		else
		{
			tabImg[nbImg]=(contenuRep->d_name);
			nbImg++;
		}		
	}
	
	
	closedir(rep);
	
	nbAlea = alea(0,nbImg);
	
	nameImg = tabImg[nbAlea];
	
	free(tabImg);
	
	strcat(pathImg, nameImg);
	
	return pathImg;
}

int alea(int a, int b)
{
	srand(time(NULL));
	int nb=rand()%b+a;
	return nb;
}

void start(char* nameExec, char* param)
{
	int pid=-1;
	char* pathExec;
	
	pathExec = getenv("EXIASAVER_HOME");
	strcat(pathExec, nameExec);
	
	pid = fork();
	
	switch(pid)
	{
		case -1:
			printf("Processus creation failed");
			break;
		case 0:
			execl(pathExec,nameExec,param,(char*)NULL);
			break;
		default:
			wait(NULL);
			break;
	}
}


