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
int humeurBonbons(int n) {
    if (n<=3) return 0;
    if (n<=7) return 1;
    if (n<=12) return 2;
    return 3;
}
int humeurLegumes(int n) {
    if (n==0) return 0;
    if (n<=2) return 1;
    return 2;
}
int humeurFruits(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    return 2;
}
void afficheResume(int tab[])
{
    printf("========== Resume du jour ==========\n");
    printf("Eau       : %d 💧 ", tab[0]);
    afficherBarre(tab[0], 20);
    printf("\n");
    printf("Cafe      : %d ☕ ", tab[1]);
    afficherBarre(tab[1], 20);
    printf("\n");
    printf("Bonbons   : %d 🍬 ", tab[2]);
    int hb = humeurBonbons(tab[2]);
    if (hb == 0)      printf("😇 ");
    else if (hb == 1) printf("🙂 ");
    else if (hb == 2) printf("😬 ");
    else              printf("😈 ");
    afficherBarre(tab[2], 20);
    printf("\n");
    printf("Gateau    : %d 🍰 ", tab[3]);
    afficherBarre(tab[3], 20);
    printf("\n");
    printf("Legumes   : %d 🥦 ", tab[4]);
    int hl = humeurLegumes(tab[4]);
    if (hl == 0){
        printf("🎁 ");
    }
    else if (hl == 1)
    {
        printf("🙂 ");
    }
    else{
        printf("😎 ");
    }
    afficherBarre(tab[4], 20);
    printf("\n");
    printf("Fruits    : %d 🍎 ", tab[5]);
    int hf = humeurFruits(tab[5]);
    if (hf == 0){
        printf("😧 ");
    }
    else if (hf == 1){
        printf("🙂 ");
    }
    else{
        printf("😄 ");
    }
    afficherBarre(tab[5], 20);
    printf("\n");
    printf("Proteines : %d 🍗 ", tab[6]);
    afficherBarre(tab[6], 20);
    printf("\n");
    printf("====================================\n");
}
void afficherBarre(int valeur, int max)
{
    int casesPleines;
    if (max <= 0)
        max = 1;
    if (valeur < 0)
        valeur = 0;
    if (valeur > max)
        valeur = max;
    casesPleines = (valeur * 10) / max;
    for (int i = 0; i < 10; i++)
    {
        if (i < casesPleines)
            printf("█");
        else
            printf("░");
    }
}