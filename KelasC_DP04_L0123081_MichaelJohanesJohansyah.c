#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BRS 2
#define KLM 2

int input;

void printArray(int array[BRS][KLM]) {
    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int getMenuChoice() {
    int choice;
    printf("Berikut ini dua jenis program Array:\n");
    printf("1. Mengubah nilai array\n");
    printf("2. Mengoperasikan nilai array\n");
    printf("\nSilahkan input jenis program yang kamu mau! (1-2): ");
    scanf("%d", &choice);
    return choice;
}

void ubahNilai(int array1[BRS][KLM], int array2[BRS][KLM]) {
    printf("\nPilih array yang ingin kamu ubah:\n");
    printf("1. Array pertama\n");
    printf("2. Array kedua\n");
    printf("Pilih array (1-2): ");
    scanf("%d", &input);

    if (input == 1) {
        for (int i = 0; i < BRS; i++) {
            for (int j = 0; j < KLM; j++) {
                printf("Array ke-[%d][%d]: ", i, j);
                scanf("%d", &array1[i][j]);
            }
        }
        printf("\nHasil array: \n");
        printArray(array1);
    } else {
        for (int i = 0; i < BRS; i++) {
            for (int j = 0; j < KLM; j++) {
                printf("Array ke-[%d][%d]: ", i, j);
                scanf("%d", &array2[i][j]);
            }
        }
        printf("\nHasil array: \n");
        printArray(array2);
    }
}

void tambahArray(int array1[BRS][KLM], int array2[BRS][KLM], int result[BRS][KLM]) {
    
    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            result[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("\nHasil penjumlahan array:\n");
    printArray(result);
}

void kurangArray(int array1[BRS][KLM], int array2[BRS][KLM], int result[BRS][KLM]) {
    
    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            result[i][j] = array1[i][j] - array2[i][j];
        }
    }

    printf("\nHasil pengurangan array:\n");
    printArray(result);
}

void kaliArray(int array1[BRS][KLM], int array2[BRS][KLM], int result[BRS][KLM]) {
    
    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            result[i][j] = array1[i][j] * array2[i][j];
        }
    }

    printf("\nHasil perkalian array:\n");
    printArray(result);
}

void bagiArray(int array1[BRS][KLM], int array2[BRS][KLM], int result[BRS][KLM]) {
    
    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            if (array2[i][j] == 0) {
                printf("\nTidak dapat membagi oleh nol.\n");
                return;
            }
            result[i][j] = array1[i][j] / array2[i][j];
        }
    }

    printf("\nHasil pembagian array:\n");
    printArray(result);
}

int main() {
    int arr1[BRS][KLM];
    int arr2[BRS][KLM];

    srand(time(NULL));

    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            arr1[i][j] = rand() % 9 + 1;
        }
    }

    for (int i = 0; i < BRS; i++) {
        for (int j = 0; j < KLM; j++) {
            arr2[i][j] = rand() % 9 + 1; 
        }
    }

    int result[BRS][KLM];

    printf("\nPercobaan Program Array 2D\n");
    printf("Berikut ini dua Array acak\n");
    printf("\nArray pertama:\n");
    printArray(arr1);
    printf("\n");

    printf("Array kedua:\n");
    printArray(arr2);
    printf("\n");

    do {
        input = getMenuChoice();
    } while (input < 1 || input > 2);

    if (input == 1) {
        ubahNilai(arr1, arr2);
    } else if (input == 2) {
        printf("\nPengoperasian array:\n");
        printf("1. Penjumlahan\n");
        printf("2. Pengurangan\n");
        printf("3. Perkalian\n");
        printf("4. Pembagian\n");
        printf("Input jenis operasi yang kamu mau!: ");
        scanf("%d", &input);
        switch (input) {
            case 1:
                tambahArray(arr1, arr2, result);
                break;
            case 2:
                kurangArray(arr1, arr2, result);
                break;
            case 3:
                kaliArray(arr1, arr2, result);
                break;
            case 4:
                bagiArray(arr1, arr2, result);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
