#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include <stdlib.h>
#include "column.h"
#include <stdio.h>
#include <string.h>
#define REALSIZE 256


COLUMN * create_column();

void delete_column(COLUMN **);
void print_col(COLUMN*);
COLUMN *remplir_colonne(COLUMN* col,int x);



#endif