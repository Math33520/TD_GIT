#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherCartes(int *cartes, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%2d ", cartes[i]);

        if ((i + 1) % 13 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void melangerCartes(int *cartes, int taille) {
    if (cartes == NULL || taille <= 0) {
        return;
    }

    for (int i = 0; i < taille; i++) {
        int j = rand() % taille;   // nombre aleatoire entre 0 et 51

        int temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}

int main() {
    int cartes[52];

    /* Initialisation des cartes */
    for (int i = 0; i < 52; i++) {
        cartes[i] = i + 1;
    }

    srand(time(NULL));  // initialisation du generateur aleatoire

    printf("Jeu de cartes avant melange :\n");
    afficherCartes(cartes, 52);

    melangerCartes(cartes, 52);

    printf("Jeu de cartes apres melange :\n");
    afficherCartes(cartes, 52);

    return 0;
}
