#pragma once 
#include "NodeX.h" 
class SparseMatrix { 
    private: 
        NodeX* start; 
    public: 
        SparseMatrix(); 
        NodeX* getStart();
        void setStart(NodeX*);
        void add(int value, int xPos, int yPos); 
        int get(int xPos, int yPos); 
        void remove(int xPos, int yPos); 
        void printStoredValues(); 
        int density(); 
        SparseMatrix* multiply(SparseMatrix* second); 
        void TestAll();
        int getXSize();
        int getYSize();
        ~SparseMatrix(); 
}; 
