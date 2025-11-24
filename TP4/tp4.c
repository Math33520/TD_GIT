#include <stdio.h>

void affichemenu(){
    printf("====Gestion des notes ====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleur note de chaque controle\n");
    printf("0. Quitter\n");
}

int lirechoix()
{
    int choix;
    printf("Donnez votre choix parmis tout les nombres : ");
    scanf("%d",&choix);
    return choix;
}

int saisinombreeleves()
{
    int nbeleves;
    printf("saisir le nombre d'eleves de (1 a 30) : ");
    scanf("%d",&nbeleves);

    if (nbeleves < 1 || nbeleves > 30)
    {
        printf("\nValeur invalide\n");
        return saisinombreeleves();   
    }
    else
    {
        return nbeleves;
    }
}

void Saisinotes(float tab[][3], int nbeleves)
{
    printf("Saisie des notes pour %d eleves et 3 controles.\n", nbeleves);

    for (int i = 0; i < nbeleves; i++)
    {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("  Note du controle %d (0 a 20) : ", j + 1);
            scanf("%f", &tab[i][j]);
            while (tab[i][j] < 0 || tab[i][j] > 20)
            {
                printf("  Valeur invalide (0 a 20) : ");
                scanf("%f", &tab[i][j]);
            }
        }
    }
}
void affichernotes(int nbeleves,float tab[0][3])
{
    printf("Tableau des notes\nEleve C1 C2 C3\n");
    for(int i=0;i<nbeleves;i++)
    {
        printf("%d",i+1);
        for(int j = 0 ;j<3;j++)
        {
            printf("%4.0f",tab[i][j]);
        }
        printf("\n");
    
    }
}
float calculerMoyenneEleve(float tab[][3], int indiceEleve)
{
    float somme = 0.0f;
    for (int j = 0; j < 3; j++)
    {
        somme = somme + tab[indiceEleve][j];
    }
    return somme / 3.0f;
}
float calculerMoyenneGenerale(float tab[][3], int nbeleves)
{
    float sommeMoyennes = 0.0f;

    for (int i = 0; i < nbeleves; i++)
    {
        sommeMoyennes = sommeMoyennes + calculerMoyenneEleve(tab, i);
    }

    return sommeMoyennes / nbeleves;
}
int main()
{
    affichemenu();
    float tab[30][3];          
    int variable = lirechoix();
    int valeur = saisinombreeleves();
    Saisinotes(tab, valeur); 
    affichernotes(valeur,tab) ;
    int indice;
    printf("Entrez l'indice de l'eleve (1 a %d): ", valeur);
    scanf("%d", &indice);
    while (indice < 1 || indice > valeur)
    {
        printf("Indice invalide. Entrez l'indice de l'eleve (1 a %d): ", valeur);
        scanf("%d", &indice);
    }
    float moyenne = calculerMoyenneEleve(tab, indice - 1);
    printf("Moyenne de l'eleve %d: %.2f\n", indice, moyenne);
     float moyenneGenerale = calculerMoyenneGenerale(tab, valeur);
    printf("Moyenne generale de la classe: %.2f\n", moyenneGenerale);
    return 0;
}
