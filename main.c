#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    int opsi, opsiDimensi;
    char loopGame = 'N';

    /*MULAI GAME*/
    cover();
    system("cls");
    menuUtama();
    scanf("%d", &opsi);

    switch (opsi)
    {
    case 1:
        system("cls");
        InputNamaPemain();
        system("cls");
        do
        {
            system("cls");
            PilihDimensi();
            scanf("%d", &opsiDimensi);
            system("cls");
            switch (opsiDimensi)
            {
            case 1:
                // TIC TAC TOE 3 X 3
                count3 = 9;
                flagBoardDinamis = 3;
                int x = 1;
                for (int i = 0; i < flagBoardDinamis; i++)
                {
                    for (int j = 0; j < flagBoardDinamis; j++)
                    {
                        char c = x + '0';
                        papan[i][j] = '-';
                        x++;
                    }
                }
                while (CekWin3())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin3();
                }

                if (XO == 'X' && !draw)
                {
                    system("cls");
                    p1menang++;
                    printf("%s memenangkan permainan!", pemain1);
                    printf("\nHasil Akhir :\n");
                    BoardDinamis();
                }
                else if (XO == 'O' && !draw)
                {
                    system("cls");
                    p2menang++;
                    printf("%s memenangkan permainan!", pemain2);
                    printf("\nHasil Akhir :\n");
                    BoardDinamis();
                }
                else
                {
                    system("cls");
                    printf("Permainan Seri!");
                    printf("\nHasil Akhir :\n");
                    BoardDinamis();
                }
                break;
            case 2:
                // TIC TAC TOE 5 X 5
                flagBoardDinamis = 5;
                x = 1;
                for (int i = 0; i < flagBoardDinamis; i++)
                {
                    for (int j = 0; j < flagBoardDinamis; j++)
                    {
                        char c = x + '0';
                        papan[i][j] = '-';
                        x++;
                    }
                }
                while (CekWin5())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin5();
                }

                if (XO == 'X' && !draw)
                {
                    system("cls");
                    p1menang++;
                    printf("%s memenangkan permainan!", pemain1);
                    printf("\nHasil Akhir :\n");
                    BoardDinamis();
                }
                else if (XO == 'O' && !draw)
                {
                    system("cls");
                    p2menang++;
                    printf("%s memenangkan permainan!", pemain2);
                    printf("\nHasil Akhir :\n");
                    BoardDinamis();
                }
                else
                {
                    system("cls");
                    printf("Permainan Seri!");
                    printf("\nHasil Akhir :\n");
                    BoardDinamis(flagBoardDinamis);
                }
                break;
            case 3:
                // TIC TAC TOE 7 X 7
                flagBoardDinamis = 7;
                break;
            default:
                printf("\nTidak ada pilihan dimensi!");
                break;
            }
            printf("\nUlangi Permainan? (Y/N) : ");
            scanf("%s", &loopGame);
            int x = 1;
            char c;
            for (int i = 0; i < flagBoardDinamis; i++)
            {
                for (int j = 0; j < flagBoardDinamis; j++)
                {
                    c = x + '0';
                    papan[i][j] = '-';
                    x++;
                }
            }
        } while (loopGame == 'Y');

        system("cls");
        printf("%s %d vs %d %s\n", pemain1, p1menang, p2menang, pemain2);
        break;
    case 2:
        /*HOW TO PLAY*/
        break;
    case 3:
        /*QUIT GAME*/
        Closing();
        getchar();
        break;
    default:
        printf("Input Salah!");
        break;
    }

    return 0;
}