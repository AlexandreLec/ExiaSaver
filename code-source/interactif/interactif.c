#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/home/alexandre/projet_c/functions.c"
#include "/home/alexandre/projet_c/functions.h"


//Print the area's plane
void fonctionAffichage(int tabConsole[23][80], coordo* coordo, char *position);


int main(int argc, char* argv[]){

	//Clean the console
	system("clear");
	
	if(argc == 2)
	{
		//Definition of initial position of the gravity center
		int ordo=0;
		int abs=0;	
		
		int *pOrdo = &ordo;
		int *pAbs = &abs;
		
		//Area's plane
		int tabConsole[23][80]={{0},{0}};
		//Command entered
		char c;
		
		positionInit(argv[1],pOrdo, pAbs);
		
		coordo avion_coordo;
		coordo *pavion_coordo = &avion_coordo;
		
		fonction_Init(pavion_coordo, ordo, abs);
		
		fonctionAffichage(tabConsole,pavion_coordo,"avion_b");
		printf("Commande ('x' pour sortir) :  ");
	
		//While char c is not x
		while((c=getchar())!=120)
		{
			switch(c)
			{
				//User press d
				case 100:
					moveRight(pavion_coordo);
					break;
				//User press q
				case 113:
					moveLeft(pavion_coordo);
					break;
				//User press z
				case 122:
					moveUp(pavion_coordo);
					break;
				//User press s 
				case 115:
					moveDown(pavion_coordo);
					break;
				//User press g
				case 103:
					moveLeft(pavion_coordo);
					break;
				//User press h
				case 104:
					moveUp(pavion_coordo);
					break;
				
				//User press b
				case 98:
					moveDown(pavion_coordo);
					break;
		
			}
			printf("\n");
			system("clear");
			
			//Print plane to it new position
			fonctionAffichage(tabConsole,pavion_coordo,"avion_b");
			
			printf("Commande ('x' pour sortir) : ");
		}
		system("clear");
	}
	else
	{
		printf("Erreur d'argument");
	}
	return 0;
}


void fonctionAffichage(int tabConsole[23][80], coordo* coordo, char *position)
{
	int i;
	int j;
	int x = coordo->O;
	int y = coordo->A;
	
	tabConsole[x][y]=1;
	
	FILE *image;
	char* path;
	char c;
	int carac = 0;
	int cpt = 0;
	char tmp[2];
	
	path=getenv("EXIASAVER3_PBM");
	
	strcat(path,position);
	strcat(path,".PBM");
	
	image = fopen("/home/alexandre/projet_c/interactif/avion_b.PBM", "r");
	
	while((c=fgetc(image)) != EOF)
	{
		if(carac < 6)
		{
			carac++;
		}
		if(carac > 5)
		{
			sprintf(tmp,"%c",c);
			tabConsole[x][y] = atoi(tmp);
			printf("%d", tabConsole[x][y]);
			
			if(cpt < 6)
			{
				x++;
				cpt++;
			}
			else
			{
				y++;
				cpt = 0;
			}
		}
	}
	
	fclose(image);
	
	/*for(i = 0;i<23;i++)
	{
		for(j=0;j<80;j++)
		{
			if(tabConsole[i][j] == 1)
			{
				printf("%c",219);
			}
			if(tabConsole[i][j] == 0)
			{
				printf(" ");
			}
		}
	}
	tabConsole[x][y]=0;*/
}
