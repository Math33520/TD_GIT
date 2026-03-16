#include <stdio.h>
#include <stdlib.h>

int main() {
    int ville1[3], ville2[3];                                                             
    int i, j;
    int stable1 = 1, stable2 = 1;
    printf("Ville 1\n");
    printf("Temperature matin : ");
    scanf("%d", &ville1[0]);
    printf("Temperature midi : ");
    scanf("%d", &ville1[1]);
    printf("Temperature soir : ");
    scanf("%d", &ville1[2]);
    printf("\nVille 2\n");
    printf("Temperature matin : ");
    scanf("%d", &ville2[0]);
    printf("Temperature midi : ");
    scanf("%d", &ville2[1]);
    printf("Temperature soir : ");
    scanf("%d", &ville2[2]);
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (abs(ville1[i] - ville1[j]) > 5) {
                stable1 = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (abs(ville2[i] - ville2[j]) > 5) {
                stable2 = 0;
            }
        }
    }
    if (stable1 && !stable2) {
        printf("\nLa ville 1 est plus stable.\n");
    } 
    else if (!stable1 && stable2) {
        printf("\nLa ville 2 est plus stable.\n");
    } 
    else if (stable1 && stable2) {
        printf("\nLes deux villes sont stables.\n");
    } 
    else {
        printf("\nAucune des deux villes n'est stable.\n");
    }

    return 0;
}

