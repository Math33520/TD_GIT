#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        i ++;
        printf("%d\n", i);
    }
    return 0;
}
// boucle a l'infinie si on ne modifie pas la valeur de i dans la boucle 