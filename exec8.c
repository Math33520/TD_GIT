#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 0;
    printf("%d\n", t[i]); 
    return 0;
}
// le problème ici est que i était initialisé a -1 est en c cela n'est pas bon pour différente raison comme des calculs 