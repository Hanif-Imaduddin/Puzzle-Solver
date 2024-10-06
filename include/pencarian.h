#ifndef PENCARIAN_H_INCLUDED
#define PENCARIAN_H_INCLUDED
#include "entity.h"
#include "aturan_produksi.h"
#include "operasi_dasar.h"

#include "tampilan.h"
#include <iostream>

int heuristik(Puzzle A, Puzzle B);
void heuristik_max(int H[4],int &idx_max,int &h_max);
void get_row_col_kosong(Puzzle A,Kotak &k);
void pindahkan_kotak(Kotak &k);
void pencarian_heuristik(int solutions[N_SOLMAX],int &n_solusi,Puzzle &A,Puzzle B);


#endif // PENCARIAN_H_INCLUDED
