#include <stdio.h>
#include <ctype.h>

int main() {
    char chaine[] = "hello";
    char *p = chaine;   // pointeur vers la chaine

    while (*p != '\0') {
        *p = toupper(*p);
        p++;            // on avance dans la chaine
    }

    printf("Chaine modifiee : %s\n", chaine);

    return 0; 
}
