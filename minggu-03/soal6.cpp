#include <iostream>
#include <string>
#include "include/utils.h"

using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
};

void updateUmur(Mahasiswa** m) {
    if (m != nullptr && *m != nullptr) {
        (*m)->umur += 1;
    }
}

int main() {
    Mahasiswa m;
    Mahasiswa* pM = &m;
    Mahasiswa** ppM = &pM;

    (*ppM)->nama = InputStr("Masukkan nama: ");
    (*ppM)->umur = InputInt("Masukkan umur: ");
    
    updateUmur(ppM);

    Clear();
    Title("UPDATE UMUR");
    cout << "Nama: " << (*ppM)->nama << endl;
    cout << "Umur setelah diubah: " << (*ppM)->umur << endl;
    Line();

    return 0;
}
