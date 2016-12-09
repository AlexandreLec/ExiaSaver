#include <stdio.h>
#include <stdlib.h>

//LAUNCHER EXIASAVER STRUCTURES ET FONCTIONS

//Structure associating a number for each different screenSaver
typedef struct screenSaver screenSaver {

    int statique = 1;
    int dynamique = 2;
    int interactif = 3;

};

//Structure associating a number for each PBM file
typedef struct PBM PBM {

    int chateau = 0;
    int exia = 1;
    int pinguin = 2;
    int poulet = 3;

};

//Random choice between the different PBM files numbers
int aleaStruct(struct);


//SCREENSAVER STATIQUE STRUCTURES ET PROTOTYPES

//Linked list containing the PBM's bytes
typedef struct bytes bytes{

    int byte;
    struct bytes *nxt;

};
struct llist {

    struct bytes *first;


};

//Open the PBM file
*FILE ouverture(int image);

//Put the PBM's bytes in the linked list
llist remplissage (*FILE);

//Print the linked list centered on the screen
void affichage (*llist);


//SCREENSAVER INTERACTIF STRUCTURES ET PROTOTYPES

typedef struct image image {

   *FILE avion_H;
   *FILE avion_B;
   *FILE avion_G;
   *FILE avion_D;
}

//save previous and actual plane position
typedef struct avionLoc avionLoc{

    char actual;
    char next ;

}

//Coordinates for each part of the plane
typedef struct coordoAvion coordoAvion{

    int A1;
    int O1;
    ...
    int A11;
    int O11;

}

//Static tab who cover all the console
int tabConsole [80][23];

//Charge path image and save it in the structure image
image chargeImage(*image, path_image);

//Complete the plane coordinate structure with the bytes of the PBM file
coordoAvion remplissageAvion(image , *coordoAvion);

//Complete the static tab with the coordinate plane structure
void remplissageTAB(*coordoAvion , *tabConsole);

//Change the coordinates of the planes for move it
int deplacement(*avionLoc, *coordoAvion);

//Print to the screen tabConsole containing the plane
void affichage(*tabConsole);




//SCREENSAVER DYNAMIQUE STRUCTURES ET PROTOTYPES

 int tabConsole[80][23];

typedef struct chiffres chiffres {//struct with pointer on number file

    *FILE chiffer_un;
    *FILE chiffer_deux;
    *FILE chiffer_trois;
    *FILE chiffer_quatre;
    *FILE chiffer_cinq;
    *FILE chiffer_six;
    *FILE chiffer_sept;
    *FILE chiffer_huit;
    *FILE chiffer_neuf;
};

typedef struct taillesChiffres taillesChiffres{// size of number ex: 5X3 7x4

    int x;
    int y;

}

//Dynamic tab that store the PPM's bytes
int **tabChiffres;

tabchiffres= malloc(x*(sizeof (*ptr)));
tabChiffres[i]= malloc(y * (sizeof(**ptr)));

//Read the time and store it into a string char
char readTime ();

//Load a number
void charge(*chiffres);

//Complete the PPM's bytes in tabChiffres
void remplissageTab(chiffres , *tabChiffres);

//Complete the tabConsole with tabChiffres
void remplissageTabConsole(*tabChiffre , *tabConsole);

//Print the time
void affichage (*tabConsole);






