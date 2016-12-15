#include "/home/alexandre/projet_c/functions.c"
#include "/home/alexandre/projet_c/functions.h"

//Size of the console 24 lines
#define H_CONSOLE 24

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
		int refresh;
		
		refresh = atoi(argv[1]);

		for (i=1; i<9; i++)
		{
			char dupu[200] = {'\0'};
			char convert[2];
			char tabdate[3];
			char affichenum[255] = {'\0'};
			char pbm[6]={".pbm"};
			char *chemin;
			
			chemin = getenv("EXIASAVER2_PBM");
			
			strcat(dupu, "date +%T | cut -c ");
			sprintf(convert, "%d", i);
			strcat(dupu, convert);
			int lineNb = 1;


			FILE *  date;
			date = popen(dupu, "r");
			
			while (fgets(tabdate, sizeof tabdate,date))
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
		
		for (chrono = refresh; chrono !=0; chrono--)
		{
			sleep(1);
			printf("."); //for each incrementation a "." it's charge
			fflush(stdout); // same 1st
		}

		fclose(dessin); //free memory
	}//while
}//main
