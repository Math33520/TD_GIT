# include <stdio.h>

int main() {
    int n ;
    int width;
    int max_height;
    char img[100][100];
    printf("Saisir une taille  n (5<=x<=10)");
    scanf("%d",&n);
    if (n<4 || n>11){
        printf("La taille entrez est pas dans l'intervalle demander ");
        scanf("%d",&n);
    }
    else{
        width = n *n ;
        max_height= 3*n-1;

    
}