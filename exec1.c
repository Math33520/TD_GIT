#include <stdio.h>

int main() {
    int a = 2;
    int b = 2;
    float c;
    if (b==0) {
        printf("Division par zero impossible \n");
        return 1;
    }
    else{
         c=  a / b;  // crash / comportement indéfini
    }
    printf("%f\n", c);
    return 0;
}

// il n'y a pas de message d'erreur mais le programme plente car on divise par 0 cela est interdit 
