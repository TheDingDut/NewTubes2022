#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    char pemain1[50], pemain2[50];
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
        printf("\n\n%s memenangkan permainan!", pemain1);
    }
    else if (XO == 'O' && !draw)
    {
        printf("\n\n%s memenangkan permainan!", pemain2);
    }
    else
    {
        printf("\n\nPermainan Seri!");
    }

    return 0;
}