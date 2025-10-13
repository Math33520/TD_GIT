#include  <stdio.h>
int main() {
    int totalSecondes;
    int heures, minutes, secondes;
    scanf("%d", &totalSecondes);
    heures = totalSecondes / 3600;             
    minutes = (totalSecondes % 3600) / 60;     
    secondes = totalSecondes % 60;             
    printf("%d secondes = %d heures, %d minutes et %d secondes",totalSecondes, heures, minutes, secondes);

    return 0;
}
