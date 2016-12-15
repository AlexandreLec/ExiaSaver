#include <stdio.h>
#include <stdlib.h>

typedef struct coordo coordo{

	int A1;
	int O1;

};

void fonction_Init(int coordo*);

void fonctionAffichage(int tabConsole[]);

int *tabConsole=NULL;



int main(int argc, char*argv[]){

	fontion_Init(*coordo);
	int tabConsole[6][6]={0};

	tabConsole[coordo->A1++][coordo->O1++]=1;
	fonctionAffichage(&tabConsole);
}



void fonction_Init(int coordo*){
	
	coordo->A1= 3;
	coordo->O1=3;

}

void fonctionAffichage(int tabConsole[]){

	int i;
	int j;

	for(i=0; i>6 ; i++){

	for(j=0; j>6 ; i++){

		tabConsole[i][j];
		
	if(tabConsole[i][j]==1){

	printf("X");

	}


			}

}

}




