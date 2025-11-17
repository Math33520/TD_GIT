# include <stdio.h>

int main() {
    int n ;
    int width;
    int max_height;
    char img;
    printf("Saisir une taille  n (5<=x<=10)");
    scanf("%d",n);
    if (n>11 & n <4){
        printf("La taille netrez est pas dans l'intervalle demander ");
    }
    else{
        width = n *n ;
        max_height= 3*n-1;

    }

}