#include <stdio.h>
#include "patient.h"

int ajouter_patient(struct Patient liste[], int nb,
                    struct Patient nouveau) {
    liste[nb] = nouveau;
    return nb + 1;
}

void afficher_patients(struct Patient liste[], int nb) {
    int i;
    for (i = 0; i < nb; i++) {
        printf("Patient %d : %s %s, %d ans, dossier n°%d\n",
               i + 1,
               liste[i].nom,
               liste[i].prenom,
               liste[i].age,
               liste[i].numero_dossier);
    }
}
