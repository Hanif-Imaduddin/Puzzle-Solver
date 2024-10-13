#include "../include/pencarian.h"

#include <iostream>
using namespace std;

Kotak get_lokasi_kotak_kosong(Puzzle A){
    Kotak k;
    k.row = -1;
    k.col = -1;
    for (size_t i = 0;i < 4;i++){
        for (size_t j = 0;j < 4;j++){
            if (A[i][j] == 0){
                k.row = i;
                k.col = j;
                return k;
            }
        }
    }
    return k;
}

void geser_kotak_kosong(Kotak &k,int flag){
    switch (flag){
    case 0:
        k.col++;
        break;
    case 1:
        k.row++;
        break;
    case 2:
        k.col--;
        break;
    case 3:
        k.row--;
        break;
    }
}
void traverse(PuzzleTree T,elmPuzzleTree* node,Kotak kotak_kosong,Puzzle GS,int *S,int &n_step,bool &found){
    Puzzle P;
    Kotak kotak_kosong_temp;
    int flag;
    elmPuzzleTree* adr;
    if (!found && n_step < MAX_DEPTH){
        for (size_t i = 0;i <4;i++){
            salin_puzzle(P,node->info);
            flag = i;
            ap_master(P,flag,kotak_kosong);
            if (flag != -1){
                adr = T.searchElm(P);
                if (adr == nullptr){
                    found = sama_dengan_puzzle(P,GS);
                    node->children[i] = new elmPuzzleTree(P);
                    *(S+n_step) = i;
                    n_step++;
                    kotak_kosong_temp.col = kotak_kosong.col;
                    kotak_kosong_temp.row = kotak_kosong.row;
                    geser_kotak_kosong(kotak_kosong_temp,flag);
                    traverse(T,node->children[i],kotak_kosong_temp,GS,S,n_step,found);
                    cout<<node<<endl;
                    cetak_puzzle("",node->info);
                    cout<<"n_step: "<<n_step<<endl;
                    if (found){
                        return;
                    }else{
                        n_step--;
                    }
                }
            }
        }
    }
}
void cari_solusi(Puzzle IS,Puzzle GS){
    int S[MAX_DEPTH],n_step;
    string step_dict[] = {"Geser kotak kosong ke kanan",
                        "Geser kotak kosong ke bawah",
                        "Geser kotak kosong ke kiri",
                        "Geser kotak kosong ke atas"};

    PuzzleTree T;
    Kotak kotak_kosong;
    bool found;

    n_step = 0;
    kotak_kosong = get_lokasi_kotak_kosong(IS);
    T.insertRoot(IS);
    found = sama_dengan_puzzle(IS,GS);
    traverse(T,T.root,kotak_kosong,GS,S,n_step,found);
    if (found){
        cout<<"Solusi:"<<endl;
        for (size_t i = 0;i < n_step;i++){
            cout<<i+1<<". "<<step_dict[S[i]]<<endl;
            ap_master(IS,S[i],kotak_kosong);
            geser_kotak_kosong(kotak_kosong,S[i]);
        }
    }else{
        cout<<"Solusi tidak ditemukan"<<endl;
        cout<<n_step<<endl;
    }
}
