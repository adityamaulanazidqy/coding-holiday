#include <iostream>
#include <string>
#include "include/utils.h"

using namespace std;

struct Alamat {
    string kota;
    int kode_pos;
};

struct Mahasiswa {
    string nama;
    Alamat alamat;
};

int main() {
    Mahasiswa m;
    Mahasiswa *pM = &m;

    pM->nama = InputStr("Masukkan nama: ");
    pM->alamat.kota = InputStr("Masukkan kota: ");
    pM->alamat.kode_pos = InputInt("Masukkan kode pos: ");

    cout << "Nama: " << pM->nama << endl;
    cout << "Kota: " << pM->alamat.kota << endl;
    cout << "Kode Pos: " << pM->alamat.kode_pos << endl;

    return 0;
}
