#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    char pemain1[50], pemain2[50];
    cover();
    menuUtama();
    printf("\nPilih Menu : ");
    getchar();
    system("cls");
    InputNamaPemain(&pemain1, &pemain2);
    system("cls");
    while (AkhirPermainan())
    {
        cetakPapan3();
        giliran(pemain1, pemain2);
        AkhirPermainan();
    }

    if (XO == 'X' && !draw)
    {
        system("cls");
        printf("%s memenangkan permainan!", pemain1);
        printf("\nHasil Akhir :\n");
        cetakPapan3();
    }
    else if (XO == 'O' && !draw)
    {
        system("cls");
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

    return 0;
}