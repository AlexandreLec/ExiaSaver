#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

//Size of the console 24 lines 80 columns
#define W_CONSOLE 80
#define H_CONSOLE 24

//Functions prototypes
FILE* chargeImg(FILE *descriptor, char *path, char *mode);
void printHorizontal(char *l, size_t wei);


int main (int argc, char *argv[])
{

while (1 == 1)
{

	//Descriptor file
	FILE* dessin = NULL;

	//Tab for bytes's line
	char line[W_CONSOLE];

	//Number of lines in the file
	//int lineNb = 1;
	//Image height
	int hei = 0;
	//Image weight
	int wei = 0;
	//Pointers on image size
	int *phei = &hei;
	int *pwei = &wei;

	system("clear"); //clean

	int i, j;
	int chrono;
	int sertarien = 0;


	for (i=1; i<9; i++)
	{
		char dupu[200] = {'\0'};
		char convert[2];
		char tabdate[3];
		char affichenum[255] = {'\0'};
		char pbm[6]={".pbm"};
		char chemin[255]={"/home/arnaud/Bureau/projet/image/"};
		strcat(dupu, "date +%T | cut -c ");
		sprintf(convert, "%d", i);
		strcat(dupu, convert);
		int lineNb = 1;

		FILE *  date;
		date = popen(dupu, "r");
		while (fgets(tabdate, sizeof tabdate,date)) //fgets lit tout ce qui ce trouve dans date (le flux) et le place dans tabdate (le 1er). le sizeof tabdate sert a dire le maximum de caractére lu (ici la taille d'un tableau de 256)
                	sertarien = sertarien;


		int qq = strlen(tabdate);
		for (j=1; j < qq; j++)
		{
			if (tabdate[j] = '\n')
				tabdate[j] = '\0';
		}

		strcat(affichenum, chemin);
		strcat(affichenum, tabdate);
		strcat(affichenum, pbm);
//		printf("%s \n", affichenum);
		dessin = fopen(affichenum, "r");

		while((fgets(line, sizeof line, dessin)) != NULL)
		{
			if(lineNb > 2)
			{
				printHorizontal(line, W_CONSOLE);
				printf("\n");
			}
			lineNb++;

		}

	} //for

//	char attente[255] = {"wait"};
	for (chrono = 10; chrono !=0; chrono--)
	{
		printf("cela va s\'actualiser dans %d seconde(s) \n", chrono);
		sleep(1);
	}

/* marche
	for(chrono = 10; chrono !=0; chrono--)
	{
		printf("cela va s'actualiser dans %d  seconde \n", chrono);
		sleep(1);
	}
*/
	fclose(dessin);
}//while
}//main

FILE* chargeImg(FILE *descriptor, char *path, char *mode)
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

	return descriptor;
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
		int c = l[y];
		switch (c)
		{
			case 48:
				printf(" ");
				break;

			case 49:
				printf("%c", 219);
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
