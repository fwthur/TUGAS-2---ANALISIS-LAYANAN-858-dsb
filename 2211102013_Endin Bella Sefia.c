// MENGHITUNG POWER SPECTRAL DENSITY (PSD)
// program akan mencetak frekuensi dan kekuatan
//

#include <stdio.h>
#include <math.h>

#define N 8 // Jumlah titik dalam sinyal

// Fungsi untuk menghitung Power Spectral Density (PSD)
void calculate_PSpec(float real[], float imag[], int n) {
    printf("Frequency\tPower\n");
    for (int k = 0; k < n; ++k) {
        float power = (real[k] * real[k]) + (imag[k] * imag[k]);
        printf("%d\t\t%.2f\n", k, power);
    }
}

// Fungsi untuk menghitung Discrete Fourier Transform (DFT)
void DFT(float signal[], float real[], float imag[], int n) {
    for (int k = 0; k < n; ++k) { // Untuk setiap frekuensi
        real[k] = 0;
        imag[k] = 0;
        for (int t = 0; t < n; ++t) { // Untuk setiap titik dalam sinyal
            real[k] += signal[t] * cos(2 * M_PI * k * t / n);
            imag[k] -= signal[t] * sin(2 * M_PI * k * t / n);
        }
    }
}

int main() {
    // Contoh sinyal yang akan dianalisis (misalnya sinyal diskrit)
    float signal[N] = {1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0, 0.0};

    // Array untuk menyimpan hasil real dan imajiner dari DFT
    float real[N], imag[N];

    // Hitung DFT dari sinyal
    DFT(signal, real, imag, N);

    // Hitung Power Spectral Density (PSD)
    calculate_PSpec(real, imag, N);

    return 0;
}
