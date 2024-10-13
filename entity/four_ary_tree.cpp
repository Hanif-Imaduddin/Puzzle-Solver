#include "../include/four_ary_tree.h"
#include "../include/operasi_dasar.h"
#include "../include/tampilan.h"

elmPuzzleTree::elmPuzzleTree(Puzzle data){
    for (size_t i = 0;i < 3;i++){
        for (size_t j = 0;j < 3;j++){
            this->info[i][j] = data[i][j];
        }
    }
    for (size_t i = 0;i < 4;i++){
        this->children[i] = nullptr;
    }
}

PuzzleTree::PuzzleTree(){
    this->root = nullptr;
}

void PuzzleTree::traverseSearch(elmPuzzleTree* p,elmPuzzleTree* &q,Puzzle A){
    if (p != nullptr){
        if (sama_dengan_puzzle(A,p->info)){
            q = p;
        }
        if (q == nullptr){
            for (size_t i = 0;i < 4;i++){
                this->traverseSearch(p->children[i],q,A);
            }
        }
    }
}

void PuzzleTree::traverseDelete(elmPuzzleTree* p){
    if (p != nullptr){
        for (size_t i = 0;i < 4;i++){
            this->traverseDelete(p->children[i]);
            p->children[i] = nullptr;
        }
    }
    delete p;
}

void PuzzleTree::traversePrint(elmPuzzleTree* p){
    if (p != nullptr){
        int n_child;
        n_child = 0;
        cout<<"Node:"<<endl;
        cetak_puzzle("ln",p->info);
        cout<<"Children"<<endl;
        for (size_t i = 0;i < 4;i++){
            if (p->children[i] != nullptr){
                cetak_puzzle("ln",p->children[i]->info);
                n_child++;
            }
        }
        if (n_child == 0){
            cout<<"Tidak mempunyai anak"<<endl;
        }
        cout<<endl;
        for (size_t i = 0;i < 4;i++){
            this->traversePrint(p->children[i]);
        }
    }
}

elmPuzzleTree* PuzzleTree::searchElm(Puzzle A){
    if (this->root != nullptr){
        elmPuzzleTree *p,*q;
        p = this->root;
        q = nullptr;
        this->traverseSearch(p,q,A);
        return q;
    }else{
        return nullptr;
    }
}

void PuzzleTree::insertRoot(Puzzle A){
    this->root = new elmPuzzleTree(A);
}

void PuzzleTree::insertChild(Puzzle parentInfo,Puzzle childInfo,int position){
    if (position != -1){
        elmPuzzleTree * child = new elmPuzzleTree(childInfo);
        elmPuzzleTree * parent = this->searchElm(parentInfo);
        if (parent != nullptr){
            parent->children[position] = child;
        }
    }
}

void PuzzleTree::deleteChild(Puzzle A){
    elmPuzzleTree* node = searchElm(A);
    if (node != nullptr){
        traverseDelete(node);
    }
}

void PuzzleTree::printAll(){
    if (this->root != nullptr){
        traversePrint(this->root);
    }else{
        cout<<"Pohon kosong"<<endl;
    }
}

void PuzzleTree::deleteAll(){
    if (this->root != nullptr){
        this->traverseDelete(this->root);
        this->root = nullptr;
    }
}
