#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    int menu, pilihDimensi;

    cover();
	system("cls");
	Menu();
	printf("Pilih Menu \t: ");
	scanf("%d", &menu);
    switch (menu)
	{
	case 1: 
            Dimensi();
            printf("Pilih Dimensi :");
            scanf("%d", &pilihDimensi);
            switch (pilihDimensi)
            {

            }

    }
    char pemain1[50], pemain2[50];
    InputNamaPemain(&pemain1, &pemain2);
    system("cls");


    cetakPapan3();
    giliran(pemain1, pemain2);


    return 0;
}