#include <stdio.h>

int main() {
    char lanjut;
    //Do statement untuk mengulangi kode dengan suatu syarat
    do {
        int angka;
        
        
        printf("Masukkan angka bulan (1-12): ");
        scanf("%d", &angka);

        // Switch statement untuk mengkonversi angka menjadi nama bulan
        // Break statement untuk menghentikan switch
        switch (angka) {
            case 1:
                printf("Bulan %d adalah Januari\n", angka);
                break;
            case 2:
                printf("Bulan %d adalah Februari\n", angka);
                break;
            case 3:
                printf("Bulan %d adalah Maret\n", angka);
                break;
            case 4:
                printf("Bulan %d adalah April\n", angka);
                break;
            case 5:
                printf("Bulan %d adalah Mei\n", angka);
                break;
            case 6:
                printf("Bulan %d adalah Juni\n", angka);
                break;
            case 7:
                printf("Bulan %d adalah Juli\n", angka);
                break;
            case 8:
                printf("Bulan %d adalah Agustus\n", angka);
                break;
            case 9:
                printf("Bulan %d adalah September\n", angka);
                break;
            case 10:
                printf("Bulan %d adalah Oktober\n", angka);
                break;
            case 11:
                printf("Bulan %d adalah November\n", angka);
                break;
            case 12:
                printf("Bulan %d adalah Desember\n", angka);
                break;
            default:
                printf("Angka yang dapat kamu masukkan hanya dari angka 1-12\n");
        }

        
        printf("Apakah Anda ingin melanjutkan? (y/n): ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y'); // While statement untuk mengulangi kode selama pengguna ingin melanjutkan

    return 0;
}
