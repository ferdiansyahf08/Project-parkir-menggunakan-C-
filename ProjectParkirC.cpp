#include <iostream>
#include <iomanip>

using namespace std;

const double TARIF_JAM_PERTAMA = 3000.0; // Biaya parkir untuk jam pertama
const double TARIF_PER_JAM = 3000.0;    // Biaya parkir per jam setelah jam pertama

int main() {
    char ulangi;

    do {
        int jamMasuk, menitMasuk, jamKeluar, menitKeluar;
        string nomorKendaraan;  // Menambahkan variabel untuk nomor kendaraan

        // Input nomor kendaraan
        cout << "Masukkan nomor kendaraan: ";
        cin >> nomorKendaraan;

        // Input waktu masuk
        cout << "Masukkan waktu masuk (jam menit): ";
        cin >> jamMasuk >> menitMasuk;

        // Input waktu keluar
        cout << "Masukkan waktu keluar (jam menit): ";
        cin >> jamKeluar >> menitKeluar;

        // Hitung durasi parkir dalam jam
        int durasiJam = jamKeluar - jamMasuk;
        int durasiMenit = menitKeluar - menitMasuk;

        // Menangani kasus jika durasi menit negatif
        if (durasiMenit < 0) {
            durasiJam -= 1;
            durasiMenit += 60;
        }

        // Hitung biaya parkir
        double durasiParkir = durasiJam + durasiMenit / 60.0;
        double biayaParkir;

        if (durasiParkir <= 1.0) {
            // Biaya parkir untuk jam pertama
            biayaParkir = TARIF_JAM_PERTAMA;
        }
        else {
            // Biaya parkir per jam setelah jam pertama
            int jumlahJam = static_cast<int>(durasiParkir);
            biayaParkir = TARIF_JAM_PERTAMA + jumlahJam * TARIF_PER_JAM;
        }

        // Tampilkan hasil
        cout << fixed << setprecision(2);
        cout << "==============||==============" << endl;
        cout << "Informasi Keterangan Parkir Kendaraan" << endl;
        cout << "Nomor Kendaraan: " << nomorKendaraan << endl;
        cout << "Durasi Parkir: " << durasiJam << " jam " << durasiMenit << " menit" << endl;
        cout << "Biaya Parkir: Rp. " << biayaParkir << endl;
        cout << "Terima kasih sudah parkir disini" << endl;
        cout << "==============||==============" << endl;

        // Meminta pengguna untuk mengulangi perhitungan
        cout << "Apakah Anda ingin menghitung biaya parkir lagi? (y/n): ";
        cin >> ulangi;

    } while (ulangi == 'y' || ulangi == 'Y');

    cout << "Terima kasih, program berakhir." << endl;

    return 0;
}
