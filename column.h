#ifndef COLUMN_H
#define COLUMN_H

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
int insert_value(COLUMN* , int );


int nb_occurence(COLUMN*,int );
int val_par_pos(COLUMN*,int);
int nb_valeur_sup(COLUMN*,int x);
int nb_valeur_inf(COLUMN*,int);

#endif