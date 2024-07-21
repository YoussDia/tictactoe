#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>



void afficheGrille(char grille[3][3]){
    printf("test grille :\n");
    for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("| %c |",grille[i][j]);
            }
        printf("\n");

    }
}
/* la fonction verifie la case jouer est dans la grille et si celle-ci est vide*/
int coupValide(char grille[3][3],int x,int y){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x>0 && x<4){
                if(y>0 && y<4){
                    if(grille[x-1][y-1]==' '){// j'enlève 1 aux possitions de la grille et les colonneset lignes de ma grille sont  indexé de 0à2 mais lorsque j'attribue les ligne et colonne mes valeur sont entre 1 et 3 compris
                        return 1;
                    }

                }
            }
            return 0;
        }
    }
}

void jouer(char grille[3][3],int x,int y,char c){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grille[x][y] = c;
        }
    }
}

 int victoire(char grille[3][3]){
    //verification des lignes
    for(int i=0;i<3;i++){
        if(grille[i][0]==grille[i][1] && grille[i][1] ==grille[i][2] && grille[i][0]!=' '){
            return 1;
        }
    }
    //verification des colonnes
    for(int j=0;j<3;j++){
        if (grille[0][j]==grille[1][j] && grille[1][j]==grille[2][j] && grille[0][j] !=' '){
            return 1;
        }
    }
    // verification des diagonales
    if (grille[0][0]==grille[1][1] && grille[1][1]==grille[2][2] && grille[0][0] !=' '){
        return 1;
    }
    if (grille[0][2]==grille[1][1] && grille[1][1]==grille[2][0] && grille[0][2] !=' '){
        return 1;
    }
    return 0;
}
void resultat(char grille[3][3],int coup){
    if(victoire(grille)&& coup%2 == 0){
        printf("Le joueur 2 remporte la partie !\n");
    }
    else if(victoire(grille)&& coup%2 != 0){
        printf("Le joueur 1 remporte la partie !\n");
    }
    else{
        printf("il y a egalité !");
    }
}

main(){
    int coup = 1; // designe le numero du tours de jeux
    int joueur;
    char signe;
    char maGrille[3][3] = {{' ',' ',' '},
                           {' ',' ',' '},
                           {' ',' ',' '}};
    afficheGrille(maGrille);

    while(!(victoire(maGrille))&& coup<10){

        if(coup%2!=0){
            signe = 'X';
            joueur = 1;

            }
            else{
                signe = 'O';
                joueur = 2;
            }
            printf("c'est au joueur %d de jouer\n veuillez choisir une ligne et une colonne !\n",joueur);
            int ligne;
            int colonne ;
            printf("ligne :\n");
            scanf("%d",&ligne);
            printf("colonne :\n");
            scanf("%d",&colonne);

            if (coupValide(maGrille,ligne,colonne)){
                    jouer(maGrille,ligne-1,colonne-1,signe); //j'enlève 1 car lorsque je rentre les valeurs des ligne et colonne je considère que mes ligne et colonnes sont indexé de 1à3 alors qu'il sont veritablement indexé de 0à2
                    coup ++;
            }
            else{
                printf("coup impossible veuillez ressayer !\n");

            }
            afficheGrille(maGrille);
        printf("coups :%d\n",coup-1);// j'enlève 1 au coup car dans la boucle while le coup est incrementer dès qu'un joueur joue, de cette manière j'ai le coup courant
    }
    resultat(maGrille,coup-1);
    Sleep(10000);
}
