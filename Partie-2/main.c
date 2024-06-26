
#include "cdataframe.h"



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
        printf("5) Supprimer une valeur de la colonne\n");
        printf("6) Supprimer une colonne\n");
        printf("7) Trier la colonne et l'afficher\n");
        printf("8) Trouver les occurences d'une valeur dans le tableau\n");

        printf("9) Quitter \n");
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
                nb_col= choose_col(CD);
                choose_value(&(CD->colonne[nb_col]));
                printf("Valeur ajoute !\n");
                if (CD->colonne[nb_col].valid_index==1){
                    CD->colonne[nb_col].valid_index=-1;

                }
                break;



            case 5:;   // Supprimer valeur dans une colonne
                int ind;
                ind= choose_col(CD);
                supp_val(&CD->colonne[ind]);
                break;
            case 6:;    // Supprimer une colonne dans le cdataframe
            int indice;
            indice= choose_col(CD);
            if (indice!=CD->nb_colonne-1){
            for(i=indice;i<CD->nb_colonne-1;i++){
                CD->colonne[i]=CD->colonne[i+1];

            }}

                print_col(&CD->colonne[CD->nb_colonne-1]);
            delete_column(&CD->colonne[CD->nb_colonne-1]);
            CD->nb_colonne--;
            break;




            case 7:;       //trier et afficer les valeurs d'une colonne au travers de l'index
                int y;
                y= choose_col(CD);
                sort(&CD->colonne[y],CD->colonne[y].sort_dir);

                print_col_by_index(&CD->colonne[y]);
                break;
            case 8:;        // compter le nombre d'occurrence d'une valeur dans la colonne
                int nbcol;
                nbcol=choose_col(CD);
                occure(&(CD->colonne[nbcol]));
                break;
            case 9:         // fermer le programme
                sortie = 1;
                break;
        }


    }

    return 0;
}
