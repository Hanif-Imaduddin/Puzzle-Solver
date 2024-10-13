#ifndef OPERASI_DASAR_H_INCLUDED
#define OPERASI_DASAR_H_INCLUDED
#include "entity.h"
#include <iostream>
#include <string>

using namespace std;

void baca_puzzle(Puzzle &A);

void proses_perintah(int perintah);

void salin_puzzle(Puzzle A,Puzzle B);

bool sama_dengan_puzzle(Puzzle A,Puzzle B);

string puzzle_to_string(Puzzle A);

#endif // OPERASI_DASAR_H_INCLUDED
