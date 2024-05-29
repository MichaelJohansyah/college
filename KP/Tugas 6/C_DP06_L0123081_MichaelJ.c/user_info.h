#ifndef USER_INFO_H
#define USER_INFO_H

// Enum untuk jenis kelamin
enum JenisKelamin {
    PRIA,
    WANITA,
    LAINNYA
};

// Struct untuk menyimpan informasi pengguna
struct UserInfo {
    char nama[50];
    int umur;
    enum JenisKelamin jenisKelamin;
};

#endif
