#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100

struct Patient {
    char nom[30];
    char prenom[30];
    int age;
    int numero_dossier;
};

int ajouter_patient(struct Patient liste[], int nb,
                    struct Patient nouveau);

void afficher_patients(struct Patient liste[], int nb);

#endif
