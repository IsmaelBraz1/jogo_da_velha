#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "mylib.h"


main()
{
    int i = 0,j = 0,cont = 0,a = 0,sorteio, controle=0;
    char jogo[3][3];
    char user1[15], user2[15];
    char primeiro[15], segundo[15];
    char reiniciar;
    
    cleanmtrz(jogo);
    printf("Digite o nome do primeiro jogador: ");
    scanf(" %s", user1);
    setbuf(stdin, 0);
    printf("Digite o nome do segundo jogador: ");
    scanf(" %s", user2);
    setbuf(stdin, 0);

    srand(time(NULL));
    sorteio = (rand() % 2);
    if(sorteio == 0){
        //user1 começa
        printf("%s sera o primeiro a jogar com (X) e %s sera o segundo a jogar com (O).\n\n", user1,user2);
        for(a = 0; a<strlen(user1); a++){
        primeiro[a] = user1[a];
        setbuf(stdin, 0);
        }
        for(a = 0; a<strlen(user2); a++){
        segundo[a] = user2[a];
        setbuf(stdin, 0);
        }
    }else{
        //user2 começa
        printf("%s sera o primeiro a jogar com (X) e %s sera o segundo a jogar com (O).\n\n", user2,user1);
        for(a = 0; a<strlen(user2); a++){
        primeiro[a] = user2[a];
        setbuf(stdin, 0);
        }
        for(a = 0; a<strlen(user1); a++){
        segundo[a] = user1[a];
        setbuf(stdin, 0);
        }
    }
    system("pause");
    system("cls");

    for ( cont = 0; cont < 9; )
    {
        cont++;
        print_tabela(jogo);
        
        if(cont != 11){
            do{
            if(cont%2 != 0){
                printf("\nVez de %s (X). \n", primeiro);
            }else{
                printf("\nVez de %s (O).\n", segundo);
            }

            
            do
            {
                printf("Digite a linha: ");
                scanf("%d", &i);
                setbuf(stdin, 0);
                } while ((i > 3)||(i < 1));
    
                do{
                printf("Digite a coluna: ");
                scanf("%d", &j);
                setbuf(stdin, 0);
                } while ((j > 3)||(j < 1));

                
                if(cont%2 != 0){              
                    if (jogo[i-1][j-1] == ' ' )
                    {
                        jogo[i-1][j-1] = 'X';
                        controle = 0;
                        system("cls");
                    }else{
                        printf("\nessa posicao ja foi preenchida.\n");
                        controle = 1;
                    }
                }else{
                    if (jogo[i-1][j-1] == ' ' )
                    {
                        jogo[i-1][j-1] = 'O';
                        controle = 0;
                        system("cls");
                        
                    }else{
                        printf("\nessa posicao ja foi preenchida.\n");
                        controle = 1;
                    }
                    
                }
            } while(controle == 1);
        } 

        if(cont > 4)
        {
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
                print_tabela(jogo);
                printf("\nFIM DE JOGO.\n%s VENCEU!!\n\n", primeiro);
                do{
                printf("\nJogar novamente? (S/N): ");
                scanf("%c", &reiniciar); 
                setbuf(stdin, 0); 
                cont = reset(reiniciar, cont);
                cleanmtrz(jogo);
                }while (cont == 99);
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
                print_tabela(jogo);
                printf("\nFIM DE JOGO.\n%s VENCEU!!\n\n", segundo);
                do{
                printf("\nJogar novamente? (S/N): ");
                scanf("%c", &reiniciar);  
                setbuf(stdin, 0);
                cont = reset(reiniciar, cont);
                cleanmtrz(jogo);
                }while (cont == 99);
                
            }
        }           
        if(cont == 9){ 
            print_tabela(jogo);
            printf("\nO jogo empatou.\n");
            do{
                printf("\nJogar novamente? (S/N): ");
                scanf("%c", &reiniciar);
                setbuf(stdin, 0);  
                cont = reset(reiniciar, cont);
                cleanmtrz(jogo);
            }while (cont == 99);
        }       
    }
}
