#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    char pemain1[50], pemain2[50];
    int menu, dimensi, simbol;
    bool game = true;

    Cover();
	system("cls");
	Menu();
	printf("Pilih Menu \t: ");
	scanf("%d", &menu);
    switch (menu)
	{
	case 1: 
            PilihDimensi();
            printf("Pilih Dimensi :");
            scanf("%d", &dimensi);
            switch (dimensi)
            {
            case 1 : 
                    InputNamaPemain(&pemain1, &pemain2);
                    system("cls");
                    PilihSimbol();
                    printf("Pilih Simbol :");
                    scanf("%d", &simbol);
                    system("cls");
                    cetakPapan3();
                    giliran(pemain1, pemain2);
            case 2 :
                    InputNamaPemain(&pemain1, &pemain2);
                    system("cls");
                    PilihSimbol();
                    printf("Pilih Simbol :");
                    scanf("%d", &simbol);
                    system("cls");
            case 3 :
                    InputNamaPemain(&pemain1, &pemain2);
                    system("cls");
                    PilihSimbol();
                    printf("Pilih Simbol :");
                    scanf("%d", &simbol);
                    system("cls");
            }
    case 2 :
            HowToPlay();
            system("cls");
    case 3 :
            Quit();
            system("cls");
    }
    Closing();
    
    


    


    return 0;
}