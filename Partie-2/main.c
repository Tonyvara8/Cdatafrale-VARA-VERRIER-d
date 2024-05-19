
#include "Function.h"



int main() {
    int sortie=0;
    int temp;
    CDATAFRAME *CD;
    while (sortie==0){
        printf("\n-----Choisissez ce que vous voulez faire : -----\n");
        printf("1) Creer un CDATAFRAME \n");
        printf("2) Creer et Remplir une colonne\n");
        printf("3) Afficher colonne\n");
        printf("4) Inserer valeur dans une colonne\n");


        printf("8) Quitter \n");
        scanf("%d",&temp);


        switch (temp) {

            case 1 :    //Creer un CDataframe

                CD=(CDATAFRAME *) malloc(TAILLE_MAX*sizeof (CDATAFRAME));
                CD->colonne=(COLUMN*) malloc(sizeof(COLUMN)*2);
                CD->nb_colonne=0;
                printf("CDATAFRAME creer !\n");



            case 2:   // Creer et remplir une colonne
                ;

                COLUMN* col=NULL;
                char* str=(char *) malloc(sizeof (char)*25);
                printf("Choisir nom de la colonne :\n");
                scanf("%s",str);
                col=choisir_type_column(str);
                CD->colonne[CD->nb_colonne]=*col;
                printf("Combien de valeur voulez vous ajouter ?\n");
                int nb,i;
                scanf("%d",&nb);
                for(i=0;i<nb;i++){
                    choose_value(&(CD->colonne[CD->nb_colonne]));
                }

                CD->nb_colonne++;
                break;


            case 3:;      //Afficher les colonnes


                int j;
                for (j=0;j<CD->nb_colonne;j++){
                    print_col(&(CD->colonne[j]));
                    printf("\n");

                }



                break;


            case 4:;       // Ajouter une valeur


            int nb_col;
            printf("Sélectionner numéros de la colonne\n",CD->nb_colonne);
                //scanf("%d",nb_col);
                choose_value(&(CD->colonne[0]));
                printf("Valeur ajoute !");
                break;
            case 8:
                sortie = 1;
                break;
        }


    }

    return 0;
}
