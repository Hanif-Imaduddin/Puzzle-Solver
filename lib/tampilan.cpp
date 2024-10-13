#include "../include/tampilan.h"

void cetak_puzzle(string metode,Puzzle A){
    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    if (metode == "ln"){
        cout<<endl;
    }
}

void cetak_aturan_produksi(string metode){
    cout<<"Aturan produksi (elemen nol sebagai tanda kotak kosong): "<<endl;
    cout<<"AP 0: Geser kotak kosong ke kanan"<<endl;
    cout<<"AP 1: Geser kotak kosong ke bawah"<<endl;
    cout<<"AP 2: Geser kotak kosong ke kiri"<<endl;
    cout<<"AP 3: Geser kotak kosong ke atas"<<endl;
    if (metode == "ln"){
        cout<<endl;
    }
}

void cetak_header(string metode){
    cout<<"Puzzle Solver By Hanif Imaduddin";
    if (metode == "ln"){
        cout<<endl;
    }
}
