//
// Created by zidqy on 2/10/26.
//

#ifndef LINKEDLIST_SERVIS_MODEL_H
#define LINKEDLIST_SERVIS_MODEL_H

#include <string>
using namespace std;

struct Servis {
    string platNomor;
    string jenisService;
    int estimasiWaktu;
    Servis *next;

    Servis(string p, string j, int e) {
        platNomor = p;
        jenisService = j;
        estimasiWaktu = e;
        next = nullptr;
    }
};

#endif
