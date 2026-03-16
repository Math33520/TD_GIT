#include <stdio.h>
#include "contact.h"

int ajouter_contact(struct Contact liste[], int nb) {
    if (nb >= MAX_CONTACTS) {
        printf("Liste pleine\n");
        return nb;
    }

    printf("Nom : ");
    scanf("%s", liste[nb].nom);

    printf("Prenom : ");
    scanf("%s", liste[nb].prenom);

    printf("Rue : ");
    scanf("%s", liste[nb].adresse.rue);

    printf("Ville : ");
    scanf("%s", liste[nb].adresse.ville);

    printf("Code postal : ");
    scanf("%d", &liste[nb].adresse.code_postal);

    printf("Telephone : ");
    scanf("%s", liste[nb].telephone);

    return nb + 1;
}

void afficher_contacts(struct Contact liste[], int nb) {
    int i;

    for (i = 0; i < nb; i++) {
        printf("Contact %d : %s %s, %s %s %d, Tel : %s\n",
               i,
               liste[i].nom,
               liste[i].prenom,
               liste[i].adresse.rue,
               liste[i].adresse.ville,
               liste[i].adresse.code_postal,
               liste[i].telephone);
    }
}

int rechercher_contact(struct Contact liste[], int nb, const char nom_recherche[]) {
    int i;

    for (i = 0; i < nb; i++) {
        if (strcmp(liste[i].nom, nom_recherche) == 0) {
            return i;
        }
    }
    return -1;
}

void modifier_contact(struct Contact liste[], int nb, int indice) {
    int choix;

    if (indice < 0 || indice >= nb) {
        printf("Indice invalide\n");
        return;
    }

    printf("1 - Modifier adresse\n");
    printf("2 - Modifier telephone\n");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Nouvelle rue : ");
        scanf("%s", liste[indice].adresse.rue);

        printf("Nouvelle ville : ");
        scanf("%s", liste[indice].adresse.ville);

        printf("Nouveau code postal : ");
        scanf("%d", &liste[indice].adresse.code_postal);
    }
    else if (choix == 2) {
        printf("Nouveau telephone : ");
        scanf("%s", liste[indice].telephone);
    }
}
