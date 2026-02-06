#include <iostream>
#include <string>
#include <iomanip>
#include "database/database_mahasiswa.h"
#include "include/utils.h"

using namespace std;

int main() {
    Clear();
    Title("INPUT DATA MAHASISWA");

    int n = InputInt("Masukkan jumlah mahasiswa: ");
    cin.ignore();

    Mahasiswa *m = new Mahasiswa[n];
    Mahasiswa *pM = m;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;

        (pM + i)->nim = InputStr("NIM  : ");
        (pM + i)->nama = InputStr("Nama : ");
        (pM + i)->nilai = InputFloat("Nilai: ");
        cin.ignore();
    }

    Clear();
    Title("DAFTAR DATA MAHASISWA");

    float totalNilai = 0;
    Mahasiswa *pMTertinggi = pM;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << (pM + i)->nim << " | " << (pM + i)->nama << " | " << (pM + i)->nilai << endl;

        totalNilai += (pM + i)->nilai;

        if ((pM + i)->nilai > pMTertinggi->nilai) {
            pMTertinggi = (pM + i);
        }
    }

    Line();
    cout << fixed << setprecision(2);
    float rataRata = (n > 0) ? (float)totalNilai / n : 0;
    cout << "Rata-rata Nilai: " << rataRata << endl;
    cout << "Mahasiswa Nilai Tertinggi: " << pMTertinggi->nama << " (" << pMTertinggi->nilai << ")" << endl;
    Line();

    delete[] m;

    return 0;
}
