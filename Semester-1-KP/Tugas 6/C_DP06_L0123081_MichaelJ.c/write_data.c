#include <stdio.h>
#include "user_info.h"

int main() {
    // Membuat struct UserInfo untuk menyimpan data pengguna
    struct UserInfo user;

    // Meminta pengguna memasukkan informasi
    printf("Masukkan Nama Panggilan: ");
    fgets(user.nama, sizeof(user.nama), stdin);

    printf("Masukkan Umur: ");
    scanf("%d", &user.umur);

    printf("Masukkan Jenis Kelamin (0: Pria, 1: Wanita, 2: Lainnya): ");
    scanf("%d", &user.jenisKelamin);

    // Menulis data pengguna ke dalam file
    FILE *file = fopen("user_data.txt", "a");  // Mode "a" untuk menambahkan data ke file

    if (file != NULL) {
        fprintf(file, "%s %d %d\n", user.nama, user.umur, user.jenisKelamin);
        fclose(file);
        printf("Data pengguna telah ditulis ke dalam file 'user_data.txt'.\n");
    } else {
        printf("Gagal membuka file untuk penulisan.\n");
    }

    return 0;
}
