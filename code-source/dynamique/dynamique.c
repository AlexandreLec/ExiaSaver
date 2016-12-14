#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

//Size of the console 24 lines 80 columns
#define H_CONSOLE 24

//Functions prototypes


int main (int argc, char *argv[])
{

while (1 == 1)
{

        system("clear"); //clean


	//Descriptor file
	FILE* dessin = NULL;
	int w_console = 10;
	//Tab for bytes's line
	char line[w_console];

	//Number of lines in the file
	//int lineNb = 1;
	//Image height
	int hei = 0;
	//Image weight
	int wei = 0;
	//Pointers on image size
	int *phei = &hei;
	int *pwei = &wei;

	int i, j;
	int chrono;

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
                	continue;


		int qq = strlen(tabdate);
		for (j=1; j < qq; j++) //use for remplace \n by \0
		{
			if (tabdate[j] = '\n')
				tabdate[j] = '\0';
		}

		strcat(affichenum, chemin);
		strcat(affichenum, tabdate);
		strcat(affichenum, pbm);
		dessin = fopen(affichenum, "r"); //all paths for one number
		while((fgets(line, sizeof line, dessin)) != NULL)
		{

			if(lineNb > 2)
			{
				printHorizontal(line, w_console); //print 1 lines
				printf("\n"); // go under previous lines
			}
			lineNb++;
		}

	} //for

	//The refresh timer
	printf("Cet écran sera actualisé dans quelques secondes ");
	fflush(stdout); //without printf not displayed
	for (chrono = 3; chrono !=0; chrono--)
	{
		sleep(1);
		printf("."); //for each incrementation a "." it's charge
		fflush(stdout); // same 1st
	}

	fclose(dessin); //free memory


}//while
}//main