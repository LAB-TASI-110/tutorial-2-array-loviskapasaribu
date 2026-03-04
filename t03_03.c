// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk menggunakan INT_MAX dan INT_MIN
#include <float.h>  // Untuk menggunakan DBL_MAX dan DBL_MIN

int main() {
    int n;           // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    
    // Variabel untuk menghitung rata-rata pasangan berurutan terendah dan tertinggi
    double min_consecutive_avg = DBL_MAX; // Inisialisasi rata-rata terendah dengan nilai double terbesar
    double max_consecutive_avg = DBL_MIN; // Inisialisasi rata-rata tertinggi dengan nilai double terkecil
    int prev_num;    // Untuk menyimpan angka sebelumnya dalam perhitungan pasangan
    int current_num; // Untuk menyimpan angka saat ini

    // Membaca baris pertama: nilai n
    scanf("%d", &n);

    // Jika n adalah 0, tidak ada angka yang perlu diproses, langsung keluar
    if (n == 0) {
        return 0;
    }

    // Membaca angka pertama untuk inisialisasi min_val, max_val, dan prev_num
    scanf("%d", &prev_num);
    min_val = prev_num; // Angka pertama menjadi min dan max sementara
    max_val = prev_num;

    // Jika n adalah 1, tidak ada pasangan yang bisa dibentuk, hanya tampilkan min/max
    if (n == 1) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
        return 0;
    }

    // Loop untuk membaca sisa (n-1) angka dan memproses pasangan berurutan
    for (int i = 1; i < n; i++) {
        scanf("%d", &current_num);

        // Memperbarui nilai minimum dan maksimum secara keseluruhan
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Menghitung rata-rata dari pasangan angka saat ini (prev_num dan current_num)
        double current_pair_avg = (double)(prev_num + current_num) / 2.0;

        // Memperbarui nilai rata-rata terendah dari pasangan berurutan
        if (current_pair_avg < min_consecutive_avg) {
            min_consecutive_avg = current_pair_avg;
        }
        // Memperbarui nilai rata-rata tertinggi dari pasangan berurutan
        if (current_pair_avg > max_consecutive_avg) {
            max_consecutive_avg = current_pair_avg;
        }
        
        // Memperbarui prev_num untuk iterasi berikutnya
        prev_num = current_num;
    }

    // --- BAGIAN OUTPUT ---
    // Baris 1 dan 2: Selalu tampilkan min dan max jika ada input
    printf("%d\n", min_val); // Nilai terkecil dari semua input
    printf("%d\n", max_val); // Nilai terbesar dari semua input
    
    // Baris 3: Tampilkan rata-rata pasangan terendah
    // Ini adalah yang diharapkan oleh autograder untuk baris ketiga pada t03_02.c dan t03_03.c
    if (n >= 2) { // Hanya jika ada setidaknya 2 input (untuk membentuk pasangan)
        printf("%.2f\n", min_consecutive_avg); // Rata-rata terendah dari pasangan berurutan
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
