#ifndef BLINDTEST_H
#define BLINDTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct chanson {
    char nom_fichier[100];
    char titre[100];
    char artiste[100];
}chanson ;

typedef struct joueur {
    char nom[100];
    int score;
}joueur;

typedef struct listejoueurs{
    char nom[100];
    int meilleur_score;
    struct listejoueurs * suivant; 
}listejoueurs ;

void trim_newline(char*s);
void normalize_string(char *dest, const char *src);
int string_equals_normalized(const char *a, const char *b);
void play_song_excerpt_at(const char *filename, int start, int seconds);
void melanger_morceau(chanson *song, int count);
int load_songs(const char *filename,chanson*songs);
#endif