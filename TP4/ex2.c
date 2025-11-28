#include <stdio.h>

void afficherMenu()
{
    printf("=== BANQUE - DISTRIBUTEUR ===\n");
    printf("1 - Faire un retrait\n");
    printf("2 - Quitter\n");
}

int saisir_montant() {
    int montant;
    printf("Montant a retirer : ");
    scanf("%d", &montant);
    return montant;
}

int montant_valide(int montant) {
    if (montant < 5 || montant > 1000 || montant % 5 != 0) {
        printf("Erreur : montant invalide.\n");
        printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5.\n");
        return 0;
    }
    return 1;
}

void calcul_distribution(int montant) {

    int b50 = montant / 50;
    montant = montant % 50;

    int b20 = montant / 20;
    montant = montant % 20;

    int b10 = montant / 10;
    montant = montant % 10;

    int b5  = montant / 5;

    printf("Billets distribues :\n");
    if (b50 > 0) printf("%d billets de 50 euros\n", b50);
    if (b20 > 0) printf("%d billets de 20 euros\n", b20);
    if (b10 > 0) printf("%d billets de 10 euros\n", b10);
    if (b5  > 0) printf("%d billets de 5 euros\n",  b5);
}

int main() {
    int choix;
    int montant;

    afficherMenu();

    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        montant = saisir_montant();

        if (montant_valide(montant)) {
            calcul_distribution(montant);
        }
    }
    return 0;
}
