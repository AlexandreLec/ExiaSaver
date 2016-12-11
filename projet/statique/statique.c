#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define W_CONSOLE 80
#define H_CONSOLE 24

void affichage(char *l, size_t wei, size_t hei);


int main(int argc, char *argv[])
{

	FILE* dessin = NULL;
	char line[W_CONSOLE];
	int lineNb = 1;
	
	system("clear");

	if (argc == 2)
	{

		dessin = fopen(argv[1], "r");

		if(dessin==NULL)
		{
			printf("Ouverture impossible");
		}
		else
		{
			while((fgets(line, sizeof line, dessin)) != NULL)
			{
					
				if(lineNb > 2){
					
					affichage(line, W_CONSOLE);
					printf("\n");
					
				}
				lineNb++;
			}
		}
	}
	else
	{
		printf("Erreur d'argument");
	}
	
	fclose(dessin);
	
	return 0;
}

void affichage(char *l, size_t wei)
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
