#include <stdio.h>

char papan[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char XO = 'O';
int pilihan;

// Deklarasi Variabel Koordinat
typedef struct
{
    int baris, kolom;
} Koordinat;

// Modul Prosedur untuk tampilan awal permainan
    void cover(){

    }

// Modul Prosedur untuk tampilan menu
    void Menu(){

    }

// Modul Prosedur untuk tampilan pemilihan dimensi
    void Dimensi(){

    }

// Modul Prosedur untuk input nama pemain
void InputNamaPemain(char *p1, char *p2)
{
    printf("Masukkan Nama Pemain 1 : ");
    scanf("%s", &*p1);
    printf("Masukkan Nama Pemain 2 : ");
    scanf("%s", &*p2);
}

// Modul prosedur untuk cetak papan 3 x 3
void cetakPapan3()
{
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", papan[i][0], papan[i][1], papan[i][2]);
        if (i != 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
    printf("\n");
}

// modul prosedur untuk menentukan giliran dan mengubah state array pilihan baris dan kolom menjadi X / O
void giliran(pemain1, pemain2)
{
    Koordinat lokasi;
    if (XO == 'O')
    {
        printf("Giliran %s : ", pemain1);
    }
    else if (XO == 'X')
    {
        printf("Giliran %s : ", pemain2);
    }
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        lokasi.baris = 0;
        lokasi.kolom = 0;
        break;
    case 2:
        lokasi.baris = 0;
        lokasi.kolom = 1;
        break;
    case 3:
        lokasi.baris = 0;
        lokasi.kolom = 2;
        break;
    case 4:
        lokasi.baris = 1;
        lokasi.kolom = 0;
        break;
    case 5:
        lokasi.baris = 1;
        lokasi.kolom = 1;
        break;
    case 6:
        lokasi.baris = 1;
        lokasi.kolom = 2;
        break;
    case 7:
        lokasi.baris = 2;
        lokasi.kolom = 0;
        break;
    case 8:
        lokasi.baris = 2;
        lokasi.kolom = 1;
        break;
    case 9:
        lokasi.baris = 2;
        lokasi.kolom = 2;
        break;
    default:
        printf("Input salah!");
        break;
    }

    if (XO == 'X' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
    {
        papan[lokasi.baris][lokasi.kolom] = 'X';
        XO = 'O';
    }
    else if (XO == 'O' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
    {
        papan[lokasi.baris][lokasi.kolom] = 'O';
        XO = 'X';
    }
    else
    {
        giliran();
    }

    cetakPapan3();
}

