#include <stdio.h> 

int main() {
    int n;
    int width;
    int max_height;
    char img[100][100];
    int mid;

    printf("Saisir une taille n (5<=n<=10): ");
    scanf("%d", &n);
    if (n < 4 || n > 11) {
        printf("La taille entree n'est pas dans l'intervalle demande.\n");
        scanf("%d", &n);
    }

    width = n * n;
    max_height = 3 * n - 1;

    // Initialisation
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = ' ';
        }
    }

    // Pointe
    mid = width / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width; j++) {
            int k = j - mid;
            if (k == -i || k == i) {
                img[i][j] = 'A';
            } else if (k > -i && k < i) {
                img[i][j] = 'S';
            }
        }
    }

    // Base de la pointe
    int left = mid - (n - 1);
    int right = mid + (n - 1);
    for (int j = 0; j < width; j++) {
        if (j < left || j > right) {
            img[n - 1][j] = '_';
        }
    }

    /* ========= ETAPE 5 : corps central de l'étoile ========= */
    for (int i = 0; i < n; i++) {
        int ligne  = n + i;           // juste sous la base pour i=0
        int gauche = i;               // les bords se rapprochent
        int droite = width - 1 - i;

        for (int j = 0; j < width; j++) {

            if (i == 0) {
                // 1ère ligne : "SSSSSSSSSSSSSSSSSSSSSSS"
                if (j == gauche || j == droite)
                    img[ligne][j] = '"';
                else if (j > gauche && j < droite)
                    img[ligne][j] = 'S';

            } else if (i == 1) {
                // 2ème ligne : 'VSSSSSSSSSSSSSSSSSSSSSV'
                if (j == gauche || j == droite)
                    img[ligne][j] = '\'';
                else if (j == gauche + 1 || j == droite - 1)
                    img[ligne][j] = 'V';
                else if (j > gauche + 1 && j < droite - 1)
                    img[ligne][j] = 'S';

            } else {
                // Lignes suivantes qui se rétrécissent : .SSSSSSSSSSS.
                if (j == gauche || j == droite)
                    img[ligne][j] = '.';
                else if (j > gauche && j < droite)
                    img[ligne][j] = 'S';
            }
        }
    }
    /* ======================================================= */

    // Affichage
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}
