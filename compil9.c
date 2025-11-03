#include <stdio.h>

int main() {
    char s[7] = "Hello";
    printf("%s\n", s);
    return 0;
}
//./compil9.c:4:17: warning: initializer-string for array of chars is too long
//char s[3] = "Hello";
// l'erreur était qu'il y avait pas assez de place dans le tableau pour l'elemnt hello il fallit augmenter la taille du tableau