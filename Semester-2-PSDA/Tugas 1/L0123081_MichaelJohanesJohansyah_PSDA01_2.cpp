/*
NIM: L0123081
Nama: Michael Johanes Johansyah
Kelas: C
*/

#include <iostream> // Untuk mengaktifkan operasi input dan output standar (cout dan cin)
#include <stack>    // Untuk mengaktifkan penggunaan struktur data stack

 
// Deklarasi stack untuk menyimpan string
std::stack <std::string> backStack;
std::stack <std::string> forwardStack;

// Fungsi untuk mengunjungi suatu website
void visit(std::string url) {

    // Tambah history ke backStack
    backStack.push(url);
    std::cout << "- Mengunjungi " << url << std::endl;
    
    // Kosongkan stack forward karena mengunjungi halaman baru
    while (!forwardStack.empty()) {
        forwardStack.pop();
    }
}

// Fungsi untuk mundur ke halaman sebelumnya
void back() {
    // Jika backStack tidak kosong
    if (!backStack.empty()) {
        // Simpan url sekarang ke current
        // lalu pop url sekarang dari backStack
        // dan push url ke forwardStack
        std::string current = backStack.top();
        backStack.pop();
        forwardStack.push(current);

        if (!backStack.empty()) {
            std::cout << "- Mengunjungi " << backStack.top() << std::endl;
        } else {
            std::cout << "- Tidak ada halaman sebelumnya" << std::endl;
        } 
    } else {
        std::cout << "- Tidak ada halaman sebelumnya" << std::endl;
    }
}

// Fungsi untuk maju ke halaman setelahnya
void forward() {
    // Jika halaman selanjutnya ada
    if (!forwardStack.empty()) {
        std::string current = forwardStack.top();
        forwardStack.pop();
        backStack.push(current);

        std::cout << "- Mengunjungi " << current << std::endl;
        
    } else {
        std::cout << "- Tidak ada halaman berikutnya" << std::endl;
    }
}

int main() {
    visit("google.com");
    visit("instagram.com");
    visit("github.com");
    back();
    back();
    visit("stackoverflow.com");

    return 0;
}   