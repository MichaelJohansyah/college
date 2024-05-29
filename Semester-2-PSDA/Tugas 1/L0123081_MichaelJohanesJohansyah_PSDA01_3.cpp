/*
NIM: L0123081
Nama: Michael Johanes Johansyah
Kelas: C
*/

#include <iostream> // Untuk mengaktifkan operasi input dan output standar (cout dan cin)
#include <queue>    // Untuk operasi antrian/queue (FIFO).
#include <stack>    // Untuk operasi tumpukan/stack (LIFO).

void commandPrompt(std::queue <std::string> &input) {
    std::stack <int> stack;

    while(!input.empty()) {
        
        // Jalankan input yang paling awal
        // lalu hapus dari queue input yang dijalankan
        std::string command = input.front();
        input.pop();

        if (command.substr(0, 4) == "PUSH") {
            // Ambil angka di string tersebut
            // lalu convert dari string ke integer
            int angka = std::stoi(command.substr(5));
            stack.push(angka);
        } else if (command.substr(0, 3) == "TOP") {
            if (!stack.empty()) {
                // Cetak angka yang teratas di stack
                std::cout << stack.top();
            }
        } else if (command.substr(0, 3) == "POP") {
            if(!stack.empty()) {
                stack.pop();
            }
        }
    }
}

int main() {
    std::queue <std::string> input;

    // Masukan input ke komputer
    input.push("PUSH 0");
    input.push("PUSH 0");
    input.push("TOP");
    input.push("PUSH 1");
    input.push("TOP");
    input.push("POP");
    input.push("POP");
    input.push("TOP");

    // Eksekusi input
    commandPrompt(input);

    return 0;
}