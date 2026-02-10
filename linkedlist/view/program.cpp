//
// Created by zidqy on 2/10/26.
//

#include <iostream>
#include <ostream>

#include "../include/helper.h"
#include "../storage/servis_storage.h"

void TambahAntrian() {
    Clear();
    Title("TAMBAH ANTRIAN");
    string platNomor = InputStr("Masukkan nomor plat : ");
    string jenisService = InputStr("Masukkan jenis service : ");
    int estimasiWaktu = InputInt("Masukkan estimasi waktu(Hitungan Menit) : ");
    cin.ignore(1000, '\n');

    Servis *baru = new Servis(platNomor, jenisService, estimasiWaktu);
    string isPriority;
    bool valid = false;

    while (!valid) {
        isPriority = InputStr("Apakah antrian ini priority (Y/N) : ");
        if (isPriority == "Y" || isPriority == "y") {
            baru->next = headServis;
            headServis = baru;
            valid = true;
        } else if (isPriority == "N" || isPriority == "n") {
            if (headServis == nullptr) {
                headServis = baru;
            } else {
                Servis *temp = headServis;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = baru;
            }
            valid = true;
        } else {
            cout << "Tolong masukkan Y atau N." << endl;
        }
    }

    lengthListServis++;
    cout << "Antrian berhasil ditambahkan!" << endl;
    Next();
}

void ListAntrian() {
    Clear();
    Title("DAFTAR ANTRIAN");
    for (int i = 0; i < lengthListServis; i++) {
        Servis *temp = headServis;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        cout << "[" << i + 1 << "] " << temp->platNomor << " - Jenis Service: " << temp->jenisService << " - Estimasi: "
                << temp->estimasiWaktu << " Menit"
                << endl;
    }

    cout << endl;
}

void HapusAntrian() {
    Clear();
    if (lengthListServis == 0) {
        cout << "Tidak ada antrian!" << endl;
        Next();
        return;
    }

    ListAntrian();
    Title("HAPUS ANTRIAN");
    string platNomor = InputStr("Masukkan nomor plat: ");

    Servis *temp = headServis;
    while (temp->platNomor != platNomor && temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->platNomor == platNomor) {
        headServis = temp->next;
        delete temp;
        lengthListServis--;
        cout << "Antrian berhasil dihapus!" << endl;
    }

    Next();
}

void TotalEstimasiServis() {
    Clear();
    int total = 0;
    for (int i = 0; i < lengthListServis; i++) {
        Servis *temp = headServis;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        total += temp->estimasiWaktu;
    }

    Title("TOTAL ESTIMASI SERVIS");
    cout << "Total estimasi waktu: " << total << " menit" << endl;
    Next();
}

void PindahkanAntrianTerakhirKeDepan() {
    Clear();
    Servis *temp = headServis;
    Servis *prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = headServis;
    headServis = temp;

    cout << "Antrian berhasil dipindahkan!" << endl;
    ListAntrian();
    Next();
}
