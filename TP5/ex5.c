#include <stdio.h>

void modifierEcran(int *luminosite, int *contraste) {
    if (luminosite == NULL || contraste == NULL) {
        printf("Erreur : pointeur NULL\n");
        return;
    }

    printf("Valeurs actuelles :\n");
    printf("Luminosite : %d\n", *luminosite);
    printf("Contraste  : %d\n", *contraste);

    printf("\nNouvelle valeur de luminosite : ");
    scanf("%d", luminosite);

    printf("Nouvelle valeur de contraste : ");
    scanf("%d", contraste);
}

int main() {
    int luminosite = 50;
    int contraste = 50;

    printf("Avant modification :\n");
    printf("Luminosite = %d, Contraste = %d\n\n", luminosite, contraste);

    modifierEcran(&luminosite, &contraste);

    printf("\nApres modification :\n");
    printf("Luminosite = %d, Contraste = %d\n", luminosite, contraste);

    return 0;
}
