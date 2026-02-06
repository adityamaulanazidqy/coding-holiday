#include <iostream>
#include <string>
#include "include/utils.h"

using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

int main() {
    Mahasiswa m;
    Mahasiswa *pM = &m;

    pM->nama = InputStr("Masukkan nama: ");
    pM->umur = InputInt("Masukkan umur: ");

    do {
        pM->ipk = InputFloat("Masukkan IPK: ");
        if (pM->ipk > 4) {
            cout << "IPK tidak boleh lebih dari 4!" << endl;
        }
    } while (pM->ipk > 4);

    Clear();

    Title("DATA MAHASISWA");
    cout << "Nama: " << pM->nama << endl;
    cout << "Umur: " << pM->umur << endl;
    cout << "IPK: " << pM->ipk << endl;
    Line();

    return 0;
}
