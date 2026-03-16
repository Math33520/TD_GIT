
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;
    p = malloc(sizeof(int));

    if (p == NULL)
    {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }
    *p = 42;

    printf("Adresse du pointeur (p) : %p\n", (void*)p);
    printf("Valeur stockee (*p) : %d\n", *p);
    printf("Taille du pointeur (p) : %lu octets\n", sizeof(p));
}