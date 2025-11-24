# include <stdio.h>

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
    printf("Donnez votre choix parmis tout les nombresc : ");
    scanf("%d",&choix);
    return choix;
}
    int saisinombreeleves()
{
    int nbeleves;
    printf("saisir le nombre d'eleves de (1 a 30) : ");
    scanf("%d",&nbeleves);
    if (nbeleves<1 || nbeleves>30)
    {
        printf("\nValeur invalide ");
        saisinombreeleves();
    }
    else{
        return nbeleves;
    }

}
int main()
{
    affichemenu();
    int variable = lirechoix();
    int valeur = saisinombreeleves();
    printf("\n Vous avez choisi l'option :%d",variable);
    printf("\n nombre d'eleves :%d",valeur);
    return 0;
}