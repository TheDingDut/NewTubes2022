#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    int opsi;                // Variabel ini digunakan untuk menampung pilihan pada menuUtama yang dipilih user
    int opsiDimensi;         // Variabel ini digunakan untuk menampung pilihan dimensi yang dipilih user
    int flagBoardDinamis;    // Variabel ini digunakan untuk menampung pilihan dimensi papan untuk dapat dicetak
    char loopGame = 'N';     // Variabel ini digunakan untuk menginiliasasi dan menampung pilihan user untuk mengulangi permainan atau tidak
    Player pemain1, pemain2; // Variabel ini merupakan variabel bertipe data Player
    pemain1.menang = 0;      // Variabel ini digunakan untuk menampung skor yang didapat pemain 1
    pemain2.menang = 0;      // Variabel ini digunakan untuk menampung skor yang didapat pemain 2

    /* WARNA */
    system("COLOR E0"); // Code ini digunakan untuk mengubah warna layar dan tulisan pada output program

    /*MULAI GAME*/
    cover();
    system("cls"); // Code ini bertujuan untuk membersihkan layar program
    menuUtama();
    scanf("%d", &opsi);
    switch (opsi)
    {
    case 1:
        /*Memulai permainan*/
        system("cls");
        InputNamaPemain(&pemain1, &pemain2);
        system("cls");
        do
        {
            system("cls");
            PilihDimensi();
            scanf("%d", &opsiDimensi);
            system("cls");
            switch (opsiDimensi) // Proses yang dilanjutkan sesuai opsi yang dipilih user pada pemilihan papan dimensi permainan
            {
            case 1:
                // TIC TAC TOE 3 X 3
                flagBoardDinamis = 3;
                isiPapan(flagBoardDinamis);
                while (GamePlay3(flagBoardDinamis)) //  Apabila gameplay3 bernilai true maka permainan dapat dilakukan
                {
                    boardRef3(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    GamePlay3(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
                break;
            case 2:
                // TIC TAC TOE 5 X 5
                flagBoardDinamis = 5;
                isiPapan(flagBoardDinamis);
                while (GamePlay5(flagBoardDinamis)) //  Apabila gameplay5 bernilai true maka permainan dapat dilakukan
                {
                    boardRef5(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    GamePlay5(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
                break;
            case 3:
                // TIC TAC TOE 7 X 7
                flagBoardDinamis = 7;
                isiPapan(flagBoardDinamis);
                while (GamePlay7(flagBoardDinamis)) //  Apabila gameplay7 bernilai true maka permainan dapat dilakukan
                {
                    boardRef7(pemain1, pemain2);
                    tampilanPengingatWaktu();
                    BoardDinamis(flagBoardDinamis);
                    inputSimbolKedalamPapan(pemain1, pemain2, flagBoardDinamis);
                    GamePlay7(flagBoardDinamis);
                }
                getWinner(&pemain1, &pemain2, draw, flagBoardDinamis);
                break;
            case 4:
                // Kembali ke menu utama
                main();
            default:
                // Apabila user menginput nomor selain 1-4 pada pemilihan dimensi
                printf("\nTidak ada pilihan dimensi!");
                break;
            }
            printf("\n\tUlangi Permainan? Tekan selain 'Y' untuk keluar : ");
            scanf("%s", &loopGame);
            isiPapan(flagBoardDinamis);                                                                                 // Proses inisialisasi papan agar tidak berisi simbol
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
        /*Apabila user menginput nomor selain 1-4 pada menu utama*/
        printf("Input Salah!");
        getch();
        main();
        break;
    }

    return 0;
}