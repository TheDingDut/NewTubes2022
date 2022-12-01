#include <stdio.h>
#include <stdbool.h>
#include <time.h>

char papan[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char XO = 'X';
int pilihan;
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
    printf("\n\t    TTTTTTTT   HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UU    UU  TTTTTTTT\n");
    printf("\t       TT      HH   HH  EE           DD     DD   II  NN NN   NN  GG        DD     DD   UU    UU     TT\n");
    printf("\t       TT      HHHHHHH  EEEEEE       DD      DD  II  NN  NN  NN  GG  GGGG  DD      DD  UU    UU     TT\n");
    printf("\t       TT      HH   HH  EE           DD     DD   II  NN   NN NN  GG    GG  DD     DD   UU    UU     TT\n");
    printf("\t       TT      HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UUUUUUUU     TT\n\n");
    printf("\t  =====================================================================================================\n\n\n\n");
    printf("\t\t\t   TTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE  \n");
    printf("\t\t\t     TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE   \n ");
    printf("\t\t\t     TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE  \n\n\n");
    printf("\t\t\t\t                         Made By :                      \n");
    printf("\t\t\t\t               Hasna Fitriyani Khairunnisa \n");
    printf("\t\t\t\t               Muhammad Fikri Nur Sya'bani \n");
    printf("\t\t\t\t                     Naffa Lenteranisa           \n\n");
    printf("\t\t\t\t              Tekan Enter Untuk Lanjut . . .");
    getchar();
}

// Cetak Menu Utama
void menuUtama()
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t===================================================================\n\n");
    printf("\t\t\t                            MAIN MENU      \n\n");
    printf("\t\t\t                      1. Mulai Permainan \n");
    printf("\t\t\t                      2. Cara Bermain    \n");
    printf("\t\t\t                      3. Keluar Permainan\n\n\n");
    printf("\t\t                        Pilih Menu : ");
}

// Modul Prosedur untuk input nama pemain
void InputNamaPemain(char *p1, char *p2)
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t=================================================================\n\n");
    printf("\t\t\t                 Masukkan Nama Pemain 1 (X): ");
    scanf("%s", &*p1);
    printf("\t\t\t                 Masukkan Nama Pemain 2 (O): ");
    scanf("%s", &*p2);
}

// Modul prosedur untuk tampilan memilih simbol
// void PilihSimbol()
// {
//     printf("\t\t\tTTT  I  CCC   TTT   A    CCC   TTT  O   EEE \n");
//     printf("\t\t\t T   I  C      T   AAA   C      T  O O  EE  \n ");
//     printf("\t\t\t T   I  CCC    T  A   A  CCC    T   O   EEE \n\n");
//     printf("\t\t\t===============================================\n\n");
//     printf("\t\t\t              Pilih Simbol\n");
//     printf("\t\t\t              1. X\n");
//     printf("\t\t\t              2. O\n");
// }

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

// modul function bertipe boolean berfungsi sebagai countdown timer
// bool EstimasiWaktu()
// {
//     unsigned int x_hours = 0;
//     unsigned int x_minutes = 0;
//     unsigned int x_seconds = 0;
//     unsigned int x_milliseconds = 0;
//     unsigned int totaltime = 0, count_down_time_in_secs = 0, time_left = 0;

//     clock_t x_startTime, x_countTime;
//     count_down_time_in_secs = 10; // input detik

//     x_startTime = clock();                           // menjalankan timer
//     time_left = count_down_time_in_secs - x_seconds; // update timer

//     while (time_left > 0)
//     {
//         x_countTime = clock(); // update perbedaan timer
//         x_milliseconds = x_countTime - x_startTime;
//         x_seconds = (x_milliseconds / (CLOCKS_PER_SEC)) - (x_minutes * 60);
//         x_minutes = (x_milliseconds / (CLOCKS_PER_SEC)) / 60;
//         x_hours = x_minutes / 60;

//         time_left = count_down_time_in_secs - x_seconds; // mendapatkan waktu tersisa
//     }

//     if (time_left == 0)
//     {
//         return true;
//     }
// }

// modul prosedur untuk menentukan giliran dan mengubah state array pilihan baris dan kolom menjadi X / O
void giliran(pemain1, pemain2)
{
    Koordinat lokasi;
    time_t waktu = time(NULL); // variabel yang berisi waktu saat modul dijalankan

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

bool AkhirPermainan()
{

    for (int i = 0; i < 3; i++)
    { /*cek vertikal horizontal*/

        if (papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] ||

            papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i])

            return false;
    }

    if (papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] || /*checking diagonals*/

        papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0])
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