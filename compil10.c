#include <stdio.h>

int main() {
    int abc = 5;
    printf("%d\n", abc);
    return 0;
}
//./compil10.c:5:20: error: invalid suffix "abc" on integer constant
//printf("%d\n", 1abc);
//on ne peut commencer avec un chiffre devant abc donc il faut enlever le 1 devant abc ou le déplacer , mais pas devant 