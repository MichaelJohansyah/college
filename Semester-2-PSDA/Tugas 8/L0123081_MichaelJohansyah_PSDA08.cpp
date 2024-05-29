#include <bits/stdc++.h> //Paket lengkap include
using namespace std;

struct Songs
{
    string title;
    string artist;
    int duration;
};

// Fungsi untuk melakukan Bubble Sort, kepada judul lagu       
void bubbleSort(vector<Songs> &collection)
{
    bool swapped; // Membuat variabel swapped untuk mengecek apakah ada elemen yang terswap
    int n = collection.size(); // Untuk membaca ukuran dari judul yang ingin di iterasi

    // Iterasi masing-masing huruf dari judul lagu, dan swap hingga judul menjadi urut
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Membuat seluruh title lagu menjadi lowercase dan ignore spasi agar sorting menjadi lebih akurat
            string title1 = collection[j].title;
            string title2 = collection[j + 1].title;
            title1.erase(remove(title1.begin(), title1.end(), ' '), title1.end());
            transform(title1.begin(), title1.end(), title1.begin(), ::tolower); 
            title2.erase(remove(title2.begin(), title2.end(), ' '), title2.end());
            transform(title2.begin(), title2.end(), title2.begin(), ::tolower); 

            if (title1 > title2) {
                swap(collection[j], collection[j + 1]);
                swapped = true;
            }
        }

        // Jika dua elemen tidak ter swap, maka break
        if (swapped == false)
            break;
    }
}

// Fungsi untuk melakukan Selection Sort, kepada artis lagu
void selectionSort(vector<Songs> &collection)
{
    int min_idx;            // Membuat variabel min index untuk memasukan elemen terendah yang ditemukan
    int n = collection.size(); // Untuk membaca ukuran dari artis yang ingin di iterasi

    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++) {

        // Cari elemen terendah untuk diurutkan
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (collection[j].artist < collection[min_idx].artist)
                min_idx = j;
        }

        // Swap minimum element yang ditemukan dengan elemen pertama
        if (min_idx != i)
            swap(collection[min_idx], collection[i]);
    }
}

// Fungsi untuk melakukan Insertion Sort, kepada durasi lagu
void insertionSort(vector<Songs> &collection)
{
    int i, j;
    int n = collection.size(); //Untuk membaca ukuran dari artis yang ingin di iterasi

    // Melakukan iterasi, dan memasukkan nilai ke key agar dapat dibandingkan
    for (i = 1; i < n; i++) {
        Songs key = collection[i];
        j = i - 1;

        // Memindahkan elemen dari array yang lebih besar dari key,
        // ke satu posisi didepan posisi sekarangnya
        while (j >= 0 && collection[j].duration > key.duration) {
            collection[j + 1] = collection[j];
            j = j - 1;
        }
        collection[j + 1] = key;
    }
}

// Fungsi untuk print daftar lagu
void printSongs(const vector<Songs> &collection)
{
    for (int i = 0; i < collection.size(); i++)
        cout << i+1 << ". " << collection[i].title << " - " << collection[i].artist << " - " << collection[i].duration << " detik \n";
    cout << "\n";
}

int main()
{
    vector<Songs> collection = 
    {
        {"Indonesia Raya", "Wage Rudolf Supratman", 111},
        {"Never Gonna Give You Up", "Rick Astley", 213},
        {"Everything Is Awesome!!!", "Tegan and Sara", 164},
        {"I Want It That Way", "Backstreet Boys", 220},
        {"Balonku", "Abdullah Totong Mahmud", 180}
    };
    
    cout << "Koleksi lagu sebelum diurut : \n";
    printSongs(collection);

    cout << "Urutan lagu berdasarkan judul: \n";
    bubbleSort(collection);
    printSongs(collection);

    cout << "Urutan lagu berdasarkan artis: \n";
    selectionSort(collection);
    printSongs(collection);

    cout << "Urutan lagu berdasarkan durasi: \n";
    insertionSort(collection);
    printSongs(collection);
    return 0;
}