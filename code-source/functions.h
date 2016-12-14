//Functions prototypes for all saver

//-----------------------------------------//
//			COMMONS FUNCTIONS    		   //
//-----------------------------------------//

FILE* chargeFile(FILE *descriptor, char *path, char *mode);

//-----------------------------------------//
//			FUNCTIONS EXIASAVER 		   //
//-----------------------------------------// 

int alea(int a, int b);
char* picImg(char* pathImg);
void start(char* nameExec, char* param);
void history(char* type, char* param);
int max(int tab[], int sizeTab);
void swap(int tab[], int i, int y);
void triSelection(int tab[], int sizeTab);
llist addStart(llist list, char* add);
void printList(llist list);

//-----------------------------------------//
//			FUNCTIONS SAVER STATIC		   //
//-----------------------------------------// 

void printHorizontal(char *l, size_t wei);
void sizeImg(char *l, int *h, int *w);
void center(int hMax, int *h);
