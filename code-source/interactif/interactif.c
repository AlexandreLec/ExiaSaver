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
		
		fonctionAffichage(tabConsole,pavion_coordo,"avion_d");
		
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
	//Save the new coordo of the plane
	int x = coordo->O;
	int y = coordo->A;
	
	//tabConsole[x][y]=1;
	
	FILE *image=NULL;
	//path of the img
	char* path;
	//Char code in ascii for each byte of the PBM file
	int c;
	//Char in the PBM file
	int carac = 0;
	int cpt = 0;
	
	//Read the environnement variable
	path=getenv("EXIASAVER3_PBM");
	
	//Buld the path
	strcat(path,position);
	strcat(path,".PBM");
	
	//Opening PBM file
	image = fopen(path, "r");
	
	//Openning failed
	if(image == NULL)
	{
		printf("erreur");
		sleep(1);
	}
	
	//Read the file char per char
	while((c=fgetc(image)) != EOF)
	{
			
			if(carac > 6)
			{	
				//Complete the area plane tab with the PBM's bytes
				switch(c)
				{
					case 48:
						tabConsole[x][y] = 0;
						break;
					case 49:
						tabConsole[x][y] = 1;
						break;
					default:
						break;
				}
				
				if(cpt > 5)
				{
					x++;
					y=coordo->A;
					cpt=0;
				}
			
				else
				{
					y++;
					cpt++;
				}
					
			}
			else
			{
				carac++;
			}		
	}
	
	//Close the file
	fclose(image);
	
	//Print the tab into the console
	for(i = 0;i<23;i++)
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
}
