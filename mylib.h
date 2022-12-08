#include <stdio.h>
#include <stdlib.h>

//function que imprime o tabela do jogo
char print_tabela(char jogo[3][3], char primeiro[15], int pont1, int pont2, char segundo[15]){
        printf("\t        1     2     3 \n\n");
        printf("\t1       %c  |  %c  |  %c   \n", jogo[0][0], jogo[0][1], jogo[0][2]);      
        printf("\t      ------------------\n");
        printf("\t2       %c  |  %c  |  %c            |%s %d x %d %s|\n", jogo[1][0], jogo[1][1], jogo[1][2], primeiro, pont1, pont2, segundo);
        printf("\t      ------------------\n");
        printf("\t3       %c  |  %c  |  %c   \n", jogo[2][0], jogo[2][1], jogo[2][2]);
}
//function para limpar a matriz
char cleanmtrz(char mtz[3][3]){
    int a,b;
    for (a = 0; a < 3; a++){
        for ( b = 0; b < 3; b++){
            mtz[a][b] = ' ';
        }
    }
    return(mtz[3][3]);
}
//function para reiniciar ou encerrar o jogo
int reset(char reiniciar, int cont){   
    int control;
            switch(reiniciar)
            {
                case 's':
                    cont = 0;
                    system("cls");
                    break;
                case 'S':
                    cont = 0;
                    system("cls");
                    break;
                case 'n':
                    cont = 11;
                    system("cls");
                    break;
                case 'N':
                    cont = 11;
                    system("cls");
                    break;
                
                default:
                    cont = 99;
                    printf("\tOpcao invalida. \n"); 
            }
            return(cont);
}

char resultado(char jogo[3][3]){
if(
                //vencedor fechando uma linha horizontal
                ((jogo[0][0] == 'X') && (jogo[0][1] == 'X') && (jogo[0][2] == 'X'))||   
                ((jogo[1][0] == 'X') && (jogo[1][1] == 'X') && (jogo[1][2] == 'X'))||   
                ((jogo[2][0] == 'X') && (jogo[2][1] == 'X') && (jogo[2][2] == 'X'))||   
                //vencedor fechando uma linha diagonal
                ((jogo[0][0] == 'X') && (jogo[1][0] == 'X') && (jogo[2][0] == 'X'))||   
                ((jogo[0][1] == 'X') && (jogo[1][1] == 'X') && (jogo[2][1] == 'X'))||   
                ((jogo[0][2] == 'X') && (jogo[1][2] == 'X') && (jogo[2][2] == 'X'))||   
                //vencedor fechando uma linha transversal
                ((jogo[0][0] == 'X') && (jogo[1][1] == 'X') && (jogo[2][2] == 'X'))||  
                ((jogo[0][2] == 'X') && (jogo[1][1] == 'X') && (jogo[2][0] == 'X'))
                )
                {
                    return(1);
                }
                if(
                //vencedor fechando uma linha horizontal
                ((jogo[0][0] == 'O') && (jogo[0][1] == 'O') && (jogo[0][2] == 'O'))||
                ((jogo[1][0] == 'O') && (jogo[1][1] == 'O') && (jogo[1][2] == 'O'))||
                ((jogo[2][0] == 'O') && (jogo[2][1] == 'O') && (jogo[2][2] == 'O'))||
                //vencedor fechando uma linha diagonal
                ((jogo[0][0] == 'O') && (jogo[1][0] == 'O') && (jogo[2][0] == 'O'))|| 
                ((jogo[0][1] == 'O') && (jogo[1][1] == 'O') && (jogo[2][1] == 'O'))|| 
                ((jogo[0][2] == 'O') && (jogo[1][2] == 'O') && (jogo[2][2] == 'O'))||
                //vencedor fechando uma linha transversal
                ((jogo[0][0] == 'O') && (jogo[1][1] == 'O') && (jogo[2][2] == 'O'))||
                ((jogo[0][2] == 'O') && (jogo[1][1] == 'O') && (jogo[2][0] == 'O'))
                )
                {  
                   return(2);
                }

}
