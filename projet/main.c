#include <stdio.h>
#include <stdlib.h>


struct PBM {

    int chateau = 0;
    int exia = 1;
    int pinguin = 2;
    int poulet = 3;

};

struct bytes {

    int byte;
    struct bytes *nxt;

};
struct llist {

    struct bytes *first;


};

int aleaStruct_PBM (*struct PBM);
*FILE ouverture(int image);
llist remplissage (*FILE);
void affichage (llist);




typedef struct image image {

   *FILE avion_H;
   *FILE avion_B;
   *FILE avion_G;
   *FILE avion_D;
}
typedef struct avionLoc avionLoc{//sauvegarde de la position précèdente

    char actual;
    char next ;

}
typedef struct coordoAvion coordoAvion{

    int A1;
    int O1;
    ...
    int A11;
    int O11;

}

int tabConsole [80][23];

image chargeImage(image);
coordoAvion remplissageAvion(image , *coordoAvion );
void remplissageTAB(*coordoAvion , *tabConsole);
int deplacement(*avionLoc , *coordoAvion);
void affichage(*tabConsole);



