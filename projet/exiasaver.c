#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int alea(int a, int b);
char* picImg(char* pathImg);
void start(char* nameExec, char* param);
void history(char* type, char* param);

int main(int argc, char *argv[])
{
	if(argc == 2 && (strcmp(argv[1], "-stats") == 0))
	{
		printf("Choisissez un mode d'affichage des statistiques des screensavers lances");
		//scanf("");
		
	}
	
	else if(argc == 1)
	{
		int nbRand;
		char *path;
		char *name;

		system("clear");
	
		nbRand = alea(1,3);

		switch(nbRand)
		{
			case 1:
			//statique
			path = getenv("EXIASAVER1_PBM");
			name = picImg(path);
			
			history(" 1 ", name);
			
			strcat(path, name);
			start("statique",path);
			break;
		
			case 2:
			//dynamique
			history(" 2 ", name);
			start("dynamique", NULL);
			break;
		
			case 3:
			//interactif
			history(" 3 ", name);
			start("interactif", NULL);
			break;
		}
	}
	
	else
	{
		printf("Too many arguments\n");
	}
	
	return 1;
}

int openHistory()
{
	int idH;

	idH = open("history.txt", O_CREAT, S_IRUSR);
		
	if(idH==-1)
	{
		printf("fileHistory can't load");
		return -1;
	}
	else
	{
		return idH;
	}
}

void history(char* type, char* param)
{
	printf("%s", param);
	
	struct tm timeStart;
	time_t sec;
	
	char *lineHistory;
	lineHistory = (char*)malloc(sizeof("DD/MM/YYYY HH:MM:SS typetypetype parametreparametre"));
	
	sec = time(NULL);
	timeStart = *localtime(&sec);
	
	strftime(lineHistory, sizeof("DD/MM/YYYY HH:MM:SS"), "%d/%m/%Y %H:%M:%S", &timeStart);

	strcat(lineHistory,type);

	strcat(lineHistory,param);
	
	FILE* history = fopen("history.txt","a+");
	
	if(history != NULL)
	{
		fprintf(history,"%s\n", lineHistory);
		
		fclose(history), history = NULL;
		
	}
	else
	{
		printf("ERREUR");
	}
	
	
	free(lineHistory);	
	
}

char* picImg(char* pathImg)
{
	char *nameImg;
	char **tabImg;
	
	int nbImg=0;
	int nbAlea=0;
	
	tabImg = (char**)malloc(10*(sizeof(char*)));
	
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
	
	return nameImg;
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


