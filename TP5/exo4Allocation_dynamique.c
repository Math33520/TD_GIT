#include <stdio.h>
#include <stdlib.h>

#define PLAQUE_LEN 7

typedef struct {
    char plaque[PLAQUE_LEN + 1];
} Voiture;

typedef struct {
    int estOccupee;    
    Voiture* voiture;   
} Place;

Place* creerParking(int capacite) {
    Place* p = malloc(sizeof(Place) * capacite);
    if (p == NULL) exit(1);

    for (int i = 0; i < capacite; i++) {
        p[i].estOccupee = 0;
        p[i].voiture = NULL;
    }
    return p;
}

Voiture* creerVoiture() {
    Voiture* v = malloc(sizeof(Voiture));
    if (v == NULL) exit(1);

    printf("Plaque (%d caracteres) : ", PLAQUE_LEN);
    scanf("%7s", v->plaque);
    return v;
}

void garerVoiture(Place* parking, int capacite, int place, Voiture* v) {
    if (place < 1 || place > capacite) {
        printf("Place invalide.\n");
        free(v);
        return;
    }

    int i = place - 1;

    if (parking[i].estOccupee == 1) {
        printf("Place %d deja occupee.\n", place);
        free(v);
        return;
    }

    parking[i].estOccupee = 1;
    parking[i].voiture = v;
    printf("Voiture garee a la place %d.\n", place);
}
void sortirVoiture(Place* parking, int capacite, int place) {
    if (place < 1 || place > capacite) {
        printf("Place invalide.\n");
        return;
    }

    int i = place - 1;

    if (parking[i].estOccupee == 0) {
        printf("Aucune voiture a la place %d.\n", place);
        return;
    }

    printf("Voiture %s sortie de la place %d.\n", parking[i].voiture->plaque, place);

    free(parking[i].voiture);
    parking[i].voiture = NULL;
    parking[i].estOccupee = 0;
}
void afficherParking(Place* parking, int capacite) {
    printf("\nEtat du parking :\n");
    for (int i = 0; i < capacite; i++) {
        if (parking[i].estOccupee == 1) {
            printf("Place %d : %s\n", i + 1, parking[i].voiture->plaque);
        } else {
            printf("Place %d : libre\n", i + 1);
        }
    }
    printf("\n");
}
void libererParking(Place* parking, int capacite) {
    for (int i = 0; i < capacite; i++) {
        if (parking[i].voiture != NULL) {
            free(parking[i].voiture);
        }
    }
    free(parking);
}

int main() {
    int capacite, choix, place;

    printf("Entrez la capacite du parking : ");
    scanf("%d", &capacite);

    Place* parking = creerParking(capacite);

    do {
        printf("1. Garer une voiture\n");
        printf("2. Retirer une voiture\n");
        printf("3. Afficher l'etat du parking\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Numero de place (1-%d) : ", capacite);
            scanf("%d", &place);

            Voiture* v = creerVoiture();
            garerVoiture(parking, capacite, place, v);
        }
        else if (choix == 2) {
            printf("Numero de place (1-%d) : ", capacite);
            scanf("%d", &place);

            sortirVoiture(parking, capacite, place);
        }
        else if (choix == 3) {
            afficherParking(parking, capacite);
        }

    } while (choix != 4);

    libererParking(parking, capacite);
    return 0;
}
