#include <stdio.h>
#include <stdlib.h>

    int main (int argc, char*argv[])

    {
        FILE* fichier = NULL;
        int caractereActuel = 0;
        fichier = fopen("C:\ Users\ Jc\ Desktop\ CESI\ history", "r");

        if (fichier != NULL)
        {
            do

            {
                caractereActuel =fgetc(fichier);
                printf("%c", caractereActuel);

            } while (caractereActuel !=EOF);

            fclose(fichier);
        }
        return 0;
    }
            // Une fois le fgect a ouvert le fichier history , placé chaque ligne dans un tableau de val i
             // Ensuite lance une focntion tri qui tri chaque ligne du tableau et
