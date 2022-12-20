#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Deklarasi tipe data baru bernama Koordinat
typedef struct
{
    int baris, kolom;
} Koordinat;

// Deklarasi tipe data baru bernama Player
typedef struct
{
    char nama[20];
    int menang;
} Player;

char papan[7][7];  // Variabel ini digunakan untuk mengisi simbol berdasarkan nomor yang diinput user
char XO = 'O';     // Variabel ini digunakan untuk menginiliasasi dan menampung simbol yang digunakan pemain
bool draw = false; // Variabel ini digunakan untuk inisialiasi dan penentu permainan dikatakan seri atau tidak

/*Deskripsi Modul
Prosedur
Modul ini bertujuan sebagai tampilan awal permainan berupa pengenalan nama permainan
I.S : cover belum tampil
F.S : cover tampil
*/
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

/*Deskripsi Modul
Prosedur
Modul ini bertujuan sebagai tampilan pemilihan menu oleh user
I.S : menuUtama belum tampil
F.S : menuUtama tampil
*/
void menuUtama()
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t===================================================================\n\n");
    printf("\t\t\t                          MAIN MENU      \n\n");
    printf("\t\t\t                       1. Mulai Permainan \n");
    printf("\t\t\t                       2. Cara Bermain    \n");
    printf("\t\t\t                       3. Score Board \n");
    printf("\t\t\t                       4. Keluar Permainan\n");
    printf("\t\t\tPilih Menu : ");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan sebagai tampilan dan pengisian nama pemain
I.S : Nama pemain belum terisi
F.S : Nama pemain terisi
*/
void InputNamaPemain(Player *p1, Player *p2)
{
    printf("\n\t\t\tTTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE \n");
    printf("\t\t\t  TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE  \n ");
    printf("\t\t\t  TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE \n\n");
    printf("\t\t\t=================================================================\n\n");
    printf("\t\t\t  Masukkan Nama Pemain 1 (O) : ");
    scanf(" %[^\n]", &p1->nama);
    printf("\t\t\t  Masukkan Nama Pemain 2 (X) : ");
    scanf(" %[^\n]", &p2->nama);
    if (strlen(p1->nama) >= 12 || strlen(p2->nama) >= 12)
    {
        printf("\n\t\t\tMaksimal Nama Pemain Adalah 12 Karakter...");
        getch();
        system("cls");
        InputNamaPemain(p1, p2);
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan sebagai tampilan pemilihan dimensi oleh user
I.S : PilihDimensi belum tampil
F.S : PilihDimensi tampil
*/
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
    printf("\t\t\t                       4. Kembali ke layar utama\n");
    printf("\t\t\tPilih : ");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan menjadi papan referensi dalam pengisian papan dimensi 3x3 oleh user
I.S : Papan referensi belum tampil
F.S : Papan referensi tampil
*/
void boardRef3(Player p1, Player p2)
{
    printf("\n\tPilih salah satu kolom dengan menginputkan nomor\n");
    printf("\t 1  | 2  | 3  \t\t\t\t\t\t%s : %d\n", p1.nama, p1.menang);
    printf("\t----|----|----\t\t\t\t\t\t%s : %d\n", p2.nama, p2.menang);
    printf("\t 4  | 5  | 6  \n");
    printf("\t----|----|----\n");
    printf("\t 7  | 8  | 9  \n");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan menjadi papan referensi dalam pengisian papan dimensi 5x5 oleh user
I.S : Papan referensi belum tampil
F.S : Papan referensi tampil
*/
void boardRef5(Player p1, Player p2)
{
    printf("\n\tPilih salah satu kolom dengan menginputkan nomor\n");
    printf("\t 1  | 2  | 3  | 4  | 5  \t\t\t\t\t\t%s : %d\n", p1.nama, p1.menang);
    printf("\t----|----|----|----|----\t\t\t\t\t\t%s : %d\n", p2.nama, p2.menang);
    printf("\t 6  | 7  | 8  | 9  | 10 \n");
    printf("\t----|----|----|----|----\n");
    printf("\t 11 | 12 | 13 | 14 | 15 \n");
    printf("\t----|----|----|----|----\n");
    printf("\t 16 | 17 | 18 | 19 | 20 \n");
    printf("\t----|----|----|----|----\n");
    printf("\t 21 | 22 | 23 | 24 | 25 \n");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan menjadi papan referensi dalam pengisian papan dimensi 7x7 oleh user
I.S : Papan referensi belum tampil
F.S : Papan referensi tampil
*/
void boardRef7(Player p1, Player p2)
{
    printf("\tPilih salah satu kolom dengan menginputkan nomor\n");
    printf("\t 1  | 2  | 3  | 4  | 5  | 6  | 7  \t\t\t\t\t\t%s : %d\n", p1.nama, p1.menang);
    printf("\t----|----|----|----|----|----|----\t\t\t\t\t\t%s : %d\n", p2.nama, p2.menang);
    printf("\t 8  | 9  | 10 | 11 | 12 | 13 | 14 \n");
    printf("\t----|----|----|----|----|----|----\n");
    printf("\t 15 | 16 | 17 | 18 | 19 | 20 | 21 \n");
    printf("\t----|----|----|----|----|----|----\n");
    printf("\t 22 | 23 | 24 | 25 | 26 | 27 | 28 \n");
    printf("\t----|----|----|----|----|----|----\n");
    printf("\t 29 | 30 | 31 | 32 | 33 | 34 | 35 \n");
    printf("\t----|----|----|----|----|----|----\n");
    printf("\t 36 | 37 | 38 | 39 | 40 | 41 | 42 \n");
    printf("\t----|----|----|----|----|----|----\n");
    printf("\t 43 | 44 | 45 | 46 | 47 | 48 | 49 \n");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan sebagai tampilan pengingat waktu bagi user
I.S : pengingat waktu belum tampil
F.S : pengingat waktu tampil
*/
void tampilanPengingatWaktu()
{
    printf("\n\tWaktu anda hanya 10 detik, lebih dari itu maka giliran bermain akan terganti\n");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk inisialisasi isi baris kolom pada papan
I.S : Isi pada papan belum terinisialisasi
F.S : Isi pada papan terinisialisasi
*/
void isiPapan(int flag)
{
    int x = 1;
    for (int i = 0; i < flag; i++)
    {
        for (int j = 0; j < flag; j++)
        {
            char c = x + '0';
            papan[i][j] = ' ';
            x++;
        }
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk membuat desain papan
I.S : Papan permainan belum tampil
F.S : Papan permainan tampil
*/
void BoardDinamis(int flag)
{
    for (int i = 0; i < flag; i++)
    {
        printf("\t");
        for (int j = 0; j < flag; j++)
        {
            printf(" %c ", papan[i][j]);
            if (j != flag - 1)
            {
                printf("%c", 186);
            }
        }
        printf("\n");
        printf("\t");
        for (int j = 0; j < flag; j++)
        {
            /* code */
            if (i < flag - 1)
            {
                /* code */
                printf("%c%c%c", 205, 205, 205);
                if (j != flag - 1)
                {
                    printf("%c", 206);
                }
            }
        }
        printf("\n");
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menentukan giliran bermain pemain 1 dan pemain 2 dan
proses pengisian baris dan kolom dengan simbol
I.S : Giliran pemain belum berganti dan baris kolom kosong
F.S : Giliran pemain berganti dan baris kolom terisi simbol
*/
void inputGiliranPemain(Player p1, Player p2, int *pilihan)
{
    if (XO == 'O')
    {
        printf("\tGiliran %s : ", p1.nama);
    }
    else if (XO == 'X')
    {
        printf("\tGiliran %s : ", p2.nama);
    }
    scanf("%d", &*pilihan);
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menentukan giliran bermain pemain 1 dan pemain 2 dan
proses pengisian baris dan kolom dengan simbol
I.S : Giliran pemain belum berganti dan baris kolom kosong
F.S : Giliran pemain berganti dan baris kolom terisi simbol
*/
void GiliranBermain()
{
    if (XO == 'O')
    {
        XO = 'X';
    }
    else
    {
        XO = 'O';
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menentukan giliran bermain pemain 1 dan pemain 2 dan
proses pengisian baris dan kolom dengan simbol
I.S : Giliran pemain belum berganti dan baris kolom kosong
F.S : Giliran pemain berganti dan baris kolom terisi simbol
*/
void inputSimbolKedalamPapan(Player p1, Player p2, int flag)
{
    Koordinat lokasi;
    time_t waktu = time(NULL); // variabel yang berisi waktu saat modul dijalankan
    int pilihan;               // Variabel ini digunakan untuk menampung posisi yang dipilih user untuk mengisi papan

    if (flag == 3)
    {
        inputGiliranPemain(p1, p2, &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\n\t!!!!!Waktu Habis!!!!!\n");
            GiliranBermain();
            printf("\n\tTekan Enter Untuk Lanjut..\n");
            getch();
            system("cls");
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
                    inputSimbolKedalamPapan(p1, p2, flag);
                }

                // cetakPapan3();
            }
            system("cls");
        }
    }
    else if (flag == 5)
    {
        inputGiliranPemain(p1, p2, &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\n!!!!!Waktu Habis!!!!!\n\n");
            GiliranBermain();
            printf("\n\tTekan Enter Untuk Lanjut..\n");
            getch();
            system("cls");
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
                    inputSimbolKedalamPapan(p1, p2, flag);
                }

                // cetakPapan3();
            }
            system("cls");
        }
    }
    else if (flag == 7)
    {
        inputGiliranPemain(p1, p2, &pilihan);
        time_t waktuSetelahInput = time(NULL); // variabel yang berisi waktu saat user input keyboard
        if (waktuSetelahInput - waktu >= 10)
        {
            printf("\n\t!!!!!Waktu Habis!!!!!\n\n");
            GiliranBermain();
            printf("\n\tTekan Enter Untuk Lanjut..\n");
            getch();
            system("cls");
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
                inputSimbolKedalamPapan(p1, p2, flag);
            }

            // cetakPapan7();
        }
        system("cls");
    }
}

/*Deskripsi Modul
Function
Modul ini bertujuan mengembalikan nilai true dan false pada permainan dimensi papan 3x3
Apabila true, maka permainan dimensi 3x3 dapat dilakukan
Apabila false, maka permainan dimensi 3x3 berhenti karena adanya kondisi menang atau seri
*/
bool GamePlay3(int flag)
{
    /*cek horizontal dan vertikal*/
    for (int i = 0; i < flag; i++)
    {
        if ((papan[i][0] == 'X' && papan[i][1] == 'X' && papan[i][2] == 'X') || (papan[i][0] == 'O' && papan[i][1] == 'O' && papan[i][2] == 'O') ||
            (papan[0][i] == 'X' && papan[1][i] == 'X' && papan[2][i] == 'X') || (papan[0][i] == 'O' && papan[1][i] == 'O' && papan[2][i] == 'O'))
        {
            return false;
        }
    }

    /*cek diagonal*/
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X') || (papan[0][0] == 'O' && papan[1][1] == 'O' && papan[2][2] == 'O') ||
        (papan[0][2] == 'X' && papan[1][1] == 'X' && papan[2][0] == 'X') || (papan[0][2] == 'O' && papan[1][1] == 'O' && papan[2][0] == 'O'))
    {
        return false;
    }

    for (int i = 0; i < flag; i++)
    { /*cek draw*/

        for (int j = 0; j < flag; j++)
        {

            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return true;
        }
    }

    draw = true;

    return false;
}

/*Deskripsi Modul
Function
Modul ini bertujuan mengembalikan nilai true dan false pada permainan dimensi papan 5x5
Apabila true, maka permainan dimensi 5x5 dapat dilakukan
Apabila false, maka permainan dimensi 5x5 berhenti karena adanya kondisi menang atau seri
*/
bool GamePlay5(int flag)
{
    /*cek horizontal dan vertikal*/
    for (int i = 0; i < flag; i++)
    {
        if ((papan[i][0] == 'X' && papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X') || (papan[i][0] == 'O' && papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O') ||
            (papan[i][1] == 'X' && papan[i][2] == 'X' && papan[i][3] == 'X' && papan[i][4] == 'X') || (papan[i][1] == 'O' && papan[i][2] == 'O' && papan[i][3] == 'O' && papan[i][4] == 'O') ||
            (papan[0][i] == 'X' && papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X') || (papan[0][i] == 'O' && papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O') ||
            (papan[1][i] == 'X' && papan[2][i] == 'X' && papan[3][i] == 'X' && papan[4][i] == 'X') || (papan[1][i] == 'O' && papan[2][i] == 'O' && papan[3][i] == 'O' && papan[4][i] == 'O'))
        {
            return false;
        }
    }

    /*cek diagonal*/
    if ((papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X') || (papan[0][0] == 'O' && papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O') ||
        (papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X') || (papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O') ||
        (papan[1][0] == 'X' && papan[2][1] == 'X' && papan[3][2] == 'X' && papan[4][3] == 'X') || (papan[1][0] == 'O' && papan[2][1] == 'O' && papan[3][2] == 'O' && papan[4][3] == 'O') ||
        (papan[0][1] == 'X' && papan[1][2] == 'X' && papan[2][3] == 'X' && papan[3][4] == 'X') || (papan[0][1] == 'O' && papan[1][2] == 'O' && papan[2][3] == 'O' && papan[3][4] == 'O') ||

        (papan[0][4] == 'X' && papan[1][3] == 'X' && papan[2][2] == 'X' && papan[3][1] == 'X') || (papan[0][4] == 'O' && papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O') ||
        (papan[1][3] == 'X' && papan[2][2] == 'X' && papan[3][1] == 'X' && papan[4][0] == 'X') || (papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O' && papan[4][0] == 'O') ||
        (papan[1][4] == 'X' && papan[2][3] == 'X' && papan[3][2] == 'X' && papan[4][1] == 'X') || (papan[1][4] == 'O' && papan[2][3] == 'O' && papan[3][2] == 'O' && papan[4][1] == 'O') ||
        (papan[0][3] == 'X' && papan[1][2] == 'X' && papan[2][1] == 'X' && papan[3][0] == 'X') || (papan[0][3] == 'O' && papan[1][2] == 'O' && papan[2][1] == 'O' && papan[3][0] == 'O'))
    {
        return false;
    }

    for (int i = 0; i < flag; i++)
    { /*cek draw*/

        for (int j = 0; j < flag; j++)
        {
            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return true;
        }
    }

    draw = true;

    return false;
}

/*Deskripsi Modul
Function
Modul ini bertujuan mengembalikan nilai true dan false pada permainan dimensi papan 7x7
Apabila true, maka permainan dimensi 7x7 dapat dilakukan
Apabila false, maka permainan dimensi 7x7 berhenti karena adanya kondisi menang atau seri
*/
bool GamePlay7(flag)
{
    /*cek horizontal dan vertikal*/
    for (int i = 0; i < flag; i++)
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

    /*cek diagonal*/
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

    for (int i = 0; i < flag; i++)
    { /*cek draw*/

        for (int j = 0; j < flag; j++)
        {
            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return true;
        }
    }

    draw = true;

    return false;
}

/* Deskripsi Modul */
// void inputTextToFile()
// {
//     FILE *fp; // file pointer
//     char ch;
//     fp = fopen("file_handle.c", "r");
//     while (1)
//     {
//         ch = fgetc(fp); // Each character of the file is read and stored in the character file.
//         if (ch == EOF)
//             break;
//         printf("%c", ch);
//     }
//     fclose(fp);
// }

/* DESKRIPSI MODUL
Function
Modul ini bertujuan untuk mengembalikan nilai yang berisi banyak baris file highscore.txt
*/
int hitungBarisFile()
{
    FILE *fp;
    int count = 0; // Line counter (result)
    char filename[50] = "highscore.txt";
    char c; // To store a character read from file

    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);

    return count;
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menampilkan teks cara bermain permainan Tic Tac Toe
I.S : Cara bermain pada permainan Tic Tac Toe belum tampil
F.S : Cara bermain pada permainan Tic Tac Toe tampil
*/
void displayHowToPlay() /* displayHowToPlay */
{
    FILE *FF; // penunjuk ke file
    char CC;  // var penunjuk karakter yang dibaca

    if ((FF = fopen("HOW TO PLAY.txt", "r")) == NULL)
    { // Buka file mode baca
        printf("Pembukaan File Gagal !");
        exit(1); // keluar program
    }

    while ((CC = getc(FF)) != EOF)
    {              // CC akan berisi karakter yg dibaca, akhir teks dengan EOF
        putch(CC); // baca dan tampilkan ke layar
    }

    fclose(FF);
    printf("\n\nPress any key to main menu... ");
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menuliskan nama pemain dan jumlah menang ke file highscore.txt
I.S : Nama pemain belum terinput ke file highscore.txt
F.S : Nama pemain sudah terinput ke file highscore.txt
*/
void tulisHighscore(Player pemain)
{
    FILE *fptr;

    fptr = fopen("highscore.txt", "a+"); // variabel yang menampung nama file dan fungsi yang akan digunakan

    if (fptr == NULL) // program akan tertutup apabila file tidak ada
    {
        exit(1);
    }

    fprintf(fptr, "%s %d\n", pemain.nama, pemain.menang); // menulis nama pemain dan jumlah menang kedalam file
    fclose(fptr);
}

void sortHighscore()
{
    FILE *fptr;
    int total_line = hitungBarisFile();
    Player pemain[total_line], temp;
    temp.nama[20] = "default";
    temp.menang = 0;

    fptr = fopen("highscore.txt", "r"); // variabel yang menampung nama file dan fungsi yang akan digunakan
    // printf("total line = %d\n", total_line);

    if (fptr == NULL) // program akan tertutup apabila file tidak ada
    {
        exit(1);
    }
    int j = 0;
    while (fscanf(fptr, "%s %d\n", pemain[j].nama, &pemain[j].menang) != EOF) // membaca nama pemain dan jumlah menang dari file
    {
        j++;
    }
    fclose(fptr);
    for (int i = 0; i < total_line; i++)
    {
        for (int j = i + 1; j < total_line; j++)
        {
            if (strcmp(pemain[i].nama, pemain[j].nama) == 0)
            {
                pemain[i].menang = pemain[i].menang + pemain[j].menang;
                for (int k = j; k < total_line; k++)
                {
                    pemain[k] = pemain[k + 1];
                }
                total_line--;
                j--;
            }
        }
    }
    for (int i = 0; i < total_line; i++)
    {
        for (int j = i + 1; j < total_line; j++)
        {
            if (pemain[i].menang < pemain[j].menang)
            {
                temp = pemain[i];
                pemain[i] = pemain[j];
                pemain[j] = temp;
            }
        }
    }

    fptr = fopen("highscore.txt", "w");

    for (int i = 0; i < total_line; i++)
    {
        fprintf(fptr, "%s %d\n", pemain[i].nama, pemain[i].menang);
    }

    fclose(fptr);
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menampilkan keadaan pemain menang atau seri di setiap 1 kali putaran permainan
I.S : Keadaan pemain menang atau seri tidak diketahui
F.S : Keadaan pemain menang atau seri diketahui
*/
void getWinner(Player *p1, Player *p2, bool draw, int flag)
{
    if (XO == 'X' && !draw)
    {
        system("cls");
        p1->menang = p1->menang + 1;
        printf("\n\t%s memenangkan permainan!", p1->nama);
        printf("\n\tHasil Akhir :\n\n");
        BoardDinamis(flag);
    }
    else if (XO == 'O' && !draw)
    {
        system("cls");
        p2->menang = p2->menang + 1;
        printf("\n\t%s memenangkan permainan!", p2->nama);
        printf("\n\tHasil Akhir :\n\n");
        BoardDinamis(flag);
    }
    else
    {
        system("cls");
        printf("Permainan Seri!");
        printf("\nHasil Akhir :\n\n");
        BoardDinamis(flag);
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menampilkan nama pemain dalam bentuk uppercase
I.S : array of char dari nama pemain belum sepenuhnya uppercase
F.S : array of char dari nama pemain sudah sepenuhnya uppercase
*/
void kapitalisasiNamaPemain(Player pemain, char p[50])
{
    int count = strlen(pemain.nama);
    for (int i = 0; i < count + 1; i++)
    {
        p[i] = toupper(pemain.nama[i]);
    }
}

void readFileForScoreboard()
{
    FILE *ff;
    int countLine = hitungBarisFile();
    Player *pemain[countLine];
    int x = 0;
    while (fscanf(ff, "%s %d\n", pemain[x]->nama, &pemain[x]->menang) != EOF) // membaca nama pemain dan jumlah menang dari file
    {
        x++;
    }
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk membuat tampilan papan skor
I.S : Papan skor belum tampil
F.S : Papan skor belum tampil
*/
void scoreboard()
{
    int c = 1;
    FILE *ff;
    int countLine = hitungBarisFile();
    Player pemain[countLine];
    ff = fopen("highscore.txt", "r");
    int x = 0;
    while (fscanf(ff, "%s %d\n", pemain[x].nama, &pemain[x].menang) != EOF) // membaca nama pemain dan jumlah menang dari file
    {
        x++;
    }
    system("cls");
    printf("\n               SCORE BOARD                   ");
    printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n %c  No  %c Tanggal %c Nama Player %c Score %c", 186, 186, 186, 186, 186);
    printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    for (int i = 0; i < countLine; i++)
    {
        printf("\n %c  %d", 186, c);
        if (c < 10)
        {
            printf("   %c         %c%s", 186, 186, pemain[i].nama);
        }
        else
        {
            printf("  %c         %c%s", 186, 186, pemain[i].nama);
        }

        for (int j = 0; j < 13 - strlen(pemain[i].nama); j++)
        {
            printf(" ");
        }
        printf("%c %d", 186, pemain[i].menang, 186);
        if (pemain[i].menang < 10)
        {
            printf("     %c", 186);
        }
        else
        {
            printf("    %c", 186);
        }

        c++;
    }
    printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 188);

    printf("\n\nPress any key to main menu... \n");
    fclose(ff);
    getch();
    main();
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk menampilkan hasil akhir permainan
I.S : Hasil akhir permainan belum diketahui
F.S : Hasil akhir permainan diketahui
*/
void displayClosing(Player pemain1, Player pemain2)
{
    char p1[50];
    char p2[50];
    kapitalisasiNamaPemain(pemain1, &p1);
    kapitalisasiNamaPemain(pemain2, &p2);

    printf("\n\t  TTTTTTTT   HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UU    UU  TTTTTTTT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN NN   NN  GG        DD     DD   UU    UU     TT\n");
    printf("\t     TT      HHHHHHH  EEEEEE       DD      DD  II  NN  NN  NN  GG  GGGG  DD      DD  UU    UU     TT\n");
    printf("\t     TT      HH   HH  EE           DD     DD   II  NN   NN NN  GG    GG  DD     DD   UU    UU     TT\n");
    printf("\t     TT      HH   HH  EEEEEEEE     DDDDDDD     II  NN      NN  GGGGGGGG  DDDDDDD     UUUUUUUU     TT\n\n");
    printf("\t  =====================================================================================================\n\n");
    printf("\t\t\t   TTTTTT  II  CCCCCC   TTTTTT   AA    CCCCCC   TTTTTT  OOO   EEEEEE  \n");
    printf("\t\t\t     TT    II  CC         TT    AAAA   CC         TT   OO OO  EEE   \n ");
    printf("\t\t\t     TT    II  CCCCCC     TT   AA  AA  CCCCCC     TT    OOO   EEEEEE  \n\n\n");
    printf("\t\t\t                         HASIL AKHIR      \n\n");
    printf("\t\t\t               %s MEMENANGKAN %d KALI PERMAINAN \n", p1, pemain1.menang);
    printf("\t\t\t               %s MEMENANGKAN %d KALI PERMAINAN \n", p2, pemain2.menang);
    tulisHighscore(pemain1);
    tulisHighscore(pemain2);
    sortHighscore();
}

/*Deskripsi Modul
Prosedur
Modul ini bertujuan untuk mengakhiri permainan
I.S : Program dan permainan berjalan
F.S : Program berhenti
*/
void KeluarPermainan()
{
    exit(0);
}