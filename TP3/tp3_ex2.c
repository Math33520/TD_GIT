#include <stdio.h>
#include <stdlib.h>

#define TAILLE 3

void initialiser_plateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = ' ';
        }
    }
}

void afficher_plateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf(" %c ", plateau[i][j]);
            if (j < TAILLE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < TAILLE - 1) {
            printf("---+---+---\n");
        }
    }
}

int verifier_victoire(char plateau[TAILLE][TAILLE], char symbole) {
    for (int i = 0; i < TAILLE; i++) {
        if (plateau[i][0] == symbole && plateau[i][1] == symbole && plateau[i][2] == symbole) {
            return 1;
        }
    }

    for (int j = 0; j < TAILLE; j++) {
        if (plateau[0][j] == symbole && plateau[1][j] == symbole && plateau[2][j] == symbole) {
            return 1;
        }
    }

    if (plateau[0][0] == symbole && plateau[1][1] == symbole && plateau[2][2] == symbole) {
        return 1;
    }

    if (plateau[0][2] == symbole && plateau[1][1] == symbole && plateau[2][0] == symbole) {
        return 1;
    }

    return 0;
}

int verifier_egalite(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (plateau[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int jouer_tour(char plateau[TAILLE][TAILLE], int joueur) {
    int ligne, colonne;
    char symbole = (joueur == 1) ? 'X' : 'O';

    printf("Joueur %d, entrez votre position (ligne colonne): ", joueur);

    if (scanf("%d %d", &ligne, &colonne) != 2) {
        printf("Erreur de saisie.\n");
        while (getchar() != '\n');
        return 0;
    }

    ligne--;
    colonne--;

    if (ligne < 0 || ligne >= TAILLE || colonne < 0 || colonne >= TAILLE) {
        printf("Position invalide.\n");
        return 0;
    }

    if (plateau[ligne][colonne] != ' ') {
        printf("Cette case est déjà prise.\n");
        return 0;
    }

    plateau[ligne][colonne] = symbole;
    return 1;
}

int main() {
    char plateau[TAILLE][TAILLE];
    int joueur_actuel = 1;
    int coup_joue = 0;
    int jeu_termine = 0;

    initialiser_plateau(plateau);

    // Premier affichage du plateau vide
    afficher_plateau(plateau); 

    while (!jeu_termine) {
        
        do {
            coup_joue = jouer_tour(plateau, joueur_actuel);
        } while (coup_joue == 0);

        // Affichage après un coup valide
        afficher_plateau(plateau);

        char symbole_joueur = (joueur_actuel == 1) ? 'X' : 'O';

        if (verifier_victoire(plateau, symbole_joueur)) {
            printf("Joueur %d gagne!\n", joueur_actuel);
            jeu_termine = 1;
        }
        else if (verifier_egalite(plateau)) {
            printf("Match nul! Égalité!\n");
            jeu_termine = 2;
        }
        else {
            joueur_actuel = (joueur_actuel == 1) ? 2 : 1;
        }
    }

    return 0;
}