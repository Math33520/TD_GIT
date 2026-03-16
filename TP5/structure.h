#ifndef STRUCTURE
#define STRUCTURE

struct panneau {
    int la;
    int lg;
    int ep;
    char code[6];
};
void affichage_panneau(struct panneau p);
struct panneau creer_panneau(void);
int calculer_volume(struct panneau p);

#endif