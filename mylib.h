#include <stdio.h>
#include <stdlib.h>

//function que imprime o tabela do jogo
char print_tabela(char jogo[3][3]){
        printf("        1     2     3 \n\n");
        printf("1       %c  |  %c  |  %c   \n", jogo[0][0], jogo[0][1], jogo[0][2]);      
        printf("      ------------------\n");
        printf("2       %c  |  %c  |  %c   \n", jogo[1][0], jogo[1][1], jogo[1][2]);
        printf("      ------------------\n");
        printf("3       %c  |  %c  |  %c   \n", jogo[2][0], jogo[2][1], jogo[2][2]);
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
                    printf("Opcao invalida. \n"); 
            }
            return(cont);
}
