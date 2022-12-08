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
                flagBoardDinamis = 3;
                isiPapan();
                while (CekWin3())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin3();
                }
                PemainWin();
                break;
            case 2:
                // TIC TAC TOE 5 X 5
                flagBoardDinamis = 5;
                isiPapan();
                while (CekWin5())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin5();
                }
                PemainWin();
                break;
            case 3:
                // TIC TAC TOE 7 X 7
                flagBoardDinamis = 7;
                isiPapan();
                while (CekWin7())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin7();
                }
                PemainWin();
                break;
            default:
                printf("\nTidak ada pilihan dimensi!");
                break;
            }
            printf("\nUlangi Permainan? (Y/N) : ");
            scanf("%s", &loopGame);
            isiPapan();
        } while ((loopGame == 'Y' && p1menang <= 3) || (loopGame == 'Y' && p2menang <= 3));
        system("cls");
            printf("%s %d vs %d %s\n", pemain1, p1menang, p2menang, pemain2);
        break;
    case 2:
        HowToPlay();
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