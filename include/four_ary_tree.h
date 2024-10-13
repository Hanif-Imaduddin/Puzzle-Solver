#ifndef FOUR_ARY_TREE_H_INCLUDED
#define FOUR_ARY_TREE_H_INCLUDED
#include "entity.h"
#include "operasi_dasar.h"


struct elmPuzzleTree{
    Puzzle info;
    elmPuzzleTree *children[4];
    elmPuzzleTree(Puzzle);
};

struct PuzzleTree{
private:
    void traverseSearch(elmPuzzleTree*,elmPuzzleTree*&,Puzzle);
    void traverseDelete(elmPuzzleTree*);
    void traversePrint(elmPuzzleTree*);
public:
    elmPuzzleTree *root;

    PuzzleTree();
    elmPuzzleTree* searchElm(Puzzle);
    void insertRoot(Puzzle);
    void insertChild(Puzzle,Puzzle,int);
    void deleteChild(Puzzle);
    void printAll();
    void deleteAll();
};

#endif // FOUR_ARY_TREE_H_INCLUDED
