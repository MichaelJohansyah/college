/*
NIM: L0123081
Nama: Michael Johanes Johansyah
Kelas: C
*/

#include <iostream> // Untuk mengaktifkan operasi input dan output standar (cout dan cin)
#include <list>     // Untuk menggunakan struktur data list

int main() {

    // Membuat list untuk menyimpan berbagai jenis buah
    // Disini menggunakan linked list
    std::list<std::string> Buah;

    // Memasukkan buah-buahan ke dalam list buah tadi
    Buah.push_back("Rambutan");
    Buah.push_back("Jambu");
    Buah.push_back("Jeruk");
    Buah.push_back("Melon");
    Buah.push_back("Semangka");
    Buah.push_back("Durian");

    // Membuat dua list baru untuk memisahkan buah-buahan tadi
    std::list<std::string> list1;
    std::list<std::string> list2;

    // Memindahkan elemen ke list1 dan list2 dengan menggunakan iterasi
    std::list<std::string>::iterator it = Buah.begin();

    // Membuat isi list masing-masing sebanyak 3 
    for(int i = 0; i < 3; i++) {
        list1.push_back(*it);
        ++it;
    }

    for(int i = 0; i < 3; i++) {
        list2.push_back(*it);
        ++it;
    }

    // Menghapus Jambu dan Durian dari list
    list1.remove("Jambu");
    list2.remove("Durian");

    // Mencetak isi list
    std::cout << "Seluruh list :" << std::endl;

    for(const std::string &buah : Buah) {
        std::cout << buah << std::endl;
    }

    // Cetak list 1
    std::cout << "\nList 1 :" << std::endl;
    for(const std::string &buah: list1) {
        std::cout << buah << std::endl;
    }

    // Cetak list 2
    std::cout << "\nList 2 :" << std::endl;
    for(const std::string &buah: list2) {
        std::cout << buah << std::endl;
    }

    return 0;
}