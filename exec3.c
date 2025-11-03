#include <stdio.h>

int main() {
    int x = 0;
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}
// pas de message d'erreur mais x na pas de valeur défin ie donc il prend la valeur qu'il veut ce qui fausse le résultat, il faut donc modifier la valeur de x