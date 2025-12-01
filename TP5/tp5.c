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
    scanf("%d", &choix);
    return choix;
}
void initialiser(int tab[])
{
    for (int i = 0; i < 7; i++)
    {
        tab[i] = 0;
    }
}
void ajouterConsommation(int tab[])
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
    scanf("%d", &choixCategorie);
    if (choixCategorie < 1 || choixCategorie > 7)
    {
        printf("Choix invalide\n");
        return;
    }
    printf("Combien d'unites ajouter ? :");
    scanf("%d", &quantite);
    tab[choixCategorie - 1] = tab[choixCategorie - 1] + quantite;
    printf("Consommation mise a jour.\n");
}
void afficheResume(int tab[])
{
    printf("========== Resume du jour ==========\n");
    printf("Eau       : %d\n", tab[0]);
    printf("Cafe      : %d\n", tab[1]);
    printf("Bonbons   : %d\n", tab[2]);
    printf("Gateau    : %d\n", tab[3]);
    printf("Legumes   : %d\n", tab[4]);
    printf("Fruits    : %d\n", tab[5]);
    printf("Proteines : %d\n", tab[6]);
    printf("====================================\n");
}
int sauvegarde(int tab[])
{
    FILE *f = fopen("consommation.txt", "w");
    if (f == NULL)
    {
        return 0;
    }
    for (int i = 0; i < 7; i++)
    {
        fprintf(f, "%d ", tab[i]); 
    }
    fprintf(f, "\n");

    fclose(f);
    return 1;
}

int charger(int tab[])
{
    FILE *f = fopen("consommation.txt", "r");
    if (f == NULL)
    {
        return 0;
    }

    for (int i = 0; i < 7; i++)
    {
        if (fscanf(f, "%d", &tab[i]) != 1)
        {
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}
