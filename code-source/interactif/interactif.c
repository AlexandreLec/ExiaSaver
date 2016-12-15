#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/home/alexandre/projet_c/functions.c"
#include "/home/alexandre/projet_c/functions.h"


//Print the area's plane
void fonctionAffichage(int tabConsole[23][80], coordo* coordo, int position);


int main(int argc, char* argv[]){

	//Clean the console
	system("clear");
	
	if(argc == 2)
	{
		//Definition of initial position of the gravity center
		int ordo=0;
		int abs=0;	
		
		int pos=0;
		
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
		
		fonctionAffichage(tabConsole,pavion_coordo,pos);

		printf("Commande ('x' pour sortir) :  ");
	
		//While char c is not x
		while((c=getchar())!=120)
		{
			switch(c)
			{
				//User press d
				case 100:
					moveRight(pavion_coordo);
					pos=1;
					break;
				//User press q
				case 113:
					moveLeft(pavion_coordo);
					pos=3;
					break;
				//User press z
				case 122:
					moveUp(pavion_coordo);
					pos=0;
					break;
				//User press s 
				case 115:
					moveDown(pavion_coordo);
					pos=2;
					break;
				//User press g
				case 103:
					moveLeft(pavion_coordo);
					pos=3;
					break;
				//User press h
				case 104:
					moveUp(pavion_coordo);
					pos=0;
					break;
				
				//User press b
				case 98:
					moveDown(pavion_coordo);
					pos=2;
					break;
		
			}
			printf("\n");
			system("clear");
			
			//Print plane to it new position
			fonctionAffichage(tabConsole,pavion_coordo,pos);
			
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


void fonctionAffichage(int tabConsole[23][80], coordo* coordo, int position)
{
	int i;
	int j;
	//Save the new coordo of the plane
	int x = coordo->O;
	int y = coordo->A;
	
	//Reinitialization of the plane area
	for(i = 0;i<23;i++)
	{
		for(j=0;j<80;j++)
		{
			
			tabConsole[i][j] = 0;

		}
	}
	
	//Char code in ascii for each byte of the PBM file
	int c=0;
	//Char in the PBM file
	int carac = 0;
	int cpt = 0;
	
	//Opening PBM file
	FILE *image;
	
	//Choose the PBM file
	if(position == 0)
	{
		image = fopen("/home/alexandre/projet_c/interactif/PBM/avion_h.PBM", "r");
	}
	if(position == 1)
	{
		image = fopen("/home/alexandre/projet_c/interactif/PBM/avion_d.PBM", "r");
	}
	if(position == 2)
	{
		image = fopen("/home/alexandre/projet_c/interactif/PBM/avion_b.PBM", "r");
	}
	if(position == 3)
	{
		image = fopen("/home/alexandre/projet_c/interactif/PBM/avion_g.PBM", "r");
	}
	
	if(image != NULL)
	{
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
					carac++;
					
				}
				else
				{
					carac++;
				}		
		}
	
	//Close the file
	fclose(image);
	
	}
	else 
	{
		sleep(5);
	}
	
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
