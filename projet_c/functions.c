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
//All the functions of the ExiaSaver project are define in this file.

//-----------------------------------------//
//			FUNCTIONS EXIASAVER 		   //
//-----------------------------------------//

typedef struct element element;
struct element
{
	char *l;
	struct element *next;
};
typedef element *llist;

llist addStart(llist list, char *add)
{
	element *newElement = malloc(sizeof(element));
	
	strcpy(newElement->l,add);
	newElement->next = list;
	
	return newElement;
}

void printList(llist list)
{
	element *tmp = list;
	
	while(tmp != NULL)
	{
		printf("%s", tmp->l);
		tmp = tmp->next;
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

int alea(int a, int b)
{
	srand(time(NULL));
	int nb=rand()%b+a;
	return nb;
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

int max(int tab[], int sizeTab)
{
    //Find bigger value in tab
    int i = 0;
    int i_max = 0;

    while(i < sizeTab) //cross the tab
    {
        if(tab[i] > tab[i_max])
        {
            i_max = i; //If value find bigger than max, it's the new max
        }
        i++;
    }
    return i_max;
}

void swap(int tab[], int i, int y)
{
    //swap 2 cases's values

    int tmp;

    tmp = tab[i];
    tab[i] = tab[y];
    tab[y] = tmp;
}

void triSelection(int tab[], int sizeTab)
{
    int i_max;

    for(; sizeTab > 1; sizeTab--) //reduce tab at each passage
    {
        i_max = max(tab, sizeTab);       //find the max

        swap(tab, sizeTab-1, i_max);  //Swap max to the first position
    }
}

//-----------------------------------------//
//			FUNCTIONS SAVER STATIC		   //
//-----------------------------------------//

FILE* chargeFile(FILE *descriptor, char *path, char *mode)
{
	int pid;
	
	pid = fork();
	
	switch(pid)
	{
		case -1:
			printf("Processus creation failed");
			break;
		
		case 0:
			descriptor = fopen(path, mode);
			break;
			
		default:
			wait(NULL);
			break;
			
	}
				
	if(descriptor==NULL)
	{
		printf("Opening failed");
	}
	else
	{
		return descriptor;
	}
}

void sizeImg(char *l, int *h, int *w)
{
	char *tmp;
	
	tmp = strtok(l, " ");
	
	*w = atoi(tmp);
	
	tmp = strtok(NULL, " ");
	
	*h = atoi(tmp);
}

void printHorizontal(char *l, size_t wei)
{
	size_t lenght = strlen(l);
	
	if(wei >= lenght)
	{
		size_t n = (wei - lenght)/2;
		
		for(size_t i=0; i<n;i++)
		{
			printf(" ");
		}
	}
	for(int y=0; y<=lenght; y++)
	{
		switch (l[y])
		{
			case 48:
				printf(" ");
				break;
				
			case 49:
				printf("%c", 219);
				break;
			case 32:
				break;
			default:
				break;
		}
	}
}

void center(int hMax, int *h) 
{
	if(hMax >= *h)
	{
		int n = (hMax - *h)/2;
		
		for(int i=0; i<n; i++)
		{
			printf("\n");
		}
	}
	else
	{
		printf("Image trop grande");
	}
	
}
