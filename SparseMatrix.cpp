#include "SparseMatrix.h" 
using namespace std;
#include <iostream>
#include <string.h>

        void add(int value, int xPos, int yPos); 
        int get(int xPos, int yPos); 
        void remove(int xPos, int yPos); 
        void printStoredValues(); 
        int density(); 
        SparseMatrix* multiply(SparseMatrix* second); 

        SparseMatrix::SparseMatrix(){start = nullptr;}
        NodeX* SparseMatrix::getStart(){return start;}
        void SparseMatrix::setStart(NodeX* inicial) {start = inicial;}
