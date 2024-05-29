#include <stdarg.h> // Digunakan agar bisa menggunakan variable length argument
#include <stdio.h>

// Fungsi untuk mencari nilai minimum
int findMinimum(int num, ...) {
    va_list args;                    // Membuat variabel untuk menyimpan variadic arguments
    va_start(args, num);             // Menginisialisasi variabel args, num adalah jumlah argumen yang diberikan
    int min = va_arg(args, int);     // Mengambil nilai pertama dari variadic arguments sebagai nilai minimum awal

    for (int i = 1; i < num; i++) {
        int current = va_arg(args, int);  // Mengambil nilai berikutnya dari variadic arguments
        if (current < min) {
            min = current;                // Memperbarui nilai minimum jika nilai berikutnya lebih kecil
        }
    }

    va_end(args);  // Membersihkan variabel args setelah digunakan

    return min;    // Mengembalikan nilai minimum

}

// Fungsi untuk mencari nilai maksimum
int findMaximum(int num, ...) {
    va_list args;                         // Membuat variabel untuk menyimpan variadic arguments
    va_start(args, num);                  // Menginisialisasi variabel args, num adalah jumlah argumen yang diberikan
    int max = va_arg(args, int);          // Mengambil nilai pertama dari variadic arguments sebagai nilai maksimum awal

    for (int i = 1; i < num; i++) {
        int current = va_arg(args, int);  // Mengambil nilai berikutnya dari variadic arguments
        if (current > max) {
            max = current;                // Memperbarui nilai maksimum jika nilai berikutnya lebih besar
        }
    }

    va_end(args);        // Membersihkan variabel args setelah digunakan

    return max;          // Mengembalikan nilai maksimum
}


int main() {

    printf("\nProgram untuk mencari nilai minimum dan maksimum dari beberapa kumpulan angka\n");

    // Menampilkan angka-angka yang tersedia
    int angka[] = {17, 5, 87, 46, 101};                    //Pada bagian ini kita bisa mengubah nilai angka yang kita mau, dan hasil output
    int jumlahAngka = sizeof(angka) / sizeof(angka[0]);    // akan tetap memperlihatkan nilai minimum dan maksimumnya

    printf("Angka yang tersedia: ");
    for (int i = 0; i < jumlahAngka; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    // Contoh pemanggilan fungsi
    int minResult = findMinimum(jumlahAngka, angka[0], angka[1], angka[2], angka[3], angka[4]); // Bisa disesuaikan ingin ada berapa angka pada suatu kumpulan angka tersebut, 
    int maxResult = findMaximum(jumlahAngka, angka[0], angka[1], angka[2], angka[3], angka[4]); // Dapat diatur disini.

    // Menampilkan hasil
    printf("Nilai minimum: %d\n", minResult);
    printf("Nilai maksimum: %d\n", maxResult);

    return 0;
}
