#include <stdio.h>
#include <string.h>
int main() {
    char mot[] = "ordinateur"; // mot à deviner
    char devine[20];
    int erreurs = 0;
    int trouve = 0;
    int i;
    
    char *pendu[] = {
        "\n\n\n\n\n\n\n-------\n",
        "\n |\n |\n |\n |\n |\n |\n-------\n",
        " -------\n |     |\n |\n |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |     |\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |    /|\\\n |\n |\n-------\n",
        " -------\n |     |\n |     O\n |    /|\\\n |    / \\\n |\n-------\n"
    };

    for (i = 0; i < strlen(mot); i++) {
        devine[i] = '_';
    }
    devine[i] = '\0';

    printf("Bienvenue dans le jeu du pendu !");

    while (erreurs < 6 && !trouve) {
        printf("%s\n", pendu[erreurs]);
        printf("Mot : %s\n", devine);
        printf("Lettre : ");
        char lettre;
        scanf(" %c", &lettre);

        int bonne_lettre = 0;
        for (i = 0; i < strlen(mot); i++) {
            if (mot[i] == lettre && devine[i] == '_') {
                devine[i] = lettre;
                bonne_lettre = 1;
            }
        }

        if (!bonne_lettre) {
            erreurs++;
        }

        if (strcmp(mot, devine) == 0) {
            trouve = 1;
        }
    }

    if (trouve) {
        printf("Bravo ! Tu as trouve le mot ");
    } else {
        printf("%s", pendu[6]);
        printf("Dommage Le mot etait : %s", mot);
    }

    return 0;
}