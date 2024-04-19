#include "Fonction.h"





COLUMN * create_column(){
    char titre[20];
    printf("Saisir le titre de la colonne");
    scanf("%s",titre);
    COLUMN * col = (COLUMN*) malloc((sizeof (COLUMN)));
    col->TaillePhysique=0;
    col->TailleLogique=0;
    col->data=NULL;
    col->Titre=(char *) malloc((strlen(titre)+1)*sizeof (char));
    strcpy(col->Titre,titre);
    return col;




}

int insert_value(COLUMN* col, int value){
    if (col->TaillePhysique >col->TailleLogique){
        col->data[col->TailleLogique]=value;
    }
    else {
        col->data=(int* ) realloc(col->data,REALSIZE);
        col->TaillePhysique+=256;
        col->data[0]=value;

    }
    col-> TailleLogique+=1;
    return 1;



}
COLUMN * remplir_colonne(COLUMN* col,int x){
    int i;
    for(i=0;i<x;i++){
        int val;
        printf("Saisir valeur\n");
        scanf("%d",&val);
        insert_value(col,val);


    }
    return col;



}
void delete_column(COLUMN **col){
    free(col);
    *col=NULL;


}
void print_col(COLUMN* col){
    int i,max;
    max=col->TailleLogique;
    for (i=0;i<max;i++){
        printf("[%d]\t%d\n",i,col->data[i]);
    }

}

int  nb_occurence(COLUMN* col,int x){
    int nb,i,max;
    nb=0;
    max=col->TailleLogique;

    for (i=0;i<max;i++){
        if (col->data[i] ==x){
            nb++;
        }
    }
   printf("Il y a %d occurrence de %d\n",nb,x);
    return nb;
}

int val_par_pos(COLUMN*col,int x){
    int pos;
    pos=0;
    if (x>= col->TailleLogique){
        printf("ERROR il n'y a pas assez de valeur");
    }
    printf("la valeur a la position %d est : %d \n",x,col->data[x]);
    return col->data[x];
}

int nb_valeur_sup(COLUMN*col,int x){
    int i,nb=0,max;
    max= col->TailleLogique;
    for (i=0;i<max;i++){
        if (col->data[i]>x){
            nb++;
        }
    }
    printf("Il y a %d valeurs plus grandes que %d\n",nb,x);
    return nb;
}

int nb_valeur_inf(COLUMN*col,int x){
    int i,nb=0,max;
    max= col->TailleLogique;
    for (i=0;i<max;i++){
        if (col->data[i]<x){
            nb++;
        }
    }
    printf("Il y a %d valeurs plus petites que %d\n",nb,x);
    return nb;

}
