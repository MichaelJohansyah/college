#include <stdio.h>

int main() {
    // Membuka file untuk menghapus isi
    FILE *file = fopen("user_data.txt", "w");

    if (file != NULL) {
        fclose(file);
        printf("Isi file 'user_data.txt' telah dihapus.\n");
    } else {
        printf("Gagal membuka file untuk menghapus isi.\n");
    }

    return 0;
}
