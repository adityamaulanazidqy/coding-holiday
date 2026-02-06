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
    Mahasiswa* pM = new Mahasiswa;

    pM->nama = InputStr("Masukkan nama: ");
    pM->umur = InputInt("Masukkan umur: ");
    
    do {
        pM->ipk = InputFloat("Masukkan IPK: ");
        if (pM->ipk > 4) {
            cout << "IPK tidak boleh lebih dari 4!" << endl;
        }
    } while (pM->ipk > 4);

    Clear();
    
    Title("DATA MAHASISWA DYNACO");
    cout << pM->nama << " " << pM->umur << " " << pM->ipk << endl;
    Line();

    delete pM;
    return 0;
}
