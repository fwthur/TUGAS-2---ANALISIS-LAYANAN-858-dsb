#include <stdio.h>
#include <string.h>

// Fungsi untuk mencetak kombinasi
void printCombinations(char* str, int start, char* result, int index, int length) {
    // Output: Cetak hasil saat ini (kombinasi)
    for (int i = 0; i < index; i++) {
        printf("%c", result[i]);
    }
    printf("\n");

    // Proses: Rekursif untuk menghasilkan semua kombinasi
    for (int i = start; i < length; i++) {
        result[index] = str[i]; // Tambahkan karakter saat ini ke hasil
        printCombinations(str, i + 1, result, index + 1, length); // Rekursif untuk karakter berikutnya
    }
}

// Driver program
int main() {
    char input_string[] = "abc"; // Contoh input
    int length = strlen(input_string); // Panjang string
    char result[length + 1]; // Array untuk menyimpan kombinasi saat ini

    printf("Kombinasi dari string '%s':\n", input_string);
    printCombinations(input_string, 0, result, 0, length);

    return 0;
}
