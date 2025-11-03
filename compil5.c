#include <stdio.h>

int main() {
    char c = 'A';
    printf("c = %c\n", c);
    return 0;
}
// donne aucun message d'erreur mais il y a au niveau du print un %s alors qu'il faut un %c pour afficher un caractère