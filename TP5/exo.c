#include <stdio.h>
#include "structure.h"

struct panneau creer_panneau(void) {
    struct panneau p;

    printf("Largeur (mm) : ");
    scanf("%d", &p.la);

    printf("Longueur (mm) : ");
    scanf("%d", &p.lg);

    printf("Epaisseur (mm) : ");
    scanf("%d", &p.ep);

    printf("Type de bois (pin / chene / hetre) : ");
    scanf("%s", p.code);

    return p;
}

void affichage_panneau(struct panneau p) {
    printf("Panneau : %d x %d x %d mm | Bois : %s\n",
           p.la, p.lg, p.ep, p.code);
}

int calculer_volume(struct panneau p) {
    return p.la * p.lg * p.ep;
}