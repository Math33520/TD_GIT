#include <stdio.h>
#include "tp5.h"

int main ()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); 
    int choix = 0;
    int tab[7];
    int objectifs[7] = {8, 0, 0, 0, 5, 3, 2};

    if (charger(tab) == 0)
    {
        printf("Aucune sauvegarde trouvee.\n");
        initialiser(tab);
    }
    while (choix != 4)
    {
        afficherMenu();
        choix = lireChoix();
        if (choix == 1)
        {
            ajouterConsommation(tab);
        }
        else if (choix == 2)
        {
            afficheResume(tab);
        }
        else if (choix == 3)
        {
            afficherObjectifsEtScore(tab, objectifs);
        }
        else if (choix == 4)
        {
            printf("Sauvegarde et quitter\n");
            if (sauvegarde(tab))
                printf("Sauvegarde reussie.\n");
            else
                printf("Erreur sauvegarde.\n");
        }
        else
        {
            printf("Choix invalide.\n");
        }
    }
    return 0;
}
