// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk menggunakan INT_MAX dan INT_MIN

int main() {
    int n;           // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;         // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    int i;           // Variabel counter untuk loop
    
    int first_num = 0;  // Untuk menyimpan angka pertama yang dimasukkan
    int second_num = 0; // Untuk menyimpan angka kedua yang dimasukkan
    int third_num = 0;  // Untuk menyimpan angka ketiga yang dimasukkan
    int fourth_num = 0; // Untuk menyimpan angka keempat yang dimasukkan

    double first_pair_average = 0.0;     // Untuk menyimpan rata-rata dari dua angka pertama
    double third_fourth_pair_average = 0.0; // Untuk menyimpan rata-rata dari angka ketiga dan keempat

    // Membaca baris pertama: nilai n
    scanf("%d", &n);

    // Melakukan loop sebanyak n kali untuk membaca semua masukan dan mencari min/max
    for (i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan bulat dari masukan

        // Memperbarui nilai minimum dan maksimum secara keseluruhan
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }

        // Menyimpan angka-angka spesifik untuk perhitungan rata-rata
        if (i == 0) {
            first_num = num;
        } else if (i == 1) {
            second_num = num;
        } else if (i == 2) {
            third_num = num;
        } else if (i == 3) {
            fourth_num = num;
        }
    }

    // Menghitung rata-rata dari dua angka pertama, jika tersedia
    if (n >= 2) {
        first_pair_average = (double)(first_num + second_num) / 2.0;
    }

    // Menghitung rata-rata dari angka ketiga dan keempat, jika tersedia
    if (n >= 4) {
        third_fourth_pair_average = (double)(third_num + fourth_num) / 2.0;
    }

    // Menampilkan nilai terkecil dan terbesar, jika ada input
    if (n > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    }
    
    // Menampilkan rata-rata dari dua angka pertama, jika ada minimal 2 input
    if (n >= 2) {
        printf("%.2f\n", first_pair_average); // Menampilkan dengan 2 digit presisi
    }

    // Menampilkan rata-rata dari angka ketiga dan keempat, jika ada minimal 4 input
    if (n >= 4) {
        printf("%.2f\n", third_fourth_pair_average); // Menampilkan dengan 2 digit presisi
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
