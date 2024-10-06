#include <iostream>
#include "include/entity.h"
#include "include/operasi_dasar.h"
#include "include/tampilan.h"
#include "include/pencarian.h"


using namespace std;

int main()
{
    bool stop;
    int perintah;
    int solusi[N_SOLMAX],n_solusi;
    Puzzle A,B;
    perintah = -1;
    stop = false;
    while(!stop){
        cetak_header("ln");
        cetak_aturan_produksi("ln");
        cout<<"Masukan initial state: "<<endl;
        baca_puzzle(A);
        cout<<"Masukan final state: "<<endl;
        baca_puzzle(B);

        pencarian_heuristik(solusi,n_solusi,A,B);
        if(n_solusi <= 0){
            cout<<"Solusi dari puzzle tersebut tidak ditemukan "<<n_solusi<<endl;
        }else{
            cout<<"Solusi dari puzzle tersebut adalah: ";
            cetak_solusi("ln",solusi,n_solusi);
            cout<<"Hasil: "<<endl;
            cetak_puzzle("ln",A);
        }
        cin>>perintah;
        stop = perintah == 0;
    }
    return 0;
}
