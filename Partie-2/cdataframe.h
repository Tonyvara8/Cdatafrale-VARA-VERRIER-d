//
// Created by tonyv on 16/05/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 256
#include "column.h"


typedef struct{
    COLUMN* colonne;
    int nb_colonne;



}CDATAFRAME;



void delete_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_col(COLUMN *);
void supp_val(COLUMN *);
COLUMN * choisir_type_column(char * );
int choose_col(CDATAFRAME*);
void sort(COLUMN* ,int );
int Partition(COLUMN* , int , int );
void Quicksort(COLUMN* , int , int );
void print_col_by_index(COLUMN*);
void occure(COLUMN *col);

typedef struct {
    ENUM_TYPE type;
    COL_TYPE value;
} variable;










#endif //PROJET_PART2_FUNCTION_H
