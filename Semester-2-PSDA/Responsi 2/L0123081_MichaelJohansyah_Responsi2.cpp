#include <bits/stdc++.h> //Paket lengkap include
using namespace std;

struct Videos
{
    string title;
    string studio;
    int episode;
};

// Fungsi untuk melakukan Bubble Sort, kepada judul anime       
void bubbleSort(vector<Videos> &collection)
{
    bool swapped; // Membuat variabel swapped untuk mengecek apakah ada elemen yang terswap
    int n = collection.size(); // Untuk membaca ukuran dari judul yang ingin di iterasi

    // Iterasi masing-masing huruf dari judul anime, dan swap hingga judul menjadi urut
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Membuat seluruh title anime menjadi lowercase dan ignore spasi agar sorting menjadi lebih akurat
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

// Fungsi untuk melakukan Selection Sort, kepada studio anime
void selectionSort(vector<Videos> &collection)
{
    int min_idx;            // Membuat variabel min index untuk memasukan elemen terendah yang ditemukan
    int n = collection.size(); // Untuk membaca ukuran dari studio yang ingin di iterasi

    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++) {

        // Cari elemen terendah untuk diurutkan
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (collection[j].studio < collection[min_idx].studio)
                min_idx = j;
        }

        // Swap minimum element yang ditemukan dengan elemen pertama
        if (min_idx != i)
            swap(collection[min_idx], collection[i]);
    }
}

// Fungsi untuk melakukan Insertion Sort, kepada jumlah episode anime
void insertionSort(vector<Videos> &collection)
{
    int i, j;
    int n = collection.size(); //Untuk membaca ukuran dari studio yang ingin di iterasi

    // Melakukan iterasi, dan memasukkan nilai ke key agar dapat dibandingkan
    for (i = 1; i < n; i++) {
        Videos key = collection[i];
        j = i - 1;

        // Memindahkan elemen dari array yang lebih besar dari key,
        // ke satu posisi didepan posisi sekarangnya
        while (j >= 0 && collection[j].episode > key.episode) {
            collection[j + 1] = collection[j];
            j = j - 1;
        }
        collection[j + 1] = key;
    }
}

int partition(vector<Videos> &collection,int low, int high)
{
    int pivot = collection[high].episode;  // Memilih pivot, kali ini memilih index paling belakang

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (collection[j].episode < pivot){
            i++;
            swap(collection[i].episode,collection[j].episode);
        }
    }
    swap(collection[i+1].episode,collection[high].episode);
    return (i + 1);
    
}

// Fungsi untuk melakukan Quick Sort, kepada jumlah episode anime
void quickSort(vector<Videos> &collection,int low, int high)
{
    if (low < high) {

		int pi = partition(collection, low, high);

        // Membagi sort elemen menjadi sebelum partition dan sesudah partition
		quickSort(collection, low, pi - 1);
		quickSort(collection, pi + 1, high);
	}
}


// Fungsi untuk print daftar anime
void printVideos(const vector<Videos> &collection)
{
    for (int i = 0; i < collection.size(); i++)
        cout << i+1 << ". " << collection[i].title << " - " << collection[i].studio << " - " << collection[i].episode << " episode \n";
    cout << "\n";
}

int main()
{
    vector<Videos> collection = 
    {   {"Sousou no Frieren","Madhouse", 28},
        {"Fullmetal Alchemist: Brotherhood","Bones", 64},
        {"Steins;Gate","White Fox", 24},
        {"Attack on Titan","Wit Studio & MAPPA", 98},
        {"Bleach","Pierrot", 386},
        {"One Piece","Toei Animation", 1120},
        {"Violet Evergarden","Kyoto Animation", 14},
        {"Sword Art Online","A-1 Pictures", 100},
        {"Jujutsu Kaisen","Mappa", 47},
        {"Demon Slayer","Ufotable", 61}

    };
    
    int n = collection.size(); //Untuk membaca ukuran dari anime yang ingin di iterasi

    cout << "Berikut ini koleksi anime sebelum diurut : \n";
    printVideos(collection);

    cout << "Kamu ingin mengurutkan anime berdasarkan apa? " << endl;
    cout << "1. Judul\n";
    cout << "2. Nama Studio\n";
    cout << "3. Jumlah Episode\n";
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;

    cout << endl;
        
    switch (pilihan)
    {
    case 1:
        cout << "Urutan anime berdasarkan judul: \n";
        bubbleSort(collection);
        printVideos(collection);
        break;
    
    case 2:
        cout << "Urutan anime berdasarkan studio: \n";
        selectionSort(collection);
        printVideos(collection);
        break;
    
    case 3:
        int sort;
        cout << "Berikut ini pilihan untuk urutan berdasarkan jumlah episode :" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Quick Sort" << endl;
        cout << "Pilihan: ";
        cin >> sort;

        cout << endl;

        switch (sort)
        {
        case 1:
            cout << "Urutan anime berdasarkan jumlah episode: \n";
            insertionSort(collection);
            printVideos(collection);
            break;
        
        case 2:
            cout << "Urutan anime berdasarkan jumlah episode: \n";
            quickSort(collection, 0, n-1);
            printVideos(collection);
            break;
        
        default:
            cout << "Harap pilih angka yang sesuai (1-2)" << endl;
            break;
        }
        break;
    
    default:
        cout << "Pilih angka yang sesuai! (1-3)" << endl;
        break;
    }

    return 0;
}