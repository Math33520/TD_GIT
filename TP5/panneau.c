#include <stdio.h>
#include "structure.h"

void saisirPanneau(Panneau *p)
{
    if (!p) return;

    printf("Largeur (mm) : ");
    scanf("%d", &p->largeur);

    printf("Longueur (mm) : ");
    scanf("%d", &p->longueur);

    printf("Epaisseur (mm) : ");
    scanf("%d", &p->epaisseur);

    printf("Type de bois (0=pin, 1=chene, 2=hetre) : ");
    scanf("%d", &p->bois);
}

void afficherPanneau(const Panneau *p)
{
    if (!p) return;

    printf("Panneau %d mm x %d mm x %d mm, bois code %d\n",
           p->largeur, p->longueur, p->epaisseur, p->bois);
}

float volumeMetreCube(const Panneau *p)
{
    if (!p) return 0.0f;

    float l = p->largeur / 1000.0f;
    float L = p->longueur / 1000.0f;
    float e = p->epaisseur / 1000.0f;
    return l * L * e;
}
