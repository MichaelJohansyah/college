#include <stdio.h>

// Struct untuk merepresentasikan informasi mahasiswa
struct Mahasiswa {
    char nama[50];
    int nim;
    float nilai;
};

// Enum untuk status mahasiswa (Aktif atau Tidak Aktif)
enum Status {
    AKTIF,
    TIDAK_AKTIF
};

int main() {
    // Membuat array dari struct Mahasiswa untuk menyimpan data mahasiswa
    struct Mahasiswa mahasiswas[3];

    // Mengisi data mahasiswa
    mahasiswas[0].nim = 101;
    sprintf(mahasiswas[0].nama, "John Doe");
    mahasiswas[0].nilai = 85.5;

    mahasiswas[1].nim = 102;
    sprintf(mahasiswas[1].nama, "Jane Doe");
    mahasiswas[1].nilai = 90.0;

    mahasiswas[2].nim = 103;
    sprintf(mahasiswas[2].nama, "Bob Smith");
    mahasiswas[2].nilai = 75.2;

    // Menggunakan Enum untuk status mahasiswa
    enum Status status = AKTIF;

    // Menulis data mahasiswa ke dalam file
FILE *file = fopen("mahasiswa.txt", "w");

if (file != NULL) {
    for (int i = 0; i < 3; ++i) {
        fprintf(file, "%s,%d,%.2f,%d\n", mahasiswas[i].nama, mahasiswas[i].nim, mahasiswas[i].nilai, status);
    }

    fclose(file);
    printf("Data mahasiswa telah ditulis ke dalam file.\n");
} else {
    printf("Gagal membuka file untuk penulisan.\n");
}

// Membaca data mahasiswa dari file
file = fopen("mahasiswa.txt", "r");

if (file != NULL) {
    printf("\nMembaca data mahasiswa dari file:\n");

    while (fscanf(file, "%49[^,],%d,%f,%d\n", mahasiswas[0].nama, &mahasiswas[0].nim, &mahasiswas[0].nilai, &status) != EOF) {
        printf("Nama: %s, NIM: %d, Nilai: %.2f, Status: %s\n", mahasiswas[0].nama, mahasiswas[0].nim, mahasiswas[0].nilai, status == AKTIF ? "Aktif" : "Tidak Aktif");
    }

    fclose(file);
} else {
    printf("Gagal membuka file untuk pembacaan.\n");
}


    return 0;
}
