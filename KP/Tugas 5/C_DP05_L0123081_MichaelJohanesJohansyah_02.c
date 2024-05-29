// Michael Johanes Johansyah
// L0123081
// Kelas C


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maksimum panjang nama barang
#define max_nama_brg 50

// Fungsi untuk menghitung total harga
double calculateTotal(int *jumlah, double *harga, int jenisBrg) {
    double total = 0.0;
    for (int i = 0; i < jenisBrg; i++) {
        total += jumlah[i] * harga[i];
    }
    return total;
}

int main() {
    int jenisBrg;
    printf("Selamat datang di BetaMaret, selamat berbelanja!\n");
    printf("Berapa jenis barang yang akan kamu beli?: ");
    scanf("%d", &jenisBrg);

    // Alokasikan memori dinamis untuk array jumlah, harga, dan nama barang
    int *jumlah = (int *)malloc(jenisBrg * sizeof(int));
    double *harga = (double *)malloc(jenisBrg * sizeof(double));
    char **nama = (char **)malloc(jenisBrg * sizeof(char *));

    if (jumlah == NULL || harga == NULL || nama == NULL) {
        printf("Terjadi error, silahkan masukkan jumlah yang benar.\n");
        return 1;
    }

    // Alokasikan memori untuk setiap string nama barang
    for (int i = 0; i < jenisBrg; i++) {
        nama[i] = (char *)malloc(max_nama_brg);
    }

    // Masukkan detail produk ke dalam array
    for (int i = 0; i < jenisBrg; i++) {
        printf("\nBarang ke-%d:\n", i + 1);
        printf("Nama Barang: ");
        fflush(stdin); // Membersihkan buffer stdin
        fgets(nama[i], max_nama_brg, stdin); // Menggunakan fgets untuk input nama
        nama[i][strcspn(nama[i], "\n")] = 0; // Menghapus karakter newline dari nama
        printf("Jumlah Barang: ");
        scanf("%d", &jumlah[i]);
        printf("Harga: ");
        scanf("%lf", &harga[i]);
    }

    // Tampilkan detail belanja
    printf("\nTerimakasih sudah berbelanja!");
    printf("\nDetail Pembelian:\n\n");
    for (int i = 0; i < jenisBrg; i++) {
        printf("Barang ke-%d: \nNama: %s \nJumlah: %d \nHarga: %.2lf\n\n", i + 1, nama[i], jumlah[i], harga[i]);
    }

    // Hitung total harga
    double totalHarga = calculateTotal(jumlah, harga, jenisBrg);
    printf("Total Harga: %.2lf\n", totalHarga);

    // Bebaskan memori yang dialokasikan
    for (int i = 0; i < jenisBrg; i++) {
        free(nama[i]);
    }
    free(jumlah);
    free(harga);
    free(nama);

    return 0;
}
