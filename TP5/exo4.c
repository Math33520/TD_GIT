#include <stdio.h>

int sommeTableau(int tab[], int taille, int *min, int *max) {
    if (tab == NULL || min == NULL || max == NULL || taille <= 0) {
        return 0;
    }

    int somme = 0;
    *min = tab[0];
    *max = tab[0];

    for (int i = 0; i < taille; i++) {
        somme += tab[i];

        if (tab[i] < *min) {
            *min = tab[i];
        }
        if (tab[i] > *max) {
            *max = tab[i];
        }
    }

    return somme;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};
    int taille = 5;
    int min, max;

    printf("Elements a sommer : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }

    int somme = sommeTableau(tab, taille, &min, &max);

    printf("\nLa somme est : %d\n", somme);
    printf("le min est : %d - le max est : %d\n", min, max);

    return 0;
}
