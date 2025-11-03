#include <stdio.h>

int main() {
    float distance_km = 100;
    float vitesse_kmh = 50;
    float temps = distance_km / vitesse_kmh; 
    int minutes = (int)(temps * 60);
    printf("minutes = %d\n", minutes); 
    return 0;
}
// le problème ici est que l'on peut avoir un nombre qui n'est pas entier donc cela peux fausser le résultat