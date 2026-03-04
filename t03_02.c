// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Untuk menggunakan INT_MAX dan INT_MIN
// #include <float.h> // Tidak diperlukan jika inisialisasi rata-rata menggunakan pasangan pertama

int main() {
    int n;           // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;         // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    int i;           // Variabel counter untuk loop
    
    int prev_num;    // Untuk menyimpan angka sebelumnya dalam perhitungan rata-rata pasangan
    double min_avg_pair = 0.0; // Akan diinisialisasi dengan rata-rata pasangan pertama
    double max_avg_pair = 0.0; // Akan diinisialisasi dengan rata-rata pasangan pertama
    int pair_found = 0;      // Flag untuk menandakan apakah setidaknya satu rata-rata pasangan sudah dihitung

    // Membaca baris pertama: nilai n
    scanf("%d", &n);

    // Hanya melanjutkan jika ada setidaknya satu angka yang dimasukkan
    if (n > 0) {
        // Membaca angka pertama untuk inisialisasi min_val, max_val, dan prev_num
        scanf("%d", &num);
        min_val = num;
        max_val = num;
        prev_num = num; // Angka pertama menjadi 'angka sebelumnya' untuk pasangan pertama

        // Melakukan loop untuk membaca n-1 angka berikutnya
        // Loop ini akan berjalan untuk mendapatkan (n-1) pasangan berurutan
        for (i = 1; i < n; i++) {
            scanf("%d", &num); // Membaca bilangan bulat berikutnya

            // Memperbarui nilai minimum dan maksimum secara keseluruhan
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }

            // Menghitung rata-rata dari pasangan saat ini (prev_num dan num)
            double current_pair_average = (double)(prev_num + num) / 2.0;

            // Inisialisasi min_avg_pair dan max_avg_pair dengan rata-rata pasangan pertama
            if (!pair_found) {
                min_avg_pair = current_pair_average;
                max_avg_pair = current_pair_average;
                pair_found = 1; // Set flag bahwa setidaknya satu pasangan telah ditemukan
            } else {
                // Memperbarui min_avg_pair jika rata-rata saat ini lebih kecil
                if (current_pair_average < min_avg_pair) {
                    min_avg_pair = current_pair_average;
                }
                // Memperbarui max_avg_pair jika rata-rata saat ini lebih besar
                if (current_pair_average > max_avg_pair) {
                    max_avg_pair = current_pair_average;
                }
            }
            
            // Set angka saat ini sebagai 'angka sebelumnya' untuk iterasi berikutnya
            prev_num = num;
        }
    }

    // Menampilkan nilai terkecil dan terbesar (jika ada input)
    if (n > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    }
    
    // Menampilkan rata-rata pasangan terendah dan tertinggi
    // Hanya jika setidaknya ada dua input (yaitu, setidaknya satu pasangan)
    if (pair_found) { // Ini sama dengan memeriksa n >= 2
        printf("%.2f\n", min_avg_pair); // Menampilkan dengan 2 digit presisi
        printf("%.2f\n", max_avg_pair); // Menampilkan dengan 2 digit presisi
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
