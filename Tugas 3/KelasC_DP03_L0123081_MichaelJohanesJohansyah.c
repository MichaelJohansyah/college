#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Tambahkan library math untuk operasi perpangkatan

// Deklarasi fungsi-fungsi operasi matematika
double tambah(double a, double b) {
    return a + b;
}

double kurang(double a, double b) {
    return a - b;
}

double kali(double a, double b) {
    return a * b;
}

double bagi(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Pembagian oleh nol tidak diizinkan.\n");
        exit(1);
    }
}

double pangkat(double a, double b) {
    return pow(a, b); // Menggunakan fungsi pow dari library math untuk perpangkatan
}

// Fungsi rekursif untuk menghitung ekspresi matematika
double hitungEkspresi() {
    char operator;
    double angka1, angka2, hasil;

    printf("Masukkan jenis operasi yang kamu mau (+, -, *, /, ^) atau huruf 'e' untuk keluar: ");
    scanf(" %c", &operator);

    if (operator == 'e' || operator == 'E') {
        exit(0);
    }

    printf("Masukkan dua angka yang kamu mau operasikan: \n");
    scanf("%lf %lf", &angka1, &angka2);

    switch (operator) {
        case '+':
            hasil = tambah(angka1, angka2);
            break;
        case '-':
            hasil = kurang(angka1, angka2);
            break;
        case '*':
            hasil = kali(angka1, angka2);
            break;
        case '/':
            hasil = bagi(angka1, angka2);
            break;
        case '^':
            hasil = pangkat(angka1, angka2);
            break;
        default:
            printf("Operasi tidak valid, coba ulangi lagi dengan jenis operasi dan angka yang benar.\n");
            hasil = 0.0;
    }

    printf("Hasil: %lf\n", hasil);

    return hitungEkspresi();
}

int main() {
    printf("Kalkulator Sederhana\n");

    double hasil = hitungEkspresi();

    printf("Hasil akhir: %lf\n", hasil);

    return 0;
}
