#ifndef Fonction_H
#define Fonction_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define REALSIZE 256

typedef struct {
    int TaillePhysique;
    int TailleLogique;
    int *data;
    char *Titre;
}COLUMN;

typedef struct {
    int *nbcolonne;
    COLUMN ** tableau_de_col;
}CDATAFRAME;

COLUMN * create_column();
int insert_value(COLUMN* , int );
void delete_column(COLUMN **);
void print_col(COLUMN*);
COLUMN *remplir_colonne(COLUMN* col,int x);
int nb_occurence(COLUMN*,int );
int val_par_pos(COLUMN*,int);
int nb_valeur_sup(COLUMN*,int x);
int nb_valeur_inf(COLUMN*,int);



#endif