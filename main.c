#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    int opsi;             // Variabel ini digunakan untuk menampung pilihan pada menuUtama yang dipilih user
    int opsiDimensi;      // Variabel ini digunakan untuk menampung pilihan dimensi yang dipilih user
    int flagBoardDinamis; // Variabel ini digunakan untuk menampung pilihan dimensi papan untuk dapat dicetak
    char loopGame = 'N';  // Variabel ini digunakan untuk menginiliasasi dan menampung pilihan user untuk mengulangi permainan atau tidak
    Player pemain1, pemain2;
    pemain1.menang = 0;
    pemain2.menang = 0;

    /* WARNA */
    system("COLOR E0");

    /*MULAI GAME*/
    cover();
    system("cls"); // Code ini bertujuan untuk membersihkan layar program
    menuUtama();
    scanf("%d", &opsi);
    switch (opsi)
    {
    case 1:
        system("cls");
        InputNamaPemain(&pemain1, &pemain2);
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
                isiPapan(flagBoardDinamis);
                while (CekWin3(flagBoardDinamis))
                {
                    boardRef3(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    CekWin3(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
                break;
            case 2:
                // TIC TAC TOE 5 X 5
                flagBoardDinamis = 5;
                isiPapan(flagBoardDinamis);
                while (CekWin5(flagBoardDinamis))
                {
                    boardRef5(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    CekWin5(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
                break;
            case 3:
                // TIC TAC TOE 7 X 7
                flagBoardDinamis = 7;
                isiPapan(flagBoardDinamis);
                while (CekWin7(flagBoardDinamis)) // apabila kondisi terpenuhi, maka looping berjalan
                {
                    boardRef7(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    CekWin7(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
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
            isiPapan(flagBoardDinamis);
        } while ((toupper(loopGame) == 'Y' && pemain1.menang < 3) && (toupper(loopGame) == 'Y' && pemain2.menang < 3)); // apabila kondisi terpenuhi, maka loop berjalan
        system("cls");
        displayClosing(pemain1, pemain2);
        break;
    case 2:
        /*HOW TO PLAY*/
        system("cls");
        displayHowToPlay();
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