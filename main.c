#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    /*DEKLARASI VARIABEL*/
    char pemain1[50], pemain2[50];
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
        InputNamaPemain(&pemain1, &pemain2);
        system("cls");
        PilihDimensi();
        scanf("%d", &opsiDimensi);
        system("cls");
        switch (opsiDimensi)
        {
        case 1:
            // TIC TAC TOE 3 X 3
            do
            {
                while (AkhirPermainan())
                {
                    printf("Waktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
                    cetakPapan3();
                    giliran(pemain1, pemain2);
                    AkhirPermainan();
                }

                if (XO == 'X' && !draw)
                {
                    system("cls");
                    p1menang++;
                    printf("%s memenangkan permainan!", pemain1);
                    printf("\nHasil Akhir :\n");
                    cetakPapan3();
                }
                else if (XO == 'O' && !draw)
                {
                    system("cls");
                    p2menang++;
                    printf("%s memenangkan permainan!", pemain2);
                    printf("\nHasil Akhir :\n");
                    cetakPapan3();
                }
                else
                {
                    system("cls");
                    printf("Permainan Seri!");
                    printf("\nHasil Akhir :\n");
                    cetakPapan3();
                }
                printf("\nUlangi permainan? ");
                scanf("%s", &loopGame);
            } while (loopGame == 'Y');
            system("cls");
            printf("%s berhasil memenangkan %d permainan!\n", pemain1, p1menang);
            printf("%s berhasil memenangkan %d permainan!\n", pemain2, p2menang);
            break;
        case 2:
            // TIC TAC TOE 5 X 5
            break;
        case 3:
            // TIC TAC TOE 7 X 7
            break;
        default:
            printf("\nTidak ada pilihan dimensi!");
            break;
        }
        break;
    case 2:
        /*HOW TO PLAY*/
        break;
    case 3:
        /*QUIT GAME*/
        printf("Terimakasih :)");
        getchar();
        break;
    default:
        printf("Input Salah!");
        break;
    }

    return 0;
}