#include <iostream>
#include "include/entity.h"
#include "include/operasi_dasar.h"
#include "include/tampilan.h"
#include "include/pencarian.h"


using namespace std;

int main()
{
    Puzzle IS,GS;
    cout<<"Masukan initial state"<<endl;
    baca_puzzle(IS);
    cout<<"Masukan goal state"<<endl;
    baca_puzzle(GS);

    cari_solusi(IS,GS);
    cout<<"Hasil:"<<endl;
    cetak_puzzle("ln",IS);
    return 0;
}
