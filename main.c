#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "mylib.h"

main()
{
    int modo, vencedor;
    int i = 0, j = 0, cont = 0, a = 0, sorteio, controle = 0;
    char jogo[3][3];
    char user1[15], user2[15];
    char user3[15] = "Computador";
    char reiniciar;
    int pont1 = 0, pont2 = 0;

    do
    {
        printf("\n\t\tOPCOES DE JOGO\n\n\t1 - JOGAR COM UM AMIGO\n\t2 - JOGAR CONTRA A MAQUINA\n\t3 - SAIR\n\n\t=> ");
        scanf("%d", &modo);
        setbuf(stdin, NULL);
        system("cls");
        switch (modo)
        {
        case 1:
            pont1 = 0;
            pont2 = 0;
            cleanmtrz(jogo); // function para limpar a matriz
            printf("\n\tDigite o nome do primeiro jogador: ");
            gets(user1);
            setbuf(stdin, NULL);
            printf("\n\tDigite o nome do segundo jogador: ");
            gets(user2);
            setbuf(stdin, NULL);
            printf("\t%s ira jogar com 'X' e %s ira jogar com 'O'.\n\n", user1, user2);
            system("pause");
            system("cls");
            for (cont = 0; cont < 9;)
            {
                cont++;
                print_tabela(jogo, user1, pont1, pont2, user2); // function que imprime o tabela do jogo
                if (cont != 11)
                {
                    do
                    {
                        if (cont % 2 != 0)
                        {
                            printf("\n\tVez de %s (X). \n", user1);
                        }
                        else
                        {
                            printf("\n\tVez de %s (O).\n", user2);
                        }
                        do
                        {
                            printf("\tDigite a linha: ");
                            scanf("%d", &i);
                            setbuf(stdin, 0);
                        } while ((i > 3) || (i < 1));
                        do
                        {
                            printf("\tDigite a coluna: ");
                            scanf("%d", &j);
                            setbuf(stdin, 0);
                        } while ((j > 3) || (j < 1));

                        if (cont % 2 != 0)
                        {
                            if (jogo[i - 1][j - 1] == ' ')
                            {
                                jogo[i - 1][j - 1] = 'X';
                                controle = 0;
                                system("cls");
                            }
                            else
                            {
                                printf("\n\tEsta posicao ja foi preenchida.\n");
                                controle = 1;
                            }
                        }
                        else
                        {
                            if (jogo[i - 1][j - 1] == ' ')
                            {
                                jogo[i - 1][j - 1] = 'O';
                                controle = 0;
                                system("cls");
                            }
                            else
                            {
                                printf("\n\tEsta posicao ja foi preenchida.\n");
                                controle = 1;
                            }
                        }
                    } while (controle == 1);
                }

                if (cont > 4)
                {
                    vencedor = resultado(jogo);
                    if (vencedor == 1)
                    {
                        pont1++;
                        print_tabela(jogo, user1, pont1, pont2, user2);
                        printf("\n\tFIM DE JOGO.\n\t%s VENCEU!!\n\n", user1);
                        do
                        {
                            printf("\n\tJogar novamente? (S/N): ");
                            scanf("%c", &reiniciar);
                            setbuf(stdin, 0);
                            cont = reset(reiniciar, cont); // function para reiniciar ou encerrar o jogo
                            cleanmtrz(jogo);
                        } while (cont == 99);
                    }
                    if (vencedor == 2)
                    {
                        pont2++;
                        print_tabela(jogo, user1, pont1, pont2, user2);
                        printf("\n\tFIM DE JOGO.\n\t%s VENCEU!!\n\n", user2);
                        do
                        {
                            printf("\n\tJogar novamente? (S/N): ");
                            scanf("%c", &reiniciar);
                            setbuf(stdin, 0);
                            cont = reset(reiniciar, cont);
                            cleanmtrz(jogo);
                        } while (cont == 99);
                    }
                }
                // verifica se houve empate
                if (cont == 9)
                {
                    print_tabela(jogo, user1, pont1, pont2, user2);
                    printf("\n\tFIM DE JOGO, EMPATE.\n");
                    do
                    {
                        printf("\n\tJogar novamente? (S/N): ");
                        scanf("%c", &reiniciar);
                        setbuf(stdin, 0);
                        cont = reset(reiniciar, cont);
                        cleanmtrz(jogo);
                    } while (cont == 99);
                }
            }

            break;
        case 2:
            pont1 = 0;
            pont2 = 0;
            cleanmtrz(jogo); // function para limpar a matriz
            printf("\n\tDigite o nome do jogador: ");
            scanf(" %s", user1);
            setbuf(stdin, 0);

            printf("\tVoce jogara com (X). \n");
            system("pause");
            system("cls");

            for (cont = 0; cont < 9;)
            {
                cont++;
                print_tabela(jogo, user1, pont1, pont2, user3); // function que imprime o tabela do jogo

                if (cont != 11)
                {
                    if (cont % 2 != 0)
                    {
                        printf("\n\tSua vez (X). \n");
                        do
                        {
                            do
                            {
                                printf("\tDigite a linha: ");
                                scanf("%d", &i);
                                setbuf(stdin, 0);
                            } while ((i > 3) || (i < 1));

                            do
                            {
                                printf("\tDigite a coluna: ");
                                scanf("%d", &j);
                                setbuf(stdin, 0);
                            } while ((j > 3) || (j < 1));

                            if (jogo[i - 1][j - 1] == ' ')
                            {
                                jogo[i - 1][j - 1] = 'X';
                                controle = 0;
                                system("cls");
                            }
                            else
                            {
                                printf("\n\tEsta posicao ja foi preenchida.\n");
                                controle = 1;
                            }
                        } while (controle == 1);
                    }
                    else
                    {
                        printf("\t\nProcessando...");
                        do
                        {
                            srand(time(NULL));
                            i = (rand() % 3);
                            j = (rand() % 3);

                            if (jogo[i][j] == ' ')
                            {
                                jogo[i][j] = 'O';
                                controle = 0;
                                system("cls");
                            }
                            else
                            {
                                controle = 1;
                            }
                        } while (controle == 1);
                    }
                }
                if (cont > 4)
                {
                    vencedor = resultado(jogo);
                    if (vencedor == 1)
                    {
                        pont1++;
                        print_tabela(jogo, user1, pont1, pont2, user3);
                        printf("\n\tFIM DE JOGO.\n\t%s VENCEU!!\n\n", user1);
                        do
                        {
                            printf("\n\tJogar novamente? (S/N): ");
                            scanf("%c", &reiniciar);
                            setbuf(stdin, 0);
                            cont = reset(reiniciar, cont); // function para reiniciar ou encerrar o jogo
                            cleanmtrz(jogo);
                        } while (cont == 99);
                    }
                    vencedor = resultado(jogo);
                    if (vencedor == 2)
                    {
                        pont2++;
                        print_tabela(jogo, user1, pont1, pont2, user3);
                        printf("\n\tFIM DE JOGO.\n\tO Computador VENCEU!!\n\n");
                        do
                        {
                            printf("\n\tJogar novamente? (S/N): ");
                            scanf("%c", &reiniciar);
                            setbuf(stdin, 0);
                            cont = reset(reiniciar, cont);
                            cleanmtrz(jogo);
                        } while (cont == 99);
                    }
                }
                // verifica se houve empate
                if (cont == 9)
                {
                    print_tabela(jogo, user1, pont1, pont2, user3);
                    printf("\n\tFIM DE JOGO, EMPATE.\n");
                    do
                    {
                        printf("\n\tJogar novamente? (S/N): ");
                        scanf("%c", &reiniciar);
                        setbuf(stdin, 0);
                        cont = reset(reiniciar, cont);
                        cleanmtrz(jogo);
                    } while (cont == 99);
                }
            }

            break;
        case 3:
            exit(1);
        default:
            printf("\n\tOpcao invalida\n");
            system("pause");
            system("cls");
        }
    } while (1);
}