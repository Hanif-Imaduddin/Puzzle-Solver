#include ".../include/aturan_produksi.h"

void ap_nol(Puzzle A,Kotak k){
    int temp;
    temp = A[k.row][k.col+1];
    A[k.row][k.col+1] = A[k.row][k.col];
    A[k.row][k.col] = temp;
}

void ap_satu(Puzzle A,Kotak k){
    int temp;
    temp = A[k.row-1][k.col];
    A[k.row-1][k.col] = A[k.row][k.col];
    A[k.row][k.col] = temp;
}


void ap_dua(Puzzle A,Kotak k){
    int temp;
    temp = A[k.row][k.col-1];
    A[k.row][k.col-1] = A[k.row][k.col];
    A[k.row][k.col] = temp;
}

void ap_tiga(Puzzle A,Kotak k){
    int temp;
    temp = A[k.row+1][k.col];
    A[k.row+1][k.col] = A[k.row][k.col];
    A[k.row][k.col] = temp;
}

void ap_master(Puzzle A,int &flag,Kotak k){
    if (flag == 0){
        if (col == 2){
            flag = -1
        }else{
            ap_nol(A,k);
        }
    }else if (flag == 1){
        if (row == 2){
            flag = -1;
        }else{
            ap_satu(A,k);
        }
    }else if (flag == 2){
        if (col == 0){
            flag = -1;
        }else{
            ap_dua(A,k);
        }
    }else if (flag == 3){
        if (row == 0){
            flag = -1;
        }else{
            ap_tiga(A,k);
        }
    }
}
