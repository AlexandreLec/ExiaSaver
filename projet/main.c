#include <stdio.h>
#include <stdlib.h>

//SCREENSAVER STATIQUE STRUCTURES ET PROTOTYPES


//Structure associating a number for each PBM file
typedef struct PBM PBM {

    int chateau = 0;
    int exia = 1;
    int pinguin = 2;
    int poulet = 3;

};

//Linked list containing the PBM's bytes
typedef struct bytes bytes{

    int byte;
    struct bytes *nxt;

};
struct llist {

    struct bytes *first;


};

//Random choice between the different PBM files numbers
int aleaStruct_PBM (*PBM);

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



