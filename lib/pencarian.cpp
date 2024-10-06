#include "../include/pencarian.h"
#include <iostream>
using namespace std;

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
        break;
    case 3:
        k.row -= 1;
        break;
    }
}

void pencarian_heuristik(int solutions[N_SOLMAX],int &n_solusi,Puzzle &A,Puzzle B){
    Puzzle P[4];
    int ap_invers[] = {2,3,0,1};
    int aturan_produksi,prev_ap,h;
    int H[4],F[4];
    Kotak kosong;
    get_row_col_kosong(A,kosong);
    h = -1;
    prev_ap = -1;
    n_solusi = 0;
    cout<<"Mencari solusi..."<<endl;
    for (size_t i = 0;i < N_SOLMAX & h != 9;i++){
        for (size_t j = 0;j < 4;j++){
            if (j != prev_ap){
                //cout<<i<<". P["<<j<<"]"<<endl;
                salin_puzzle(P[j],A);
                //cetak_puzzle("ln",P[j]);
                F[j] = j;
                ap_master(P[j],F[j],kosong);
                if (F[j] != -1 && j != prev_ap){
                H[j] = heuristik(P[j],B);
                }else{
                H[j] = -1;
                }
                //cetak_puzzle("ln",P[j]);
            }else{
                H[j] = -1;
            }
        }
        heuristik_max(H,aturan_produksi,h);
        ap_master(A,aturan_produksi,kosong);
        pindahkan_kotak(kosong,aturan_produksi);
        solutions[n_solusi] = aturan_produksi;
        prev_ap = ap_invers[aturan_produksi];
        n_solusi++;
        cout<<"Iterasi ke "<<i<<" Dengan aturan produksi "<<aturan_produksi<<" Dan heuritik "<<h<<endl;
        cetak_puzzle("ln",A);
    }
    /*if (h != 9){
        n_solusi = -1;
    }*/
}
