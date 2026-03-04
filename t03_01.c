// 12S25016 - Loviska Astria Pasaribu

#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk menggunakan INT_MAX dan INT_MIN

int main() {
    int n; // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num; // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar yang mungkin
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil yang mungkin
    int i; // Variabel counter untuk loop

    // Membaca baris pertama: nilai n
    scanf("%d", &n);

    // Melakukan loop sebanyak n kali untuk membaca n baris masukan berikutnya
    for (i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan bulat dari masukan

        // Membandingkan dengan nilai minimum saat ini
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan dengan nilai maksimum saat ini
        if (num > max_val) {
            max_val = num;
        }
    }

    // Menampilkan nilai terkecil
    printf("%d\n", min_val);

    // Menampilkan nilai terbesar
    printf("%d\n", max_val);

    return 0; // Mengindikasikan program berakhir dengan sukses
}
