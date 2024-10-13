#ifndef PENCARIAN_H_INCLUDED
#define PENCARIAN_H_INCLUDED

#include "entity.h"
#include "aturan_produksi.h"
#include "operasi_dasar.h"
#include "four_ary_tree.h"
#include "tampilan.h"
#include <iostream>

Kotak get_lokasi_kotak_kosong(Puzzle A);
void geser_kotak_kosong(Kotak &k,int flag);

void traverse(PuzzleTree,elmPuzzleTree*,Kotak,Puzzle,int*,int&,bool&);

void cari_solusi(Puzzle IS, Puzzle GS);

#endif // PENCARIAN_H_INCLUDED
