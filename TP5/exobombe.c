#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coupeFil(int *fil, int *timer, int filCorrect)
{
    int filChoisi = *fil;

    if (filChoisi == filCorrect)
    {
        *fil = 1;
        return 1;
    }
    else
    {
       
        *timer = *timer - 10;

       
        *fil = 0; 
        return 0;
    }
}


void tourneLaClef(int *code, int *bouclier)
{
    int key = *code;

    if (key % 2 == 0)
        *bouclier = 1; 
    else
        *bouclier = 0; 
}


void recalageTimer(int *timer, const int *bouclier)
{
    if (*bouclier == 1)
        *timer = *timer + 5;
    else
        *timer = *timer - 5;
}


int verificationCode(const int *code)
{
    int n = *code;
    int somme = 0;

    if (n < 0) n = -n;
    if (n == 0) somme = 0;

    while (n > 0)
    {
        somme += (n % 10);
        n /= 10;
    }

    return (somme == 10) ? 1 : 0;
}

int desamorcageFinal(const int *timer, const int *filEtat, const int *bouclier, const int *code)
{
    int tempsOK = (*timer > 0);
    int filOK = (*filEtat == 1);
    int bouclierOK = (*bouclier == 1);
    int codeOK = verificationCode(code);

    if (tempsOK && filOK && bouclierOK && codeOK)
        return 1;
    return 0;
}

void afficherEtat(const int *timer, const int *fil, const int *code, const int *bouclier)
{
    printf("Etat -> timer=%d s | fil=%d | code=%d | bouclier=%d\n",
           *timer, *fil, *code, *bouclier);
}

int main(void)
{
    int timer;  
    int fil;          
    int code;        
    int bouclier;    
    int filACouper;   

    srand((unsigned)time(NULL));
    filACouper = (rand() % 4) + 1; 

    printf("=== Simulation de desamorçage ===\n");

    printf("Entrez le timer initial (en secondes) : ");
    scanf("%d", &timer);

    do {
        printf("Choisissez un fil a couper (1 a 4) : ");
        scanf("%d", &fil);
    } while (fil < 1 || fil > 4);

    printf("Entrez le code numerique : ");
    scanf("%d", &code);

    bouclier = 0;

    printf("\n--- Etat initial ---\n");
    afficherEtat(&timer, &fil, &code, &bouclier);


    printf("\n--- Module : Tourne-la-clef ---\n");
    tourneLaClef(&code, &bouclier);
    afficherEtat(&timer, &fil, &code, &bouclier);

    printf("\n--- Module : Recalage du timer ---\n");
    recalageTimer(&timer, &bouclier);
    afficherEtat(&timer, &fil, &code, &bouclier);

    printf("\n--- Module : Verification du code ---\n");
    printf("Code valide ? %s\n", verificationCode(&code) ? "OUI" : "NON");
    afficherEtat(&timer, &fil, &code, &bouclier);

    printf("\n--- Module : Coupe-fil ---\n");
    printf("(Debug) Fil correct a couper = %d\n", filACouper);
    printf("Bon fil coupe ? %s\n", coupeFil(&fil, &timer, filACouper) ? "OUI" : "NON");
    afficherEtat(&timer, &fil, &code, &bouclier);

    printf("\n--- Module : Desamorcage final ---\n");
    if (desamorcageFinal(&timer, &fil, &bouclier, &code))
        printf(" Bombe DESAMORCEE !\n");
    else
        printf(" ECHEC : la bombe EXPLOSE (ou n'est pas desamorcee) !\n");

    return 0;
}
