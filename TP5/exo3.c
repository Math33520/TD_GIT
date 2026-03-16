#include <stdio.h>

void echanger(int *a, int *b) {
    if (a == NULL || b == NULL) {
        printf("Erreur : pointeur NULL, echange impossible\n");
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("Entrez la valeur de x : ");
    scanf("%d", &x);

    printf("Entrez la valeur de y : ");
    scanf("%d", &y);

    printf("\nAvant l'echange : x = %d, y = %d\n", x, y);

    echanger(&x, &y);

    printf("Apres l'echange : x = %d, y = %d\n", x, y);

    return 0;
}
