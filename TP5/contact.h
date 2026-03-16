#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100

struct Adresse {
    char rue[60];
    char ville[40];
    int code_postal;
};

struct Contact {
    char nom[30];
    char prenom[30];
    struct Adresse adresse;
    char telephone[20];
};

int ajouter_contact(struct Contact liste[], int nb);
void afficher_contacts(struct Contact liste[], int nb);
int rechercher_contact(struct Contact liste[], int nb, const char nom_recherche[]);
void modifier_contact(struct Contact liste[], int nb, int indice);

#endif