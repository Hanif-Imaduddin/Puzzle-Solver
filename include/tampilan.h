#ifndef TAMPILAN_H_INCLUDED
#define TAMPILAN_H_INCLUDED
#include "entity.h"
#include <iostream>

using namespace std;

void cetak_puzzle(string metode,Puzzle A);

void cetak_solusi(string metode,int S[N_SOLMAX],int n_solusi);

void cetak_aturan_produksi(string metode);

void cetak_pilihan(string metode);

void cetak_header(string metode);
#endif // TAMPILAN_H_INCLUDED
