#include <stdio.h>
#include "Fonction.h"
int main() {
    COLUMN * colonne1;
    CDATAFRAME * cd;
    cd=(CDATAFRAME*)malloc(sizeof (CDATAFRAME));
    cd->tableau_de_col=(COLUMN**)malloc(sizeof (COLUMN));
    int condition=0,action;
    do {
        printf("----Menu CDataframe----\n");
        printf("1-Creation CDataframe\n");
        printf("2-Remplir CDataframe\n");
        printf("3-Afficher colonne CDataframe\n");
        printf("4-ajouter une colonne \n");
        printf("5-supprimer une colonne\n");

        printf("6-Fermer programme\n");
        scanf("%d",&action);
        switch (action)
        {
            case 1:
                printf("choisissez le nombre de colonne\n");
                int nb;
                scanf("%d",&nb);
                cd->nbcolonne =&nb;
                break;
            case 2:
                printf("cas 2\n");
                int nbcol = *cd->nbcolonne,i;
                printf("%d",nbcol);
                for (i=0;i<nbcol;i++){

                    int val;

                    cd->tableau_de_col[i]= create_column();
                    printf("Saisir le nombre de valeur a entrer\n");
                    scanf("%d",&val);
                    cd->tableau_de_col[i]=remplir_colonne(cd->tableau_de_col[i],val);








                }










                break;

            case 3:
                printf("");

                int temp;
                i= 0;
                temp=*cd->nbcolonne;
                for (i=0;i<temp;i++){
                    printf("Colonne %d : %s\n",i+1,cd->tableau_de_col[i]->Titre);
                    print_col(cd->tableau_de_col[i]);

                }

                 break;
           case 4:

               ;
                int chiffre = 0;
                *cd->nbcolonne+=1;
                printf("cic%d\n",*cd->nbcolonne);
                cd->tableau_de_col[*cd->nbcolonne-1]= create_column();
                printf("Saisir le nombre de valeur a entrer\n");
                scanf("%d",&chiffre);
                cd->tableau_de_col[i]=remplir_colonne(cd->tableau_de_col[i],chiffre);

                break;

                case 5:;
                         int numcol;
                         i=0;
                printf("Saisir numeros de colonne a supprimer \n");
                scanf("%d",&numcol);

                printf("%d   oooo %d\n",numcol,*cd->nbcolonne);

                if (numcol<*cd->nbcolonne-1){
                    for(i=numcol;i<*cd->nbcolonne-1;i++){
                        cd->tableau_de_col[i]=cd->tableau_de_col[i+1];
                        printf("i==%d\n",i);
                    }
                    delete_column( &cd->tableau_de_col[*cd->nbcolonne - 1]);
                }else{
                    delete_column( &cd->tableau_de_col[numcol]);
                    printf("ohlala");
                }

                    break;


            case 6:
                condition=1;
                break;

        }

    }while (condition==0);




    return 0;
}
