#include <stdio.h>

int somme_chiffres(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    int a, b;

    printf("Entrer deux nombres : ");
    scanf("%d %d", &a, &b);

    while (a != b)
    {
        if (a < b)
            a = a + somme_chiffres(a);
        else
            b = b + somme_chiffres(b);
    }

    printf("Point de rencontre : %d\n", a);

    return 0;
}
