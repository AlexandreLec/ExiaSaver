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
	
	strcpy(newElement->l,add);//copies the string pointed to, by src to dest.
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
	
	//Struct for get informations about time
	struct tm timeStart;
	//Type time_t is define in library time.h
	time_t sec;
	
	//Line that will be print in the history.txt file
	char *lineHistory;
	//Dynamic allocation
	lineHistory = (char*)malloc(sizeof("DD/MM/YYYY HH:MM:SS typetypetype parametreparametre"));
	
	//Get information about localtime of the computer in the struct timeStart
	sec = time(NULL);
	timeStart = *localtime(&sec);
	
	//Time format in lineHistory
	strftime(lineHistory, sizeof("DD/MM/YYYY HH:MM:SS"), "%d/%m/%Y %H:%M:%S", &timeStart);
	
	//Create lineHistory; add informations about time
	strcat(lineHistory,type);
	strcat(lineHistory,param);
	
	//OPenning history file
	FILE* history = fopen("history.txt","a+");
	
	//Openning sucess
	if(history != NULL)
	{
		fprintf(history,"%s\n", lineHistory);
		
		fclose(history), history = NULL;
		
	}
	else
	{
		printf("ERREUR");
	}
	
	//Free the memory
	free(lineHistory);	
	
}

// use for have a random number
int alea(int a, int b)
{
	srand(time(NULL));//seeds the random number generator used by the function rand.
	int nb=rand()%b+a;
	return nb;
}

//Used to select an image based on the random number. 
char* picImg(char* pathImg)
{
	char *nameImg;
	char **tabImg;
	
	int nbImg=0;
	int nbAlea=0;
	
	//Dynamic allocation of tabImg, tab of char*
	tabImg = (char**)malloc(10*(sizeof(char*)));
	
	//Struct containing information about directory
	struct dirent *contenuRep;
	DIR *rep;
	
	//open a  directory
	rep = opendir(pathImg);
	
	if(rep == NULL)
	{
		printf("Openning rep failed");
	}
	
	//Scan the repertory containing the PBM files
	while((contenuRep = readdir(rep)) != NULL)
	{
		//Ignore the parent repertory and the current repertory
		if(strcmp(contenuRep->d_name, ".") == 0 || strcmp(contenuRep->d_name, "..") == 0){}
			
		else
		{
			//Place names file in tabImg
			tabImg[nbImg]=(contenuRep->d_name);
			nbImg++;
		}		
	}
	
	//Closing directory
	closedir(rep);
	
	//Pic a random number
	nbAlea = alea(0,nbImg);
	
	//Pic a PBM file random
	nameImg = tabImg[nbAlea];
	
	//Free memory
	free(tabImg);
	
	return nameImg;
}

//use for start a specific screensaver
void start(char* nameExec, char* param)
{
	int pid=-1;
	char* pathExec;
	
	//Get the path of the exec
	pathExec = getenv("EXIASAVER_HOME");
	strcat(pathExec, nameExec);
	
	//Create a processus
	pid = fork();
	
	switch(pid)
	{
		case -1:
			printf("Processus creation failed");
			break;
		case 0:
			execl(pathExec,nameExec,param,(char*)NULL); //run the program
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

void printHistory()
{
	system("clear");
	FILE *f;
	char line[200];
	
	//Opening file for reading
	f = fopen("history.txt" , "r");
	
	if(f == NULL) 
	{
      perror("Error opening file");
	}
	
	//Write the file on the console line per line
	while((fgets(line, 200, f)) != NULL)
	{	
			printf("%s",line);
	}
	
	//Closing file
	fclose(f);
}

//-----------------------------------------//
//			FUNCTIONS SAVER STATIC		   //
//-----------------------------------------//


//Charge a file in a child processus
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

//Recovery of magic numbers for the size of the image
void sizeImg(char *l, int *h, int *w)
{
	char *tmp;
	
	//Cut the string
	tmp = strtok(l, " ");
	
	*w = atoi(tmp);
	
	tmp = strtok(NULL, " ");
	
	*h = atoi(tmp);
}

//Function to center the image horizontally 
void printHorizontal(char *l, size_t wei)
{
	//Get the lenght of the string
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
		
		switch (l[y])//Displays an ascii character based on the ascii code
		{
			case 48://0
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
//Center vertically image
void center(int hMax, int *h) 
{
	if(hMax >= *h)
	{
		int n = (hMax - *h)/2;
		
		for(int i=0; i<n; i++)//Created a return to the line in order to descend on the ordinate
		{
			printf("\n");
		}
	}
	else
	{
		printf("Image trop grande");
	}
	
}
//-----------------------------------------//
//			FUNCTIONS SAVER INTERACTIF 	   //
//-----------------------------------------// 

//Struct containing the gravity center coordo of the plane
typedef struct coordo coordo;
struct coordo
{
	int A;	//abs, column
	int O;	//ordo, line
		
};

void positionInit(char *param, int *abs, int *ordo)
{
	char *tmp;
	
	//Separating param: aXb
	tmp = strtok(param,"X");
	
	//a in ordo
	*ordo = atoi(tmp);
		
	tmp = strtok(NULL,"X");
	
	//b in abs
	*abs = atoi(tmp);
}

void fonction_Init(coordo* coordo, int li, int col)
{
	coordo->A=col;
	coordo->O=li;	
}

void moveRight(coordo* coordo)
{
	coordo->A++;
}

void moveLeft(coordo* coordo)
{
	coordo->A--;
}

void moveDown(coordo* coordo)
{
	coordo->O++;
}

void moveUp(coordo* coordo)
{
	coordo->O--;
}

