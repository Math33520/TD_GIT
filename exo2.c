#include <stdio.h>
#include <math.h>
int main() {
    float M = 0;
    int c;
    int t;
    int n;
    printf("Entrez le montant du pret , le nombre d'annees et le taux d'interet :");
    scanf("%d", &c);
    printf("Nombre d'annees :");
    scanf("%d", &t);
    printf("Taux d'interet :");
    scanf("%d", &n);
    float var = (c*(t/12.0));
    float var1 = (1+t/12.0);
    float var3 = 1-pow(var1, -n*12);
    M = (float)var/(float)var3;
    printf("Le montant de la mensualite est de %f", M);
    return 0;
}
