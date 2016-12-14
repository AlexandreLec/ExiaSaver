#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordo coordo;
struct coordo
{
	int A1;
	int O1;

};

void fonction_Init( coordo* coordo);

void fonctionAffichage(int tabConsole[], coordo* coordo);

void moveRight(coordo* coordo);

void moveLeft(coordo* coordo);

void moveUp(coordo* coordo);
void moveDown(coordo* coordo);





int main(int argc, char* argv[]){

	system("clear");
	system("stty -icanon");
	coordo avion_coordo;
    coordo *pavion_coordo = &avion_coordo;
	fonction_Init(pavion_coordo);
	int tabConsole[5][5]={{0},{0}};
	char c;
	fonctionAffichage(*tabConsole,pavion_coordo);
	
	while((c=getchar())!=120)
	{
		switch(c)
		{
			case 100:
				moveRight(pavion_coordo);
				break;
			case 113:
				moveLeft(pavion_coordo);
				break;
			case 122:
				moveUp(pavion_coordo);
				break;
			case 115:
				moveDown(pavion_coordo);
				break;
		
		}
		printf("\n");
		system("clear");
		fonctionAffichage(*tabConsole,pavion_coordo);
	}
	return 0;
}



void fonction_Init(coordo* coordo)
{
        coordo->A1=2;
        coordo->O1=2;
}

void moveRight(coordo* coordo)
{
	coordo->O1=coordo->O1+1;
}

void moveLeft(coordo* coordo)
{
	coordo->O1=coordo->O1-1;
}

void moveDown(coordo* coordo)
{
	coordo->A1=coordo->A1+1;
}

void moveUp(coordo* coordo)
{
	coordo->A1=coordo->A1-1;
}


void fonctionAffichage(int tabConsole[], coordo* coordo)
{

	int i;
	int j;
	int x= coordo->A1;
	int y = coordo->O1;

	int compteur=0;
	
	tabConsole[x*5+y]=1;
	
	for(i=0; i<6 ; i++){
		
			for(j=0; j<6 ; j++){
			
				if(tabConsole[i*5+j]==0){
					printf("O");
					compteur=compteur+1;
				}

				if(tabConsole[i*5+j]==1){
					printf("%c", 219);
					compteur=compteur+1;
				}


				if(compteur==6){
					printf("\n");
					compteur=0;

				}
			} 
	}
	
	tabConsole[x*5+y]=0;
}
