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
int consommations[7];
void initialiser()
{
    for(int i=0;i<7;i++)
    {
        consommations[i]=0;
    }
}
void ajouterConsommation()
{
    int choixCategorie = 0;
    int quantite = 0;
    printf("\n Quelle categorie voulez-vous modifier \n");
    printf("1. Eau 💧\n");
    printf("2. Cafe ☕\n");
    printf("3. Bonbons 🍬\n");
    printf("4. Gateau 🍰\n");
    printf("5. Legumes 🥦\n");
    printf("6. Fruits 🍎\n");
    printf("7. Proteines 🍗\n");
    printf("Votre choix :");
    scanf("%d",&choixCategorie);
    if (choixCategorie < 1 || choixCategorie > 7)
    {
        printf("Choix invalide\n");
        return ;
    }
    printf("combien d'unite ajouter? :");
    scanf("%d",&quantite);
    consommations[choixCategorie-1]= consommations[choixCategorie-1] + quantite;
    printf("Consommation mise a jour.\n");

}
void afficheResume()
{
    printf("========== Resume du jour ==========\n");
    printf("Eau :%d\n",consommations[0]);
    printf("Cafe :%d\n",consommations[1]);
    printf("Bonbons :%d\n",consommations[2]);
    printf("Gateau :%d\n",consommations[3]);
    printf("Legumes :%d\n",consommations[4]);
    printf("Fruits :%d\n",consommations[5]);
    printf("Proteines :%d\n",consommations[6]);
    printf("====================================\n");
}