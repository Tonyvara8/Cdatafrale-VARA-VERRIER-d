#include "cdataframe.h"








void delete_column(COLUMN **col){
///Supprimer une colonne.

    (*col)->title=NULL;
    free((*col)->data);
    (*col)->data=NULL;
    free(col);


}


void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
///Passer une valeur de type quelconque en STR pour pouvoir l'afficher simplement.
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
///Afficher les colonnes.
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
    ///Choisir le type de données d'une colonne.
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
    ///Supprimer une valeur d'une colonne.
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
///Choisir une colonne sur laquelle agir.

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
    int i=0,j=0;
    unsigned long long int temp,temp2;
    switch (col->column_type){
        case INT :;
            int pivot_int;
            pivot_int=*(int*)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
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
            break;
        case FLOAT:;
            float pivot_float;
            pivot_float=*(float*)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
                if (*(float *)col->data[j]<=pivot_float){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
        break;
        case UINT:;
            unsigned long long int pivot_un;
            pivot_un=*(unsigned long long int*)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
                if (*(unsigned long long int*)col->data[j]<=pivot_un){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
            break;
        case CHAR :;
            char pivot_ch;
            pivot_ch=*(char*)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
                if (*(char*)col->data[j]<=pivot_ch){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
            break;
        case DOUBLE:;
            double pivot_db;
            pivot_db=*(double*)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
                if (*(double*)col->data[j]<=pivot_db){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
            break;
        case STRING:;
            char *str=(char *) malloc(sizeof(char*)) ;
            int temp;
            str=(char**)col->data[droite];
            i=gauche-1;
            for(j=gauche;j<=droite;j++){
                temp= strcmp((char**)col->data[j],str);
                if (temp<=0){
                    i++;
                    temp=col->index[j];
                    col->index[j]=col->index[i];
                    col->index[i]=temp;
                }
            }

            temp2=col->index[i+1];
            col->index[i+1]=col->index[droite];
            col->index[droite]=temp2;
            break;


    }



return i+1;
}
void Quicksort(COLUMN* col, int gauche, int droite){
    int pi;
    if (gauche<droite){
        pi= Partition(col,gauche,droite);
        Quicksort(col,gauche,pi-1);

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
