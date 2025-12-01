#include <stdio.h>
#include "tp5.h"
void afficherMenu()
{
    printf("==============================\n");
    printf("   Suivi de consommation\n");
    printf("==============================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvegarder et quitter\n");
    printf("Votre choix :");
}

int lireChoix()
{
    int choix;
    scanf("%d",&choix);
    return choix;
}
void initialiser()
{
    int consommations[7];
    for(int i=0;i<7;i++)
    {
        consommations[i]=0;
    }
}
void ajouterConsommation()
{
    int choixCategorie = 0;
    int quantite = 0;
    printf("\n Quelle categorie voulez")
}