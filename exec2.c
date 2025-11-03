#include <stdio.h>

int main() {
    int tab[5];
    
    for (int i = 0; i <5; i++) {
        tab[i] = i;  
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}
//aucun message d'erreur mais on cherche pour i des éléments allant jusqu'a 10 maisla taille du tableau est de 5 donc cela ne peut m'arracher on doit donc changer la valeur pour i dans la boucle ou changer le taille du tableau 