#include "cdataframe.h"
#include "column.h"

COLUMN *create_column(ENUM_TYPE type, char *title){
    /// Création de colonne.
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
    ///Entrer une valeur dans une colonne.
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
///Choisir une valeur dans une colonne.

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
void occure(COLUMN *col){
    ///Trouver le nombre d'occurences d'un nombre dans une colonne.
    int i,occurence,size;
    int tab[TAILLE_MAX];
    size=col->size;
    variable *valeur;
    valeur->type=col->column_type;
    switch(valeur->type){
        case INT:
            printf("Saisir une valeur entiere : ");
            scanf("%d",valeur->value.int_value);
            break;
        case STRING:
            printf("Saisir une valeur de type string : ");
            scanf("%s",valeur->value.string_value);
            break;
        case   FLOAT:
            printf("Saisir une valeur flottante : ");
            scanf("%f",valeur->value.float_value);
            break;
        case CHAR:
            printf("Saisir une valeur de type caractere : ");
            scanf("%c",valeur->value.char_value);
            break;
        case UINT:
            printf("Saisir une valeur entiere : ");
            scanf("%u",valeur->value.uint_value);
            break;
        case DOUBLE:
            printf("Saisir une valeur double : ");
            scanf("%f",valeur->value.double_value);
            break;
    }
    for (i=0;i<size;i++){
        switch(valeur->type){
            case INT:
                if (col->data[i]->int_value==valeur->value.int_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
            case STRING:
                if (col->data[i]->string_value==valeur->value.string_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
            case   FLOAT:
                if (col->data[i]->float_value==valeur->value.float_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
            case CHAR:
                if (col->data[i]->char_value==valeur->value.char_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
            case UINT:
                if (col->data[i]->uint_value==valeur->value.uint_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
            case DOUBLE:
                if (col->data[i]->double_value==valeur->value.double_value){
                    tab[occurence]=i;
                    occurence++;
                }
                break;
        }
    }
    switch(valeur->type){
        case INT:
            printf("La valeur %d apparait %d fois aux positions ");
            for (i=0;i<occurence;i++){
                printf("%d",tab[i]);
            }
            printf("\n");
            break;
        case STRING:
            printf("La valeur %s apparait %d fois aux positions ");
            for (i=0;i<occurence;i++){
                printf("%d",tab[i]);
            }
            printf("\n");
            break;
        case   FLOAT:
            printf("La valeur %f apparait %d fois aux positions ");
            for (i=0;i<occurence;i++){
                printf("%d",tab[i]);
            }
            printf("\n");
            break;
        case CHAR:
            printf("La valeur %c apparait %d fois aux positions ");
            for (i=0;i<occurence;i++){
                printf("%d",tab[i]);
            }
            printf("\n");
            break;
        case UINT:
            printf("La valeur %u apparait %d fois aux positions ");
            for (i=0;i<occurence;i++){
                printf("%d",tab[i]);
            }
            printf("\n");
            break;
        case DOUBLE:
            printf("La valeur %f apparait %d fois aux positions");
            for (i=0;i<occurence;i++){
                printf(" [%d]",tab[i]);
            }
            printf(".\n");
            break;
    }
}

