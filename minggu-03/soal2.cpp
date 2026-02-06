#include <iostream>
#include <string>
#include <iomanip>
#include "include/utils.h"

using namespace std;

struct Mahasiswa {
    string nama;
    float ipk;
};

int main() {
    int n = InputInt("Masukkan jumlah mahasiswa: ");
    cin.ignore();

    Clear();

    Mahasiswa *m = new Mahasiswa[n];
    Mahasiswa *pM = m;

    for (int i = 0; i < n; i++) {
        Title("Mahasiswa ke-" + to_string(i + 1));
        (pM + i)->nama = InputStr("Masukkan nama: ");

        do {
            (pM + i)->ipk = InputFloat("Masukkan IPK: ");
            if ((pM + i)->ipk > 4) {
                cout << "IPK tidak boleh lebih dari 4!" << endl;
            }
        } while ((pM + i)->ipk > 4);

        cin.ignore();
    }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (pM + i)->ipk;
    }

    Line();

    cout << fixed << setprecision(2);
    cout << "Rata-rata IPK: " << (n > 0 ? sum / n : 0.00) << endl;

    delete[] m;
    return 0;
}
