#include <stdio.h>
#include "user_info.h"

int main() {
    // Membuka file untuk membaca data pengguna
    FILE *file = fopen("user_data.txt", "r");

    if (file != NULL) {
        // Menampilkan data pengguna yang tersedia
        printf("Data Pengguna yang Tersedia:\n");
        struct UserInfo user;

        while (fscanf(file, "%49s %d %d", user.nama, &user.umur, &user.jenisKelamin) != EOF) {
            printf("- Nama: %s, Umur: %d, Jenis Kelamin: %d\n", user.nama, user.umur, user.jenisKelamin);
        }

        fclose(file);
    } else {
        printf("Gagal membuka file untuk pembacaan.\n");
    }

    return 0;
}
