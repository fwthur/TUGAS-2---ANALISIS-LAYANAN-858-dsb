#include <stdio.h>
#include <math.h>

#define N 8 // Jumlah titik dalam sinyal
#define PI 3.14159265358979323846

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
            real[k] += signal[t] * cos(2 * PI * k * t / n);
            imag[k] -= signal[t] * sin(2 * PI * k * t / n);
        }
    }
}

int main() {
    // Contoh sinyal gelombang sinus frekuensi rendah (f = 1 Hz)
    float signal[N];

    // Mengisi array sinyal dengan gelombang sinus
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * PI * i / N);  // Sinyal sinus periodik
    }

    // Array untuk menyimpan hasil real dan imajiner dari DFT
    float real[N], imag[N];

    // Hitung DFT dari sinyal
    DFT(signal, real, imag, N);

    // Hitung Power Spectral Density (PSD)
    calculate_PSpec(real, imag, N);

    return 0;
}
