#include "cdataframe.h"
#include "column.h"

COLUMN *create_column(ENUM_TYPE type, char *title){
    COLUMN * colonne;
    colonne=(COLUMN*) malloc(sizeof(COLUMN));
    colonne->title=(char *) malloc(sizeof(char *));
    colonne->title=title;

    colonne->column_type=type;
    colonne->data=(COL_TYPE**) malloc(sizeof(COL_TYPE**)*TAILLE_MAX);
    colonne->max_size=TAILLE_MAX;
    colonne->size=0;
    colonne->index=(unsigned long long int *) malloc(sizeof(unsigned long long int ));
    colonne->valid_index=0;
    colonne->sort_dir=0;

    return colonne;


}
int insert_value(COLUMN *col, void *value){

    if (col->size== col->max_size){
        col->data=(COL_TYPE**) realloc(col->data,col->max_size+TAILLE_MAX);
        col->max_size+=TAILLE_MAX;
    }

    switch(col->column_type){

        case INT:
            col->data[col->size] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->size])= *((int*)value);
            break;
        case CHAR:
            col->data[col->size] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;
        case UINT:
            col->data[col->size] = (unsigned int *) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->size])= *((unsigned int *)value);

            break;
        case FLOAT:
            col->data[col->size] = (float*) malloc (sizeof(float));
            *((float*)col->data[col->size])= *((float*)value);

            break;

        case DOUBLE:
            col->data[col->size] = (double *) malloc (sizeof(double));
            *((double *)col->data[col->size])= *((double *)value);

            break;
        case STRING:
            col->data[col->size] = (char**) malloc (sizeof(char*));
            *((char**)col->data[col->size])= *((char**)value);

            break;


    }
    col->index[col->size]=col->size;
    col->size++;
    return 1;
}
int choose_value(COLUMN *col){


    printf("Choisissez une valeur :\n");
    switch (col->column_type) {


        case INT:;
            int val;
            scanf("%d", &val);

            insert_value(col, &val);


            break;
        case CHAR:;
            char val_c;
            scanf( " %c", &val_c);
            insert_value(col, &val_c);



            break;
        case UINT:;
            unsigned int val_u;
            scanf("%u", &val_u);
            insert_value(col, &val_u);


            break;
        case FLOAT:;
            float val_f;
            scanf("%f", &val_f);
            insert_value(col, &val_f);

            break;

        case DOUBLE:;
            double val_d;
            scanf("%lf", &val_d);
            insert_value(col, &val_d);

            break;
        case STRING:;
            char *val_str= (char *)malloc(sizeof (char)) ;

            scanf("%s",val_str);
            insert_value(col, val_str);

            break;


    }


    return 1;
}


