
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
        system("clear"); //netoie l'invite

        int i;
        for (i=1; i<9; i++)
        {
                char dupu[200] = {'\0'};
                char convert[2];
                char tabdate[255];
                strcat(dupu, "date +%T | cut -c ");
                sprintf(convert, "%d", i);
                strcat(dupu, convert);

                FILE *  date;
                date = popen(dupu, "r");
                while (fgets(tabdate, sizeof tabdate,date)) //fgets lit tout ce qui ce trouve dans date (le flux) et le place dans tabdate (le 1er). le sizeof tabdate sert a dire le maximum de caractére lu (ici la taille d'un tableau de $
                        fputs(tabdate, stdout);
                //printf("%s", tabdate);
        }


        return 0;

}

//ce code permet d'afficher 1 a 1 les nombres/: de l'heure
// Par exemple si il est 16:23:55 on aura:
//1
//6
//:
//2
//3
//:
//5
//5
//il reste donc utiliser le prog statique pour afficher les bons fichiers pbm et aussi a definir la ou doivent se placer les fichiers aisni que faire l'algo d'agrandissement
