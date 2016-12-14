//Functions prototypes for all saver

//-----------------------------------------//
//			COMMONS FUNCTIONS    		   //
//-----------------------------------------//

//Charging a file
FILE* chargeFile(FILE *descriptor, char *path, char *mode);

//-----------------------------------------//
//			FUNCTIONS EXIASAVER 		   //
//-----------------------------------------// 

//Pic a random number between a and b
int alea(int a, int b);

//Pic an image
char* picImg(char* pathImg);

//Execute a screensaver
void start(char* nameExec, char* param);

//Completing the history file
void history(char* type, char* param);

//Find the maximum of a tab
int max(int tab[], int sizeTab);

//Swap two cases in a tab
void swap(int tab[], int i, int y);

void triSelection(int tab[], int sizeTab);

//Print the history file
void printHistory();

//-----------------------------------------//
//			FUNCTIONS SAVER STATIC		   //
//-----------------------------------------// 

//Print centered horizontaly
void printHorizontal(char *l, size_t wei);

//Find the size of the image
void sizeImg(char *l, int *h, int *w);

//Print centered verticaly
void center(int hMax, int *h);

//-----------------------------------------//
//			FUNCTIONS SAVER INTERACTIF 	   //
//-----------------------------------------//

//Read the initial position give by user
void positionInit(char *param, int *abs, int *ordo);

//Place the gravity center of the plane at start
void fonction_Init(coordo* coordo, int li, int col); 

//Functions to move the plane
void moveRight(coordo* coordo);
void moveLeft(coordo* coordo);
void moveUp(coordo* coordo);
void moveDown(coordo* coordo);
