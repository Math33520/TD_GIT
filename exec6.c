#include <stdio.h>

int main() {
    char nom[10];
    printf("Nom ? ");
    scanf("%s", nom); 
    printf("Bonjour %s\n", nom);
    return 0;
}
//la chaine de caractère de nom est trop petite il faut juste augmenter sa taille pour pouvoir y mettre un nom plus long