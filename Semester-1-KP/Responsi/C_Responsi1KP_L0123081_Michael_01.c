#include <stdio.h>
#include <stdlib.h>

struct Weapon {
    char name[50];
    int damage;
};

struct Enemy {
    int defense;
    int health;
};

void clearScreen() {
    // Fungsi untuk membersihkan layar konsol, bekerja di berbagai sistem operasi
    system("clear || cls");
}

void initializeEnemy(struct Enemy *enemy) {
    clearScreen();
    printf("Weapon Damage Simulator Game \n");
    printf("------------------------------------\n\n");
    printf("Choose an option to initialize enemy status:\n");
    printf("1. Enter custom values\n");
    printf("2. Use default values (100 health, 50 defense): \n");

    int option;
    scanf("%d", &option);

    if (option == 1) {
        // Meminta pengguna memasukkan nilai defense dan health untuk enemy
        printf("Enter initial enemy defense: ");
        scanf("%d", &enemy->defense);

        printf("Enter initial enemy health: ");
        scanf("%d", &enemy->health);
    } else if (option == 2) {
        // Menggunakan nilai default jika pengguna memilih opsi default
        enemy->defense = 50;
        enemy->health = 100;
    } else {
        // Menggunakan nilai default jika pengguna memasukkan opsi tidak valid
        printf("Invalid option. Using default values.\n");
        enemy->defense = 50;
        enemy->health = 100;
    }
}

void newEnemy(struct Enemy *enemy) {
    // Menginisialisasi enemy baru dengan opsi kustom atau nilai default
    printf("\nChoose an option for new enemy status:\n");
    printf("1. Enter custom values\n");
    printf("2. Use default values (100 health, 50 defense): \n");

    int option;
    scanf("%d", &option);

    if (option == 1) {
        // Meminta pengguna memasukkan nilai defense dan health untuk enemy baru
        printf("Enter new enemy defense: ");
        scanf("%d", &enemy->defense);

        printf("Enter new enemy health: ");
        scanf("%d", &enemy->health);
    } else if (option == 2) {
        // Menggunakan nilai default jika pengguna memilih opsi default
        enemy->defense = 50;
        enemy->health = 100;
    } else {
        // Menggunakan nilai default jika pengguna memasukkan opsi tidak valid
        printf("Invalid option. Using default values.\n");
        enemy->defense = 50;
        enemy->health = 100;
    }
}

void displayEnemyStatus(struct Enemy enemy) {
    // Menampilkan status defense dan health dari enemy
    printf("Enemy Status:\n");
    printf("Defense: %d\n", enemy.defense);
    printf("Health: %d\n", enemy.health);
    printf("----------------------------\n");
}

void displayWeapons(struct Weapon weapons[], int numWeapons) {
    // Menampilkan daftar senjata yang tersedia
    printf("Weapons List:\n");
    for (int i = 0; i < numWeapons; i++) {
        printf("%d. %s\n", i + 1, weapons[i].name);
    }
}

void displayWeaponDetails(struct Weapon weapon, struct Enemy enemy) {
    clearScreen();
    displayEnemyStatus(enemy);
    // Menampilkan detail senjata, termasuk nama dan damage
    printf("Weapon Details:\n");
    printf("Name: %s\n", weapon.name);
    printf("Damage: %d\n", weapon.damage);
}

// Fungsi rekursif untuk simulasi Headshot
int simulateHeadshotDamage(int damage) {
    // Peluang Headshot 50%, menggandakan damage dalam kasus Headshot
    if (rand() % 2 == 0) {
        printf("Headshot! Damage doubled! \n");
        return damage * 2;
    } else {
        return damage;
    }
}

void attackEnemy(struct Weapon weapon, struct Enemy *enemy) {
    // Mendapatkan damage yang mungkin termasuk Headshot
    int inflictedDamage = simulateHeadshotDamage(weapon.damage);

    // Mengurangi defense terlebih dahulu, kemudian health jika defense 0 atau negatif
    enemy->defense -= inflictedDamage;

    if (enemy->defense < 0) {
        // Mengurangkan defense negatif dari health jika defense kurang dari 0
        enemy->health += enemy->defense;
        enemy->defense = 0;

        // Jika baik defense dan health 0, reset ke nilai awal
        if (enemy->health <= 0) {
            printf("Enemy defeated!\n");
            newEnemy(enemy);
        }
    }

    // Memastikan health tidak kurang dari 0
    if (enemy->health < 0) {
        enemy->health = 0;
    }

    // Menampilkan status terkini dari enemy
    printf("Enemy defense: %d, health: %d\n", enemy->defense, enemy->health);
}

// Pilihan untuk mengupgrade senjata 
void upgradeWeapon(struct Weapon *weapon) {
    // Meningkatkan damage senjata sebesar 10
    weapon->damage += 10;
    printf("Weapon upgraded! New damage: %d\n", weapon->damage);
}

// Pilihan untuk mereset damage senjata 
void resetWeapon(struct Weapon *weapon, int originalDamages) {
    // Mereset damage senjata ke nilai asli
    weapon->damage = originalDamages;
    printf("Weapon reset! Damage restored to: %d\n", weapon->damage);
}

int main() {
    const int numWeapons = 5;
    struct Weapon weapons[numWeapons];

    // Inisialisasi senjata-senjata yang tersedia
    weapons[0] = (struct Weapon){"Pistol", 20};
    weapons[1] = (struct Weapon){"Rifle", 30};
    weapons[2] = (struct Weapon){"Shotgun", 50};
    weapons[3] = (struct Weapon){"Sniper", 100};
    weapons[4] = (struct Weapon){"Machine Gun", 40};

    struct Enemy enemy;
    initializeEnemy(&enemy);

    int choice;

    // Simpan nilai asli dari damage senjata
    int originalDamages[numWeapons];
    for (int i = 0; i < numWeapons; ++i) {
        originalDamages[i] = weapons[i].damage;
    }

    do {
        clearScreen();
        displayEnemyStatus(enemy);
        displayWeapons(weapons, numWeapons);

        // Meminta pengguna memilih senjata untuk dilihat detailnya
        printf("Enter the number of the weapon to view details (0 to exit): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= numWeapons) {
            int option;

            do {
                // Menampilkan detail senjata dan opsi-opsinya
                displayWeaponDetails(weapons[choice - 1], enemy);

                printf("\nOptions:\n");
                printf("1. Attack\n");
                printf("2. Upgrade Weapon\n");
                printf("3. Reset Weapon\n");
                printf("0. Back to Weapons List\n");

                // Meminta pengguna memilih opsi
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        // Menyerang enemy dengan senjata yang dipilih
                        attackEnemy(weapons[choice - 1], &enemy);
                        getchar(); // Mengonsumsi karakter newline dari input sebelumnya
                        printf("\nPress Enter to continue...");
                        getchar(); // Menunggu penekanan tombol Enter
                        break;
                    case 2:
                        // Meningkatkan damage senjata yang dipilih
                        upgradeWeapon(&weapons[choice - 1]);
                        getchar(); // Mengonsumsi karakter newline dari input sebelumnya
                        printf("\nPress Enter to continue...");
                        getchar(); // Menunggu penekanan tombol Enter
                        break;
                    case 3:
                        // Mereset damage senjata yang dipilih
                        resetWeapon(&weapons[choice - 1], originalDamages[choice - 1]);
                        getchar(); // Mengonsumsi karakter newline dari input sebelumnya
                        printf("\nPress Enter to continue...");
                        getchar(); // Menunggu penekanan tombol Enter
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid option\n");
                        break;
                }
            } while (option != 0);
        }
    } while (choice != 0);

    return 0;
}
