#include "../include/operasi_dasar.h"

void baca_puzzle(Puzzle &A){
    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            cin>>A[i][j];
        }
    }
}

void salin_puzzle(Puzzle A,Puzzle B){
    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            A[i][j] = B[i][j];
        }
    }
}




