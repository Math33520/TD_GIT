#include <stdio.h>
#include "tp5.h"

int main ()
{
    int choix = 0;
    char tab[7];
    while (choix !=3)
    {
        afficherMenu();
        choix = lireChoix();
        if (choix==1)
        {
            ajouterConsommation();
        }
        if(choix == 3 )
        {
            printf("Sauvegarde et quitter \n");
        }

    }
    return 0;
}