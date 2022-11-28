#include <stdio.h>
#include <time.h>

char papan[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char XO = 'O';
int pilihan;
bool draw = false;

// Deklarasi Variabel Koordinat
typedef struct
{
    int baris, kolom;
} Koordinat;

// Cetak Cover
void cover()
{
    printf("\t\t\t\t##### #  # ####  ##  # #   # #### ##  #  # #####\n");
    printf("\t\t\t\t  #   #  # #     # # # ##  # #    # # #  #   #\n");
    printf("\t\t\t\t  #   #### ####  # # # # # # #### # # #  #   #\n");
    printf("\t\t\t\t  #   #  # #     # # # #  ## #  # # # #  #   #\n");
    printf("\t\t\t\t  #   #  # ####  ##  # #   # #### ##  ####   #\n\n");
    printf("\t\t\t\t                 TIC TAC TOE                  \n\n");
}

// Cetak Menu Utama
void menuUtama()
{
    printf("\t\t\t\t                 1. Mulai Main                \n");
    printf("\t\t\t\t                 2. Cara Bermain              \n");
    printf("\t\t\t\t                 3. Quit Game                 \n");
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
}

// modul function bertipe boolean berfungsi sebagai countdown timer
bool EstimasiWaktu(){
    unsigned int x_hours=0;
	unsigned int x_minutes=0;
	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;

	clock_t x_startTime,x_countTime;
	count_down_time_in_secs=10;  // input detik

 
    x_startTime=clock();  // menjalankan timer
    time_left=count_down_time_in_secs-x_seconds;   // update timer

	while (time_left>0) 
	{
		x_countTime=clock(); // update perbedaan timer
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
		x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
		x_hours=x_minutes/60;

		time_left=count_down_time_in_secs-x_seconds; // mendapatkan waktu tersisa
	}

    if (time_left == 0)
    {
        return true;
    }
    
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