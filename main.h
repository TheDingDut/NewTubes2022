#include <stdio.h>
#include <stdbool.h>
#include <time.h>

char pemain1[50], pemain2[50];
char papan[7][7];
char XO = 'O';
int pilihan, flagBoardDinamis;
// pemenang
int p1menang = 0, p2menang = 0;
bool draw = false;

// Deklarasi Variabel Koordinat
typedef struct
{
    int baris, kolom;
} Koordinat;

// Cetak Cover
void cover()
{
    printf("\n\t  TTTTTTTT   HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UU    UU  TTTTTTTT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN NN   NN  GG        DD     DD   UU    UU     TT\n");
    printf("\t     TT      HHHHHHH  EEEEEE       DD      DD  II  NN  NN  NN  GG  GGGG  DD      DD  UU    UU     TT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN   NN NN  GG    GG  DD     DD   UU    UU     TT\n");
    printf("\t     TT      HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UUUUUUUU     TT\n\n");
    printf("\t  =====================================================================================================\n\n");
    printf("\t\t\t   TTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE  \n");
    printf("\t\t\t     TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE   \n ");
    printf("\t\t\t     TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE  \n\n\n");
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
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t===================================================================\n\n");
    printf("\t\t\t                          MAIN MENU      \n\n");
    printf("\t\t\t                       1. Mulai Permainan \n");
    printf("\t\t\t                       2. Cara Bermain    \n");
    printf("\t\t\t                       3. Keluar Permainan\n");
    printf("\t\t\tPilih Menu : ");
}

// Modul Prosedur untuk input nama pemain
void InputNamaPemain()
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t=================================================================\n\n");
    printf("\t\t\t  Masukkan Nama Pemain 1 (O) : ");
    scanf("%s", &pemain1);
    printf("\t\t\t  Masukkan Nama Pemain 2 (X) : ");
    scanf("%s", &pemain2);
}

// Modul prosedur untuk tampilan memilih simbol
void PilihSimbol()
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t=================================================================\n\n");
    printf("\t\t\t                      Pilih Simbol\n");
    printf("\t\t\t                      1. X\n");
    printf("\t\t\t                      2. O\n");
}

// Modul Prosedur untuk tampilan pemilihan dimensi
void PilihDimensi()
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t=================================================================\n\n");
    printf("\t\t\t                          Dimensi Permainan      \n\n");
    printf("\t\t\t                       1. 3x3 \n");
    printf("\t\t\t                       2. 5x5    \n");
    printf("\t\t\t                       3. 7x7\n");
    printf("\t\t\tPilih Dimensi : ");
}

void boardRef3()
{
    printf("Pilih salah satu kolom dengan menginputkan nomor\n");
    printf(" 1  | 2  | 3  \t\t\t%s : %d\n", pemain1, p1menang);
    printf("----|----|----\t\t\t%s : %d\n", pemain2, p2menang);
    printf(" 4  | 5  | 6  \n");
    printf("----|----|----\n");
    printf(" 7  | 8  | 9  \n");
}

void boardRef5()
{
    printf("Pilih salah satu kolom dengan menginputkan nomor\n");
    printf(" 1  | 2  | 3  | 4  | 5  \t\t\t%s : %d\n", pemain1, p1menang);
    printf("----|----|----|----|----\t\t\t%s : %d\n", pemain2, p2menang);
    printf(" 6  | 7  | 8  | 9  | 10 \n");
    printf("----|----|----|----|----\n");
    printf(" 11 | 12 | 13 | 14 | 15 \n");
    printf("----|----|----|----|----\n");
    printf(" 16 | 17 | 18 | 19 | 20 \n");
    printf("----|----|----|----|----\n");
    printf(" 21 | 22 | 23 | 24 | 25 \n");
}

void boardRef7()
{
    printf("Pilih salah satu kolom dengan menginputkan nomor\n");
    printf(" 1  | 2  | 3  | 4  | 5  | 6  | 7  \t\t\t%s : %d\n", pemain1, p1menang);
    printf("----|----|----|----|----|----|----\t\t\t%s : %d\n", pemain2, p2menang);
    printf(" 8  | 9  | 10 | 11 | 12 | 13 | 14 \n");
    printf("----|----|----|----|----|----|----\n");
    printf(" 15 | 16 | 17 | 18 | 19 | 20 | 21 \n");
    printf("----|----|----|----|----|----|----\n");
    printf(" 22 | 23 | 24 | 25 | 26 | 27 | 28 \n");
    printf("----|----|----|----|----|----|----\n");
    printf(" 29 | 30 | 31 | 32 | 33 | 34 | 35 \n");
    printf("----|----|----|----|----|----|----\n");
    printf(" 36 | 37 | 38 | 39 | 40 | 41 | 42 \n");
    printf("----|----|----|----|----|----|----\n");
    printf(" 43 | 44 | 45 | 46 | 47 | 48 | 49 \n");
}

void isiPapan()
{
    int x = 1;
    for (int i = 0; i < flagBoardDinamis; i++)
    {
        for (int j = 0; j < flagBoardDinamis; j++)
        {
            char c = x + '0';
            papan[i][j] = '-';
            x++;
        }
    }
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
            printf("WaktuHabis!\n");
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

            // cetakPapan7();
        }
    }
}

bool CekWin3()
{
    /*cek horizontal dan vertikal*/
    for (int i = 0; i < 3; i++)
    {
        if ((papan[i][0] == 'X' && papan[i][1] == 'X' && papan[i][2] == 'X') || (papan[i][0] == 'O' && papan[i][1] == 'O' && papan[i][2] == 'O') ||
            (papan[0][i] == 'X' && papan[1][i] == 'X' && papan[2][i] == 'X') || (papan[0][i] == 'O' && papan[1][i] == 'O' && papan[2][i] == 'O'))
        {
            return false;
        }
    }

    /*checking diagonals*/
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X') || (papan[0][2] == 'O' && papan[1][1] == 'O' && papan[2][0] == 'O'))
    {
        return false;
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
    /*cek vertikal horizontal dan vertikal*/
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
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X') || (papan[0][4] == 'O' && papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O') ||
        (papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X') || (papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O' && papan[4][0] == 'O'))
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

bool CekWin7()
{
    /*cek vertikal horizontal dan vertikal*/
    for (int i = 0; i < 7; i++)
    {
        if ((papan[i][0] == 'X' && papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X') || (papan[i][0] == 'O' && papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O') ||
            (papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X' && papan[i][5] == 'X') || (papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O' && papan[i][4] == 'O') ||
            (papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X' && papan[i][5] == 'X' && papan[i][6] == 'X') || (papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O' && papan[i][5] == 'O' && papan[i][6] == 'O') ||
            (papan[0][i] == 'X' && papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X') || (papan[0][i] == 'O' && papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O') ||
            (papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X' && papan[5][i] == 'X') || (papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O' && papan[4][i] == 'O') ||
            (papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X' && papan[5][i] == 'X' && papan[6][i] == 'X') || (papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O' && papan[5][i] == 'O' && papan[6][i] == 'O'))
        {
            return false;
        }
    }

    /*checking diagonals*/
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X') || (papan[0][0] == 'O' && papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O') ||
        (papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X' && papan[5][5] == 'X') || (papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O' && papan[5][5] == 'O') ||
        (papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X' && papan[5][5] == 'X' && papan[6][6] == 'X') || (papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O' && papan[5][5] == 'O' && papan[6][6] == 'O') ||

        (papan[0][1] == 'X' && papan[1][2] == 'X' && papan[2][3] == 'X' && papan[3][4] == 'X' && papan[4][5] == 'X') || (papan[0][1] == 'O' && papan[1][2] == 'O' && papan[2][3] == 'O' && papan[3][4] == 'O' && papan[4][5] == 'O') ||
        (papan[1][2] == 'X' && papan[2][3] == 'X' && papan[3][4] == 'X' && papan[4][5] == 'X' && papan[5][6] == 'X') || (papan[1][2] == 'O' && papan[2][3] == 'O' && papan[3][4] == 'O' && papan[4][5] == 'O' && papan[5][6] == 'O') ||

        (papan[0][2] == 'X' && papan[1][3] == 'X' && papan[2][4] == 'X' && papan[3][5] == 'X' && papan[4][6] == 'X') || (papan[0][2] == 'O' && papan[1][3] == 'O' && papan[2][4] == 'O' && papan[3][5] == 'O' && papan[4][6] == 'O') ||

        (papan[1][0] == 'X' && papan[2][1] == 'X' && papan[3][2] == 'X' && papan[4][3] == 'X' && papan[5][4] == 'X') || (papan[1][0] == 'O' && papan[2][1] == 'O' && papan[3][2] == 'O' && papan[4][3] == 'O' && papan[5][4] == 'O') ||
        (papan[2][1] == 'X' && papan[3][2] == 'X' && papan[4][3] == 'X' && papan[5][4] == 'X' && papan[6][5] == 'X') || (papan[2][1] == 'O' && papan[3][2] == 'O' && papan[4][3] == 'O' && papan[5][4] == 'O' && papan[6][5] == 'O') ||

        (papan[2][0] == 'X' && papan[3][1] == 'X' && papan[4][2] == 'X' && papan[5][3] == 'X' && papan[6][4] == 'X') || (papan[2][0] == 'O' && papan[3][1] == 'O' && papan[4][2] == 'O' && papan[5][3] == 'O' && papan[6][4] == 'O') ||

        (papan[0][6] == 'X' && papan[1][5] == 'X' && papan[2][4] == 'X' && papan[3][3] == 'X' && papan[4][2] == 'X') || (papan[0][6] == 'O' && papan[1][5] == 'O' && papan[2][4] == 'O' && papan[3][3] == 'O' && papan[4][2] == 'O') ||
        (papan[1][5] == 'X' && papan[2][4] == 'X' && papan[3][3] == 'X' && papan[4][2] == 'X' && papan[5][1] == 'X') || (papan[1][5] == 'O' && papan[2][4] == 'O' && papan[3][3] == 'O' && papan[4][2] == 'O' && papan[5][1] == 'O') ||
        (papan[2][4] == 'X' && papan[3][3] == 'X' && papan[4][2] == 'X' && papan[5][1] == 'X' && papan[6][0] == 'X') || (papan[2][4] == 'O' && papan[3][3] == 'O' && papan[4][2] == 'O' && papan[5][1] == 'O' && papan[6][0] == 'O') ||

        (papan[0][5] == 'X' && papan[1][4] == 'X' && papan[2][3] == 'X' && papan[3][2] == 'X' && papan[4][1] == 'X') || (papan[0][5] == 'O' && papan[1][4] == 'O' && papan[2][3] == 'O' && papan[3][2] == 'O' && papan[4][1] == 'O') ||
        (papan[1][4] == 'X' && papan[2][3] == 'X' && papan[3][2] == 'X' && papan[4][1] == 'X' && papan[5][0] == 'X') || (papan[1][4] == 'O' && papan[2][3] == 'O' && papan[3][2] == 'O' && papan[4][1] == 'O' && papan[5][0] == 'O') ||

        (papan[0][4] == 'X' && papan[1][3] == 'X' && papan[2][2] == 'X' && papan[3][1] == 'X' && papan[4][0] == 'X') || (papan[0][4] == 'O' && papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O' && papan[4][0] == 'O') ||

        (papan[1][6] == 'X' && papan[2][5] == 'X' && papan[3][4] == 'X' && papan[4][3] == 'X' && papan[5][2] == 'X') || (papan[1][6] == 'O' && papan[2][5] == 'O' && papan[3][4] == 'O' && papan[4][3] == 'O' && papan[5][2] == 'O') ||
        (papan[2][5] == 'X' && papan[3][4] == 'X' && papan[4][3] == 'X' && papan[5][2] == 'X' && papan[6][1] == 'X') || (papan[2][5] == 'O' && papan[3][4] == 'O' && papan[4][3] == 'O' && papan[5][2] == 'O' && papan[6][1] == 'O') ||

        (papan[2][6] == 'X' && papan[3][5] == 'X' && papan[4][4] == 'X' && papan[5][3] == 'X' && papan[6][2] == 'X') || (papan[2][5] == 'O' && papan[3][4] == 'O' && papan[4][3] == 'O' && papan[5][2] == 'O' && papan[6][1] == 'O'))
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

void PemainWin()
{
    if (XO == 'X' && !draw)
    {
        system("cls");
        p1menang++;
        printf("%s memenangkan permainan!", pemain1);
        printf("\nHasil Akhir :\n");
        BoardDinamis();
    }
    else if (XO == 'O' && !draw)
    {
        system("cls");
        p2menang++;
        printf("%s memenangkan permainan!", pemain2);
        printf("\nHasil Akhir :\n");
        BoardDinamis();
    }
    else
    {
        system("cls");
        printf("Permainan Seri!");
        printf("\nHasil Akhir :\n");
        BoardDinamis();
    }
}

void HowToPlay()
{
}

// Modul Prosedur untuk tampilan akhir
void Closing()
{
    printf("\n\t  TTTTTTTT   HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UU    UU  TTTTTTTT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN NN   NN  GG        DD     DD   UU    UU     TT\n");
    printf("\t     TT      HHHHHHH  EEEEEE       DD      DD  II  NN  NN  NN  GG  GGGG  DD      DD  UU    UU     TT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN   NN NN  GG    GG  DD     DD   UU    UU     TT\n");
    printf("\t     TT      HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UUUUUUUU     TT\n\n");
    printf("\t  =====================================================================================================\n\n");
    printf("\t\t\t   TTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE  \n");
    printf("\t\t\t     TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE   \n ");
    printf("\t\t\t     TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE  \n\n\n");
    printf("\t\t\t         TERIMA KASIH TELAH BERMAIN      \n\n");
    printf("\t\t\t               Sampai Jumpa!! \n");
}