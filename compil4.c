#include <stdio.h>

int main (){
    printf("Test\n");
    return 0;
}
//./compil4.c:3:10: error: expected '=', ',', ';', 'asm' or '__attribute__' before '{' token
// int main {
//pour que cela fonctionne il faut ajouter les parenthèses après main pour indiquer que c'est une fonction 