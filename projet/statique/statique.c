#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	FILE* dessin = NULL;
	int caractereLu;
	int line = 0;
	
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
			while((caractereLu = fgetc(dessin)) != EOF)
			{
					
				if(line > 9){
					switch(caractereLu)
					{
						case 48:
							printf(" ");
							break;
						case 10:
							printf("\n");
							break;
						case 49:
							printf("X");
							break;
					}
				}
				else{
					line++;
				}
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
