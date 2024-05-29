#include <bits/stdc++.h> //Paket lengkap include
using namespace std;

struct Songs // Pada tugas PSDA09 kali ini, lebih difokuskan kepada sort lagu berdasarkan durasi lagu
{
    string title;  // Tidak digunakan lagi, bekas dari PSDA08 (Pajangan)
    string artist; // Tidak digunakan lagi, bekas dari PSDA08 (Pajangan)
    int duration;
};

int partition(vector<Songs> &collection,int low, int high)
{
    int pivot = collection[high].duration;  // Memilih pivot, kali ini memilih index paling belakang

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (collection[j].duration < pivot){
            i++;
            swap(collection[i].duration,collection[j].duration);
        }
    }
    swap(collection[i+1].duration,collection[high].duration);
    return (i + 1);
    
}

// Fungsi untuk melakukan Quick Sort, kepada durasi lagu
void quickSort(vector<Songs> &collection,int low, int high)
{
    if (low < high) {

		int pi = partition(collection, low, high);

        // Membagi sort elemen menjadi sebelum partition dan sesudah partition
		quickSort(collection, low, pi - 1);
		quickSort(collection, pi + 1, high);
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
    
    int n = collection.size(); //Untuk membaca ukuran dari lagu yang ingin di iterasi

    cout << "Koleksi lagu sebelum diurut : \n";
    printSongs(collection);

    cout << "Urutan lagu berdasarkan durasi: \n";
    quickSort(collection,0,n-1);
    printSongs(collection);
    return 0;
}