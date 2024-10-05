#ifndef PENCARIAN_H_INCLUDED
#define PENCARIAN_H_INCLUDED
#include "entity.h"
#include "aturan_produksi.h"

int heuristik(Puzzle A, Puzzle B);
void heuristik_max(int H[4],int &idx_max,int &h_max);
void get_row_col_kosong(Puzzle A,Kotak &k);
void pindahkan_kotak(Kotak &k);
void pencarian_heuristik(Puzzle A,Puzzle B);


#endif // PENCARIAN_H_INCLUDED
