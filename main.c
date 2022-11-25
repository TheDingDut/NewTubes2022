#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    char pemain1[50], pemain2[50];
    InputNamaPemain(&pemain1, &pemain2);
    system("cls");

    cetakPapan3();
    giliran(pemain1, pemain2);

    return 0;
}