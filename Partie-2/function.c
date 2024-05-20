#include "Function.h"


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

void delete_column(COLUMN **col){


    (*col)->title=NULL;
    free((*col)->data);
    (*col)->data=NULL;
    free(*col);
    col=NULL;

}


void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){

    switch(col->column_type){

        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char**)col->data[i]);
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
void print_col(COLUMN *col){

    char *str;
    int i;
    printf("|Titre : %s |\n",col->title);
    for (i=0;i<col->size;i++){
        str=(char*) malloc(sizeof(char*));
        convert_value(col,i,str,150);
        printf("[%d]|\t%s\t|\n",i,str);
        str=NULL;
    }

}


COLUMN * choisir_type_column(char * str){
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

    scanf("%d",&a);
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

void supp_val(COLUMN *col){
    printf("Choisir la valeur a suppimer :\n");
    int i=0;
    switch(col->column_type){

        case INT:;
            int val;
            printf("1\n");
            scanf("%d",&val);
            while (*((int*)col->data[i])!=val){
                i++;

            }
            while(i<(col->size)-1){

                *((int*)col->data[i])=*((int*)col->data[i+1]);
                i++;
            }


            break;

        case STRING:;

            char * str= (char*)malloc(sizeof (char*));

            scanf("%s",str);
            int verif;
            verif=strcmp((char**)col->data[i],str);
            while (verif!=0){
                i++;
                verif=strcmp((char**)col->data[i],str);
            }

            while(i<(col->size)-1){
                *((char**)col->data[i])=*((char**)col->data[i+1]);
                i++;
            }
            break;

        case   FLOAT:;
            float f;
            scanf("%f",&f);
            while (*((float*)col->data[i])!=f){
                i++;
            }
            while(i<(col->size)-1){

                *((float*)col->data[i])=*((float*)col->data[i+1]);
                i++;
            }
            break;

        case CHAR:;
            char c;
            scanf(" %c",&c);
            while (*((char*)col->data[i])!=c){
                i++;
            }
            while(i<(col->size)-1){

                *((char*)col->data[i])=*((char*)col->data[i+1]);
                i++;
            }
            break;

        case UINT:;
            unsigned int un;
            scanf("%u",&un);
            while (*((unsigned int *)col->data[i])!=un){
                i++;
            }
            while(i<(col->size)-1){

                *((unsigned int*)col->data[i])=*((unsigned int *)col->data[i+1]);
                i++;
            }
            break;

        case DOUBLE:;
            double doubl;
            scanf("%lf",&doubl);
            while (*((double*)col->data[i])!=doubl){
                i++;
            }
            while(i<(col->size)-1){

                *((double*)col->data[i])=*((double*)col->data[i+1]);
                i++;
            }
            break;




    }
    col->size--;



}

int choose_col(CDATAFRAME * CD){


    char title[25];
    int t=0,ve;
    printf("Entrer le nom de la colonne dont vous voulez supprimer une valeur : \n");
    scanf("%s",title);
    for(t=0;t<CD->nb_colonne;t++){

        ve= strcmp(title,CD->colonne[t].title);
        if(ve==0){
            return t;


        }

    }


    printf("Colonne inexistante !\n");}


void sort(COLUMN*col,int sort_value){
    int i,j;
    if (sort_value==0){

        Quicksort(col,0,col->size-1);

    }

    else{
        switch (col->column_type){
            case INT :;
                int k;
                for(i=1;i<col->size;i++){
                    k=*((int*)col->data[i]);
                    j=i-1;
                    while(j>0 && *((int*)col->data[j])>k){
                        *((int*)col->data[j+1])=*((int*)col->data[j]);
                    }
                }
        }



    }
}
int Partition(COLUMN* col, int gauche, int droite ){
    int i,j;
    unsigned long long int temp,temp2;
    switch (col->column_type){
        case INT :;
            int pivot_int;
            pivot_int=*(int*)col->data[droite];
            printf("%d ",pivot_int);
            i=gauche-1;
            printf("banane\n");
            for(j=gauche;j<droite;j++){
                if (*(int*)col->data[j]<=pivot_int){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
    }



    return i+1;
}
void Quicksort(COLUMN* col, int gauche, int droite){
    int pi;
    if (gauche<droite){
        pi= Partition(col,gauche,droite);
        printf("pi== %d\n",pi);
        Quicksort(col,gauche,pi-1);
        printf("tg\n");
        Quicksort(col,pi+1,droite);


    }



}
void print_col_by_index(COLUMN*col){
    char *str;
    int i;
    printf("|Titre : %s |\n",col->title);
    for(i=0;i<col->size;i++){
        str=(char*) malloc(sizeof(char*));
        convert_value(col,col->index[i],str,150);
        printf("[%d]|\t%s\t|\n",i,str);
        str=NULL;
    }


}

void occure(COLUMN *col){
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
