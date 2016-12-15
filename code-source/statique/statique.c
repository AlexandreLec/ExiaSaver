#include "/home/alexandre/projet_c/functions.c"
#include "/home/alexandre/projet_c/functions.h"

//Size of the console 24 lines 80 columns
#define W_CONSOLE 80
#define H_CONSOLE 24


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
		
		dessin = chargeFile(dessin, argv[1], "r");

		//Reading the PBM file line per line and print it in the console
		while((fgets(line, sizeof line, dessin)) != NULL)
		{
			if(lineNb == 2)
			{
				//Find the sizes of the PBM
				sizeImg(line, phei, pwei);
				
				//Center verticaly
				center(H_CONSOLE, phei);
				
				lineNb++;
			}
				
			if(lineNb > 2){
				
				//Center horiaontaly
				printHorizontal(line, W_CONSOLE);
				printf("\n");
				lineNb++;	
			}
			else
			{
				lineNb++;
			}
			
		}
		center(H_CONSOLE, phei);
		
		//Closing the file
		fclose(dessin);
		
	}
	else
	{
		printf("Erreur d'argument");
	}
	
	//Freeze the screen until user type on a key
	system("stty cbreak -echo");
	getchar();
	system("stty cooked echo");
	system("clear");
	
	return 0;
}
