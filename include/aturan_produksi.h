#ifndef ATURAN_PRODUKSI_H_INCLUDED
#define ATURAN_PRODUKSI_H_INCLUDED
#include "entity.h"

void ap_nol(Puzzle A,Kotak k); //Kotak kosong ke kanan
void ap_satu(Puzzle A,Kotak k); //Kotak kosong ke bawah
void ap_dua(Puzzle A,Kotak k); //Kotak kosong ke kiri
void ap_tiga(Puzzle A,Kotak k); //Kotak kosong ke atas

void ap_master(Puzzle A,int &flag,Kotak k);


#endif // ATURAN_PRODUKSI_H_INCLUDED
