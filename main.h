#include <stdio.h>
#include <stdbool.h>
#include <time.h>

char pemain1[50], pemain2[50];
char papan[7][7];
char XO = 'O';
int pilihan, flagBoardDinamis;
// pemenang
int p1menang = 0, p2menang = 0;
int count3 = 9;
int count5 = 25;
bool draw = false;

// Deklarasi Variabel Koordinat
typedef struct
{
    int baris, kolom;
} Koordinat;

// Cetak Cover
void cover()
{
    printf("\t\tTTTTT  H   H  EEEEE     D     I  N    N  GGGG  D     U   U  TTTTT\n");
    printf("\t\t  T    H   H  E         D D   I  N N  N  G     D D   U   U    T\n");
    printf("\t\t  T    HHHHH  EEE       D  D  I  N  N N  GGGG  D  D  U   U    T\n");
    printf("\t\t  T    H   H  E         D D   I  N   NN  G  G  D D   U   U    T\n");
    printf("\t\t  T    H   H  EEEEE     D     I  N    N  GGGG  D     UUUUU    T\n\n");
    printf("\t\t===================================================================\n\n");
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE  \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE   \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE  \n\n");
    printf("\t\t\t    Made By :                      \n");
    printf("\t\t\t    1. Hasna Fitriyani Khairunnisa \n");
    printf("\t\t\t    2. Muhammad Fikri Nur Sya'bani \n");
    printf("\t\t\t    3. Naffa Lenteranisa           \n\n");
    printf("Tekan Enter Untuk Lanjut . . .");
    getchar();
}

// Cetak Menu Utama
void menuUtama()
{
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\t              MAIN MENU      \n\n");
    printf("\t\t\t          1. Mulai Permainan \n");
    printf("\t\t\t          2. Cara Bermain    \n");
    printf("\t\t\t          3. Keluar Permainan\n");
    printf("Pilih Menu : ");
}

// Modul Prosedur untuk input nama pemain
void InputNamaPemain()
{
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\t  Masukkan Nama Pemain 1 : ");
    scanf("%s", &pemain1);
    printf("\t\t\t  Masukkan Nama Pemain 2 : ");
    scanf("%s", &pemain2);
}

// Modul prosedur untuk tampilan memilih simbol
void PilihSimbol()
{
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\t              Pilih Simbol\n");
    printf("\t\t\t              1. X\n");
    printf("\t\t\t              2. O\n");
}

// Modul Prosedur untuk tampilan pemilihan dimensi
void PilihDimensi()
{
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\t              Dimensi Permainan      \n\n");
    printf("\t\t\t                  1. 3x3 \n");
    printf("\t\t\t                  2. 5x5    \n");
    printf("\t\t\t                  3. 7x7\n");
    printf("Pilih Dimensi : ");
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
}

void BoardDinamis()
{
    for (int i = 0; i < flagBoardDinamis; i++)
    {
        for (int j = 0; j < flagBoardDinamis; j++)
        {
            printf(" %c ", papan[i][j]);
            if (j != flagBoardDinamis - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        for (int j = 0; j < flagBoardDinamis; j++)
        {
            /* code */
            if (i < flagBoardDinamis - 1)
            {
                /* code */
                printf("---");
                if (j != flagBoardDinamis - 1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

// modul prosedur untuk menentukan giliran dan mengubah state array pilihan baris dan kolom menjadi X / O
void giliran()
{
    Koordinat lokasi;
    time_t waktu = time(NULL); // variabel yang berisi waktu saat modul dijalankan

    if (flagBoardDinamis == 3)
    {
        if (XO == 'O')
        {
            printf("Giliran %s : ", pemain1);
        }
        else if (XO == 'X')
        {
            printf("Giliran %s : ", pemain2);
        }
        scanf("%d", &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\nWaktuHabis!\n\n");
            if (XO == 'O')
            {
                XO = 'X';
            }
            else
            {
                XO = 'O';
            }
        }
        else
        {
            printf("\n");
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

            if (papan[lokasi.baris][lokasi.kolom] == 'X' || papan[lokasi.baris][lokasi.kolom] == 'O')
            {
                printf("Kolom sudah terisi!\n");
            }
            else
            {

                if (XO == 'X' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'X';
                    XO = 'O';
                    count3--;
                }
                else if (XO == 'O' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'O';
                    XO = 'X';
                    count3--;
                }
                else
                {
                    giliran();
                }

                // cetakPapan3();
            }
        }
    }
    else if (flagBoardDinamis == 5)
    {
        if (XO == 'O')
        {
            printf("Giliran %s : ", pemain1);
        }
        else if (XO == 'X')
        {
            printf("Giliran %s : ", pemain2);
        }
        scanf("%d", &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\nWaktuHabis!\n\n");
            if (XO == 'O')
            {
                XO = 'X';
            }
            else
            {
                XO = 'O';
            }
        }
        else
        {
            printf("\n");
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
                lokasi.baris = 0;
                lokasi.kolom = 3;
                break;
            case 5:
                lokasi.baris = 0;
                lokasi.kolom = 4;
                break;
            case 6:
                lokasi.baris = 1;
                lokasi.kolom = 0;
                break;
            case 7:
                lokasi.baris = 1;
                lokasi.kolom = 1;
                break;
            case 8:
                lokasi.baris = 1;
                lokasi.kolom = 2;
                break;
            case 9:
                lokasi.baris = 1;
                lokasi.kolom = 3;
                break;
            case 10:
                lokasi.baris = 1;
                lokasi.kolom = 4;
                break;
            case 11:
                lokasi.baris = 2;
                lokasi.kolom = 0;
                break;
            case 12:
                lokasi.baris = 2;
                lokasi.kolom = 1;
                break;
            case 13:
                lokasi.baris = 2;
                lokasi.kolom = 2;
                break;
            case 14:
                lokasi.baris = 2;
                lokasi.kolom = 3;
                break;
            case 15:
                lokasi.baris = 2;
                lokasi.kolom = 4;
                break;
            case 16:
                lokasi.baris = 3;
                lokasi.kolom = 0;
                break;
            case 17:
                lokasi.baris = 3;
                lokasi.kolom = 1;
                break;
            case 18:
                lokasi.baris = 3;
                lokasi.kolom = 2;
                break;
            case 19:
                lokasi.baris = 3;
                lokasi.kolom = 3;
                break;
            case 20:
                lokasi.baris = 3;
                lokasi.kolom = 4;
                break;
            case 21:
                lokasi.baris = 4;
                lokasi.kolom = 0;
                break;
            case 22:
                lokasi.baris = 4;
                lokasi.kolom = 1;
                break;
            case 23:
                lokasi.baris = 4;
                lokasi.kolom = 2;
                break;
            case 24:
                lokasi.baris = 4;
                lokasi.kolom = 3;
                break;
            case 25:
                lokasi.baris = 4;
                lokasi.kolom = 4;
                break;
            default:
                printf("Input salah!");
                break;
            }

            if (papan[lokasi.baris][lokasi.kolom] == 'X' || papan[lokasi.baris][lokasi.kolom] == 'O')
            {
                printf("Kolom sudah terisi!\n");
            }
            else
            {

                if (XO == 'X' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'X';
                    XO = 'O';
                    count5--;
                }
                else if (XO == 'O' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'O';
                    XO = 'X';
                    count5--;
                }
                else
                {
                    giliran();
                }

                // cetakPapan3();
            }
        }
    }
    else if (flagBoardDinamis == 7)
    {
        if (XO == 'O')
        {
            printf("Giliran %s : ", pemain1);
        }
        else if (XO == 'X')
        {
            printf("Giliran %s : ", pemain2);
        }
        scanf("%d", &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\nWaktuHabis!\n\n");
            if (XO == 'O')
            {
                XO = 'X';
            }
            else
            {
                XO = 'O';
            }
        }
        else
        {
            printf("\n");
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
                lokasi.baris = 0;
                lokasi.kolom = 3;
                break;
            case 5:
                lokasi.baris = 0;
                lokasi.kolom = 4;
                break;
            case 6:
                lokasi.baris = 0;
                lokasi.kolom = 5;
                break;
            case 7:
                lokasi.baris = 0;
                lokasi.kolom = 6;
                break;
            case 8:
                lokasi.baris = 1;
                lokasi.kolom = 0;
                break;
            case 9:
                lokasi.baris = 1;
                lokasi.kolom = 1;
                break;
            case 10:
                lokasi.baris = 1;
                lokasi.kolom = 2;
                break;
            case 11:
                lokasi.baris = 1;
                lokasi.kolom = 3;
                break;
            case 12:
                lokasi.baris = 1;
                lokasi.kolom = 4;
                break;
            case 13:
                lokasi.baris = 1;
                lokasi.kolom = 5;
                break;
            case 14:
                lokasi.baris = 1;
                lokasi.kolom = 6;
                break;
            case 15:
                lokasi.baris = 2;
                lokasi.kolom = 0;
                break;
            case 16:
                lokasi.baris = 2;
                lokasi.kolom = 1;
                break;
            case 17:
                lokasi.baris = 2;
                lokasi.kolom = 2;
                break;
            case 18:
                lokasi.baris = 2;
                lokasi.kolom = 3;
                break;
            case 19:
                lokasi.baris = 2;
                lokasi.kolom = 4;
                break;
            case 20:
                lokasi.baris = 2;
                lokasi.kolom = 5;
                break;
            case 21:
                lokasi.baris = 2;
                lokasi.kolom = 6;
                break;
            case 22:
                lokasi.baris = 3;
                lokasi.kolom = 0;
                break;
            case 23:
                lokasi.baris = 3;
                lokasi.kolom = 1;
                break;
            case 24:
                lokasi.baris = 3;
                lokasi.kolom = 2;
                break;
            case 25:
                lokasi.baris = 3;
                lokasi.kolom = 3;
                break;
            case 26:
                lokasi.baris = 3;
                lokasi.kolom = 4;
                break;
            case 27:
                lokasi.baris = 3;
                lokasi.kolom = 5;
                break;
            case 28:
                lokasi.baris = 3;
                lokasi.kolom = 6;
                break;
            case 29:
                lokasi.baris = 4;
                lokasi.kolom = 0;
                break;
            case 30:
                lokasi.baris = 4;
                lokasi.kolom = 1;
                break;
            case 31:
                lokasi.baris = 4;
                lokasi.kolom = 2;
                break;
            case 32:
                lokasi.baris = 4;
                lokasi.kolom = 3;
                break;
            case 33:
                lokasi.baris = 4;
                lokasi.kolom = 4;
                break;
            case 34:
                lokasi.baris = 4;
                lokasi.kolom = 5;
                break;
            case 35:
                lokasi.baris = 4;
                lokasi.kolom = 6;
                break;
            case 36:
                lokasi.baris = 5;
                lokasi.kolom = 0;
                break;
            case 37:
                lokasi.baris = 5;
                lokasi.kolom = 1;
                break;
            case 38:
                lokasi.baris = 5;
                lokasi.kolom = 2;
                break;
            case 39:
                lokasi.baris = 5;
                lokasi.kolom = 3;
                break;
            case 40:
                lokasi.baris = 5;
                lokasi.kolom = 4;
                break;
            case 41:
                lokasi.baris = 5;
                lokasi.kolom = 5;
                break;
            case 42:
                lokasi.baris = 5;
                lokasi.kolom = 6;
                break;
            case 43:
                lokasi.baris = 6;
                lokasi.kolom = 0;
                break;
            case 44:
                lokasi.baris = 6;
                lokasi.kolom = 1;
                break;
            case 45:
                lokasi.baris = 6;
                lokasi.kolom = 2;
                break;
            case 46:
                lokasi.baris = 6;
                lokasi.kolom = 3;
                break;
            case 47:
                lokasi.baris = 6;
                lokasi.kolom = 4;
                break;
            case 48:
                lokasi.baris = 6;
                lokasi.kolom = 5;
                break;
            case 49:
                lokasi.baris = 6;
                lokasi.kolom = 6;
                break;
            default:
                printf("Input salah!");
                break;
            }
        }

            if (papan[lokasi.baris][lokasi.kolom] == 'X' || papan[lokasi.baris][lokasi.kolom] == 'O')
            {
                printf("Kolom sudah terisi!\n");
            }
            else
            {

                if (XO == 'X' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'X';
                    XO = 'O';
                    count5--;
                }
                else if (XO == 'O' && papan[lokasi.baris][lokasi.kolom] != 'X' && papan[lokasi.baris][lokasi.kolom] != 'O')
                {
                    papan[lokasi.baris][lokasi.kolom] = 'O';
                    XO = 'X';
                    count5--;
                }
                else
                {
                    giliran();
                }

                // cetakPapan7();
            }
    }
}

bool CekWin3()
{
    /*cek vertikal horizontal*/
    for (int i = 0; i < 3; i++)
    {
        if (count3 <= 4)
        {
            if ((papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2]) || (papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i]))
                return false;
        }
    }

    /*checking diagonals*/
    if (count3 <= 4)
    {
        if ((papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2]) || (papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0]))
        {

            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    { /*cek draw*/

        for (int j = 0; j < 3; j++)
        {

            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return true;
        }
    }

    draw = true;

    return false;
}

bool CekWin5()
{
    for (int i = 0; i < 5; i++)
    {
        if ((papan[i][0] == 'X' && papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X') || (papan[i][0] == 'O' && papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O') ||
            (papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X') || (papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O') ||
            (papan[0][i] == 'X' && papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X') || (papan[0][i] == 'O' && papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O') ||
            (papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X') || (papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O'))
        {
            return false;
        }
    }

    /*checking diagonals*/
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X') || (papan[0][0] == 'O' && papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O') ||
        (papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X') || (papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O') ||
        (papan[0][1] == 'X' && papan[1][2] == 'X' && papan[2][3] == 'X' && papan[3][4] == 'X') || (papan[0][1] == 'O' && papan[1][2] == 'O' && papan[2][3] == 'O' && papan[3][4] == 'O') ||
        (papan[1][0] == 'X' && papan[2][1] == 'X' && papan[3][2] == 'X' && papan[4][3] == 'X') || (papan[1][0] == 'O' && papan[2][1] == 'O' && papan[3][2] == 'O' && papan[4][3] == 'O'))
    {
        return false;
    }

    for (int i = 0; i < 5; i++)
    { /*cek draw*/

        for (int j = 0; j < 5; j++)
        {
            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return true;
        }
    }

    draw = true;

    return false;
}

// Modul Prosedur untuk tampilan akhir
void Closing()
{
    printf("\t\tTTTTT  H   H  EEEEE     D     I  N    N  GGGG  D     U   U  TTTTT\n");
    printf("\t\t  T    H   H  E         D D   I  N N  N  G     D D   U   U    T\n");
    printf("\t\t  T    HHHHH  EEE       D  D  I  N  N N  GGGG  D  D  U   U    T\n");
    printf("\t\t  T    H   H  E         D D   I  N   NN  G  G  D D   U   U    T\n");
    printf("\t\t  T    H   H  EEEEE     D     I  N    N  GGGG  D     UUUUU    T\n\n");
    printf("\t\t===================================================================\n\n");
    printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
    printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
    printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
    printf("\t\t\t         TERIMA KASIH TELAH BERMAIN      \n\n");
    printf("\t\t\t               Sampai Jumpa!! \n");
}

// switch (pilihan)
// {
// case 1:
//     lokasi.baris = 0;
//     lokasi.kolom = 0;
//     break;
// case 2:
//     lokasi.baris = 0;
//     lokasi.kolom = 1;
//     break;
// case 3:
//     lokasi.baris = 0;
//     lokasi.kolom = 2;
//     break;
// case 4:
//     lokasi.baris = 1;
//     lokasi.kolom = 0;
//     break;
// case 5:
//     lokasi.baris = 1;
//     lokasi.kolom = 1;
//     break;
// case 6:
//     lokasi.baris = 1;
//     lokasi.kolom = 2;
//     break;
// case 7:
//     lokasi.baris = 2;
//     lokasi.kolom = 0;
//     break;
// case 8:
//     lokasi.baris = 2;
//     lokasi.kolom = 1;
//     break;
// case 9:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 10:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 11:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 12:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 13:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 14:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 15:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 16:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 17:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 18:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 19:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 20:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 21:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 22:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 23:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 24:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 25:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 26:
//     lokasi.baris = 0;
//     lokasi.kolom = 0;
//     break;
// case 27:
//     lokasi.baris = 0;
//     lokasi.kolom = 1;
//     break;
// case 28:
//     lokasi.baris = 0;
//     lokasi.kolom = 2;
//     break;
// case 29:
//     lokasi.baris = 1;
//     lokasi.kolom = 0;
//     break;
// case 30:
//     lokasi.baris = 1;
//     lokasi.kolom = 1;
//     break;
// case 31:
//     lokasi.baris = 1;
//     lokasi.kolom = 2;
//     break;
// case 32:
//     lokasi.baris = 2;
//     lokasi.kolom = 0;
//     break;
// case 33:
//     lokasi.baris = 2;
//     lokasi.kolom = 1;
//     break;
// case 34:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 35:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 36:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 37:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 38:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 39:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 40:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 41:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 42:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 43:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 44:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 45:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 46:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 47:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 48:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// case 49:
//     lokasi.baris = 2;
//     lokasi.kolom = 2;
//     break;
// default:
//     printf("Input salah!");
//     break;
// }