#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    int opsi;            // Variabel ini digunakan untuk menampung pilihan pada menuUtama yang dipilih user
    int opsiDimensi;     // Variabel ini digunakan untuk menampung pilihan dimensi yang dipilih user
    char loopGame = 'N'; // Variabel ini digunakan untuk menginiliasasi dan menampung pilihan user untuk mengulangi permainan atau tidak

    /* WARNA */
    system("COLOR E0");

    /*MULAI GAME*/
    cover();
    system("cls");      // Code ini bertujuan untuk membersihkan layar program
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
                    boardRef3();
                    tampilanPengingatWaktu();
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
                    boardRef5();
                    tampilanPengingatWaktu();
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
                    boardRef7();
                    tampilanPengingatWaktu();
                    BoardDinamis();
                    giliran(pemain1, pemain2);
                    CekWin7();
                }
                PemainWin();
                break;
            case 4:
                // getch();
                main();
            default:
                printf("\nTidak ada pilihan dimensi!");
                break;
            }
            printf("\n\tUlangi Permainan? Tekan selain 'Y' untuk keluar : ");
            scanf("%s", &loopGame);
            isiPapan();
        } while ((toupper(loopGame) == 'Y' && p1menang < 3) && (toupper(loopGame) == 'Y' && p2menang < 3));
        system("cls");
        Closing();
        break;
    case 2:
        /*HOW TO PLAY*/
        system("cls");
        HowToPlay();
        getch();
        main();

    case 3:
        /*SCORE BOARD*/
        system("cls");
        scoreboard();

        break;

    case 4:
        /*QUIT GAME*/
        KeluarPermainan();
        getchar();

        break;
    default:
        printf("Input Salah!");
        break;
    }

    return 0;
}