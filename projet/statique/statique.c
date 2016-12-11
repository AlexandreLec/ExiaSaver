#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//Size of the console 24 lines 80 columns
#define W_CONSOLE 80
#define H_CONSOLE 24

//Functions prototypes
void printHorizontal(char *l, size_t wei);
void sizeImg(char *l, int *h, int *w);
void center(int hMax, int *h);
FILE* chargeImg(FILE *descriptor, char *path, char *mode);


int main(int argc, char *argv[])
{
	//Descriptor file
	FILE* dessin = NULL;
	
	//Tab for bytes's line
	char line[W_CONSOLE];	
	
	//Number of lines in the file
	int lineNb = 1;
	//Image height	 
	int hei = 0;
	//Image weight
	int wei = 0;
	//Pointers on image size
	int *phei = &hei;
	int *pwei = &wei;

	if (argc == 2)
	{
		//Remove all print on the console
		system("clear");
		
		dessin = chargeImg(dessin, argv[1], "r");

		if(dessin==NULL)
		{
			printf("Opening failed");
		}
		else
		{
			//Reading the PBM file line per line and print it in the console
			while((fgets(line, sizeof line, dessin)) != NULL)
			{
				//
				if(lineNb == 2)
				{
					sizeImg(line, phei, pwei);
					center(H_CONSOLE, phei);
				}
					
				if(lineNb > 2){
					
					printHorizontal(line, W_CONSOLE);
					printf("\n");	
				}
				lineNb++;
			}
			center(H_CONSOLE, phei);
		}
	}
	else
	{
		printf("Erreur d'argument");
	}
	
	fclose(dessin);
	
	system("stty cbreak -echo");
	getchar();
	system("stty cooked echo");
	system("clear");
	
	return 0;
}

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
				printf("X");
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
