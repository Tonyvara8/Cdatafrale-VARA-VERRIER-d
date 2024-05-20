#include "Function.h"


COLUMN *create_column(ENUM_TYPE type, char *title){ ///creation d'une colonne
    COLUMN * colonne;
    colonne=(COLUMN*) malloc(sizeof(COLUMN));
    colonne->title=(char *) malloc(sizeof(char *)); ///allocation de l'espace memoire au titre de la colonne
    colonne->title=title;

    colonne->column_type=type;
    colonne->data=(COL_TYPE**) malloc(sizeof(COL_TYPE**)*TAILLE_MAX);   ///allocation de l'espace des valeurs
    colonne->max_size=TAILLE_MAX;
    colonne->size=0;
    colonne->index=NULL;

    return colonne;


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


int insert_value(COLUMN *col, void *value){
///insertion de valeures en fonction du type de la colonne.
    if (col->size== col->max_size){
        col->data=(COL_TYPE**) realloc(col->data,col->max_size+TAILLE_MAX);
        col->max_size+=TAILLE_MAX;
    }

    switch(col->column_type){

        case INT:       ///colonne de type INT, alors je peux entrer des entiers
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

    col->size++;
    return 1;
}

void delete_column(COLUMN **col){


    (*col)->title=NULL;         ///supprime le titre d'une colonne
    (*col)->data=NULL;          ///supprime les datas des colonnes
    free((*col)->data); ///libère la mémoire allouée aux données
    free(*col);         ///idem pour la colonne
    col=NULL;

}


void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
///fonction pour creer transformer les valeurs de la colonne en chaines de caractères dans un but d'affichage.
    switch(col->column_type){

        case INT:   ///si la colonne est de type INT
            snprintf(str, size, "%d", *((int*)col->data[i]));   ///On convertie cette valeur en STR
            break;
        case STRING:
            snprintf(str, size, "%s", (char**)col->data[i]);    ///idem a chaque fois
            break;
        case   FLOAT:
            snprintf(str, size, "%f", *((float *)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char *)col->data[i]));
            break;
        case UINT:
            snprintf(str, size, "%u", *((unsigned int  *)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size,"%lf",*((double*)col->data[i]));
            break;




    }





}
void print_col(COLUMN *col){ /// fonction permettant d'afficher une colonne.

    char *str;
    int i;
    printf("|Titre : %s |\n",col->title);
    for (i=0;i<col->size;i++){
        str=(char*) malloc(sizeof(char*));  ///definition d'un str comme tableau dynamique.
        convert_value(col,i,str,150);
        printf("[%d]|\t%s\t|\n",i,str);     /// affichage sous forme position->valeur->|. Ou chaque -> est une tabulation.
        str=NULL;
    }

}


COLUMN * choisir_type_column(char * str){   ///Choisir le type de la colonne.
    COLUMN * colonne;
    CDATAFRAME lol;

    int a;



    printf("Choisir type de colonne :\n");
    printf("1 -> Colonne d'entiers \n");
    printf("2 -> Colonne de caracteres \n");
    printf("3 -> Colonne de d'entiers uniquement posistif \n");
    printf("4 -> Colonne de chaines de caractères \n");
    printf("5-> Colonne de floats \n");
    printf("6-> Colonne de double \n");

    scanf("%d",&a); ///Creation de colonne en fonction de la saisie utilisateur. (Via switch case)
    switch(a){
        case 1:
            colonne=create_column(INT,str);


            break;
        case 2:
            colonne=create_column(CHAR,str);
            break;
        case 3:
            colonne=create_column(UINT,str);
            break;

        case 4:
            colonne=create_column(STRING,str);


            break;

        case 5:
            colonne=create_column(FLOAT,str);
            break;

        case 6:
            colonne=create_column(DOUBLE,str);

            break;



    }

    return colonne;

}
