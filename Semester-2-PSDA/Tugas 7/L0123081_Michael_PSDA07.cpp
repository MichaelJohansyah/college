#include <bits/stdc++.h>
using namespace std;

// Special credit untuk Asdos Nazhiif yang membantu saya memahami tugas ini
// Kode sedikit mirip dengan punya Nazhiif karena saya belajar dari cara beliau

const int MAX_STUDENTS = 30;

// Graf pertemanan dengan menggunakan matriks adjacency
bool adj_matrix[MAX_STUDENTS][MAX_STUDENTS] = {false};
vector<string> student_names(MAX_STUDENTS);
int num_students = 0;

// Cek pertemanan mahasiswa berdasarkan namanya
int getStudentId(const string &name)
{
    for (int i = 0; i < num_students; i++)
    {
        if (student_names[i] == name)
            return i;
    }
    return -1; // Jika mahasiswa tidak ditemukan
}

// 1. Menambahkan mahasiswa beserta teman-temannya
void addStudent(const string &name, const vector<string> &friends)
{
    int idx = num_students;
    student_names[idx] = name;
    num_students++;

    for (const string &friend_name : friends)
    {
        int friend_idx = getStudentId(friend_name);
        if (friend_idx != -1)
        {
            adj_matrix[idx][friend_idx] = true;
            adj_matrix[friend_idx][idx] = true;
        }
    }
}

// 2. Menambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar.
void addFriendship(const string &student1, const string &student2)
{
    int idx1 = getStudentId(student1);
    int idx2 = getStudentId(student2);
    if (idx1 != -1 && idx2 != -1) // Jika kedua mahasiswa ada
    {
        adj_matrix[idx1][idx2] = true;
        adj_matrix[idx2][idx1] = true;
    }
}

// 3. Menghapus mahasiswa beserta seluruh hubungan pertemanannya.
void removeStudent(const string &name)
{
    int idx = getStudentId(name);
    if (idx != -1)
    {
        // Hapus pertemanan
        for (int i = 0; i < num_students; i++)
        {
            adj_matrix[idx][i] = false;
            adj_matrix[i][idx] = false;
        }
        num_students--; // Hapus mahasiswa

        // Isi slot kosong studentID saat ini
        for (int i = idx; i < num_students; i++)
        {
            student_names[i] = student_names[i + 1];
        }
    }
}

// 4. Mencari teman bersama antara dua mahasiswa yang sudah terdaftar.
vector<string> findCommon(const string &student1, const string &student2)
{
    vector<string> common_friends;
    int idx1 = getStudentId(student1);
    int idx2 = getStudentId(student2);
    if (idx1 != -1 && idx2 != -1)
    {
        for (int i = 0; i < num_students; i++)
        {
            // Jika punya teman yang sama
            if (adj_matrix[idx1][i] && adj_matrix[idx2][i])
                common_friends.push_back(student_names[i]);
        }
    }
    return common_friends;
}

// 5. Menampilkan daftar teman dari seorang mahasiswa tertentu.
vector<string> getFriendList(const string &name)
{
    vector<string> friend_list;
    int idx = getStudentId(name);
    if (idx != -1)
    {
        for (int i = 0; i < num_students; i++)
        {
            if (adj_matrix[idx][i])
                friend_list.push_back(student_names[i]);
        }
    }
    return friend_list;
}

int main()
{
    //1. Menambahkan mahasiswa baru beserta daftar teman-temannya
    addStudent("Agus", {"Bagas", "Christie", "Dobleh", "Fajar"});
    addStudent("Bagas", {"Agus", "Christie"});
    addStudent("Christie", {"Agus", "Bagas", "Elizabeth"});
    addStudent("Dobleh", {"Agus"});
    addStudent("Elizabeth", {"Christie"});
    addStudent("Fajar",{"Agus, Christie, Dobleh"});

    //2. Menambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar
    addFriendship("Agus", "Elizabeth");

    //3. Menghapus mahasiswa beserta seluruh hubungan pertemanannya
    removeStudent("Dobleh");

    //4. Mencari teman bersama antara dua mahasiswa yang sudah terdaftar
    vector<string> common_friends = findCommon("Agus", "Bagas");
    cout << "Teman bersama antara Agus dan Bagas: ";
    for (const string &friend_name : common_friends)
    {
        cout << friend_name << " ";
    }
    cout << endl;

    //5. Menampilkan daftar teman dari seorang mahasiswa tertentu
    vector<string> friend_list = getFriendList("Fajar");
    cout << "Daftar teman Fajar: ";
    for (const string &friend_name : friend_list)
    {
        cout << friend_name << " ";
    }
    cout << endl;

    vector<string> friend_list2 = getFriendList("Agus");
    cout << "Daftar teman Agus: ";
    for (const string &friend_name : friend_list2)
    {
        cout << friend_name << " ";
    }
    cout << endl;


    //Eksperimen
    removeStudent("Fajar");

    vector<string> friend_list3 = getFriendList("Agus");
    cout << "Daftar teman Agus setelah Fajar kena DO: ";
    for (const string &friend_name : friend_list3)
    {
        cout << friend_name << " ";
    }
    cout << endl;

    vector<string> friend_list4 = getFriendList("Bagas");
    cout << "Daftar teman Bagas: ";
    for (const string &friend_name : friend_list4)
    {
        cout << friend_name << " ";
    }
    cout << endl;

    addFriendship("Bagas", "Elizabeth");

    vector<string> friend_list5 = getFriendList("Bagas");
    cout << "Daftar teman Bagas setelah main sama Elizabeth: ";
    for (const string &friend_name : friend_list5)
    {
        cout << friend_name << " ";
    }
    cout << endl;


    return 0;
}