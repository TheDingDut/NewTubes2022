#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    int opsi;               // Variabel ini digunakan untuk menampung pilihan pada menuUtama yang dipilih user
    int opsiDimensi;        // Variabel ini digunakan untuk menampung pilihan dimensi yang dipilih user
    char loopGame = 'N';    // Variabel ini digunakan untuk menginiliasasi dan menampung pilihan user untuk mengulangi permainan atau tidak

    /* WARNA */
    system("COLOR 8B");

    /*MULAI GAME*/
    cover();                //EDIT-EDIT SAJA 
    system("cls");          //HANYA UNTUK MENGETEST
    menuUtama();            //HAHAHAHA
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
                    boardRef5();
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
                    boardRef7();
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
        Closing();
        break;
    case 2:
        system("cls");

        FILE *FF; // penunjuk ke file
        char CC;  // var penunjuk karakter yang dibaca

        if ((FF = fopen("HOW TO PLAY.txt", "r")) == NULL)
        { // Buka file mode baca
            printf("Pembukaan File Gagal !");
            exit(1); // keluar program
        }

        while ((CC = getc(FF)) != EOF)
        {              // CC akan berisi karakter yg dibaca, akhir teks dengan EOF
            putch(CC); // baca dan tampilkan ke layar
        }

        fclose(FF);
        printf("\nPress any key to main menu... ");
        getch();
        main();

    case 3:
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