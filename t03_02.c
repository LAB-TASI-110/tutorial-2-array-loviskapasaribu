// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk menggunakan INT_MAX dan INT_MIN

int main() {
    int n;           // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;         // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    int i;           // Variabel counter untuk loop
    
    int first_num_input = 0;  // Untuk menyimpan angka pertama yang dimasukkan
    int second_num_input = 0; // Untuk menyimpan angka kedua yang dimasukkan
    double first_pair_average = 0.0; // Untuk menyimpan rata-rata dari dua angka pertama

    // Membaca baris pertama: nilai n
    scanf("%d", &n);

    // Memproses angka pertama (jika ada)
    if (n > 0) {
        scanf("%d", &num);
        min_val = num;
        max_val = num;
        first_num_input = num; // Simpan angka pertama
    }

    // Memproses angka kedua (jika ada)
    if (n > 1) {
        scanf("%d", &num);
        second_num_input = num; // Simpan angka kedua
        
        // Hitung rata-rata dari dua angka pertama
        first_pair_average = (double)(first_num_input + second_num_input) / 2.0;

        // Perbarui nilai min_val dan max_val dengan angka kedua
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }

        // Melakukan loop untuk membaca n-2 baris masukan berikutnya (mulai dari angka ketiga)
        for (i = 2; i < n; i++) {
            scanf("%d", &num);
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }
    } else if (n == 1) {
        // Jika hanya ada satu angka, min_val dan max_val sudah diatur oleh first_num_input
        // Tidak perlu loop lagi, dan rata-rata pasangan tidak bisa dihitung.
    }
    // Jika n adalah 0, tidak ada output yang relevan dari data input.

    // Menampilkan nilai terkecil dan terbesar (jika ada input)
    if (n > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    }
    
    // Menampilkan rata-rata dari dua angka pertama (jika ada minimal 2 input)
    if (n > 1) {
        printf("%.2f\n", first_pair_average); // Menampilkan dengan 2 digit presisi
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
