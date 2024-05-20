//
// Created by tonyv on 16/05/2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 256
enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;
typedef struct{
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
}COLUMN;

typedef struct{
    COLUMN* colonne;
    int nb_colonne;



}CDATAFRAME;


COLUMN *create_column(ENUM_TYPE type, char *title);
int insert_value(COLUMN *col, void *value);
int choose_value(COLUMN *);
void delete_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_col(COLUMN *);
COLUMN * choisir_type_column(char * );




typedef struct {
    ENUM_TYPE type;
    COL_TYPE value;
} variable;







#endif //PROJET_PART2_FUNCTION_H
