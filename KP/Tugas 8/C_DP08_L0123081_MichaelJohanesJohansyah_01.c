#include <stdio.h>

#define angka int // Pada baris ini saya mengubah simbol int menjadi "angka"
#define cetak printf // Pada baris ini saya mengubah fungsi printf menjadi "cetak"
#define baca scanf // Pada baris ini saya mengubah fungsi scanf menjadi "baca"

#define CONC(a, b) a ## b // Pada baris ini saya menggunakan fitur concat untuk menggabungkan a dan b menjadi ab. Dapat dilihat contoh penggunaannya di bawah

#define ca(s,number) printf(#s, number) 
// Pada baris ini saya mengubah fungsi printf khusus untuk printf(#s, number)  menjadi "ca" atau cetak angka
// Selain itu, saya juga menggunakan fungsi stringify yaitu dengan membuat s menjadi #s agar kedepannya tidak perlu memakai simbol ""



#define ba(g,number) scanf(#g, number)
// Pada baris ini saya mengubah fungsi scanf khusus untuk scanf(#g, number)  menjadi "ba" atau baca angka
// Selain itu, saya juga menggunakan fungsi stringify yaitu dengan membuat g menjadi #g agar kedepannya tidak perlu memakai simbol ""

void tesHitung(){

    angka CONC(num,ber); //Disini saya menggunakan fungsi concat agar a dan b, yang disini menjadi num dan ber menyatu dan menjadi variabel number

    cetak("\nMasukkan angka terserah berapa nanti dikalikan dengan 4 : ");
    ba(%d,&number);

    number *= 4;

    cetak("\nAngka yang kamu masukkan tadi berubah jadi = ");
    ca(%d,number);

}

angka main() {

    //Berikut ini contoh program untuk mengecek sistem operasi yang digunakan, sama seperti yang ada di materi.
    #if defined(_WIN32)
        cetak("Kamu menggunakan sistem operasi Windows\n");
    #elif defined(__linux__)
        cetak("Kamu menggunakan sistem operasi Linux\n");
    #elif defined(__APPLE__)
        cetak("Kamu menggunakan sistem operasi macOS X\n");
    #else
        cetak("Kamu menggunakan sistem operasi yang lain\n");
    #endif

    tesHitung();

    return 0;
}
