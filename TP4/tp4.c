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
int main()
{
    affichemenu();
    return 0;
}