#include ".../include/pencarian.h"


int heuristik(Puzzle A, Puzzle B){
    int h;
    h = 0;

    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            if (A[i][j] == B[i][j]){
                h += 1;
            }
        }
    }
    return h;
}

void heuristik_max(int H[4],int &idx_max,int &h_max){
    h_max = H[0];
    idx_max = 0;
    for (size_t i = 1;i < 4;i++){
        if (H[i] > h_max){
            h_max = H[i];
            idx_max = i;
        }
    }
}

void get_row_col_kosong(Puzzle A,Kotak &k){
    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            if (A[i][j] == 0){
                k.row = i;
                k.col = j;
            }
        }
    }
}

void pindahkan_kotak(Kotak &k,int aturan_produksi){
    switch (aturan_produksi){
    case 0:
        k.col += 1;
        break;
    case 1:
        k.row += 1;
        break;
    case 2:
        k.col -= 1;
    case 3:
        k.row -= 1;
        break;
    }
}

void pencarian_heuristik(int solutions[N_SOLMAX],Puzzle A,Puzzle B){
    Puzzle P[4];
    int aturan_produksi,h;
    int H[4],F[4];
    Kotak kosong;
    get_row_col_kosong(A,kosong);
    h = 0;
    for (size_t i = 0;i < N_SOLMAX & h != 9;i++){
        for (size_t j = 0;j < 4;j++){
            F[j] = ap_master(P[j],j,kosong);
            if (F[j] != -1){
                H[0] = heuristik(P[j],B);
            }else{
                H[0] = -1;
            }
        }
        heuristik_max(H,aturan_produksi,h);
        ap_master(A,aturan_produksi,kosong);
        pindahkan_kotak(kosong,aturan_produksi);
    }
}
