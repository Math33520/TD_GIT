#include <stdio.h>

int main() {
    int a;
    int b = 10;
    printf("%d\n", b);
    return 0;
}
//./compil3.c:5:5: error: 'b' undeclared (first use in this function)
//b = 10;
// oublie du int donc ne sais pas quoi attribuer comme type pour b donc il faut rajouter int pour dire entier comme la valeur est égale a 10