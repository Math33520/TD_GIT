#include <stdio.h>

int main() {
    int x = 10;
    printf("x = %d\n", x);
    return 0;
}
//./compil8.c:5:24: error: 'y' undeclared (first use in this function)
//printf("x = %d\n", y);
// y était placé au niveau du print alors que la valueur à afficher est x donc il faut remplacer le y par x