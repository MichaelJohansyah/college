#include <stdio.h>
#include<string.h>

int main()
{
    int skor, nilai;
    //int untuk deklarasikan variabel yang akan digunakan kedepannya

    printf("Sistem untuk mengonversi skor mahasiswa menjadi nilai IPK\n");
    printf("Masukkan skormu : ");
    scanf("%d", &skor);
    //input skor disini

    while (skor > 100 || skor < 0) //gunanya while supaya bisa berulang
    {printf ("Harap masukkan skor mahasiswa di rentang 0 - 100.\n");
        printf("Sistem untuk mengonversi skor mahasiswa menjadi nilai IPK\n");
        printf("Masukkan skormu : ");
        scanf("%d", &skor);
    
    }
    
    //else if untuk mencari kondisi yang benar sesuai skor mahasiswa


    if (skor >= 85 && skor <= 100 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 4.00 dengan predikat A", skor);}

    else if (skor < 85 && skor >= 80 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 3.70 dengan predikat A-", skor);}

    else if (skor < 80 && skor >= 75 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 3.30 dengan predikat B+", skor);}

    else if (skor < 75 && skor >= 70 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 3.00 dengan predikat B", skor);}

    else if (skor < 70 && skor >= 65 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 2.70 dengan predikat C+", skor);}

    else if (skor < 65 && skor >= 60 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 2.00 dengan predikat C", skor);}

    else if (skor < 60 && skor >= 55 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 1.00 dengan predikat D", skor);}

    else if (skor < 55 && skor >= 0 )
    {printf("Dengan skor %d, IPK yang kamu dapatkan adalah 0.00 dengan predikat E", skor);}

}