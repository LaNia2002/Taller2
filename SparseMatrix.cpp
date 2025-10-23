#include "SparseMatrix.h" 
using namespace std;
#include <iostream>
#include <string.h>

         void SparseMatrix::add(int value, int xPos, int yPos) {
                if (value == 0) return; 
                NodeX* actualX = start;
                NodeX* prevX = nullptr;

                while (actualX != nullptr && actualX->x < xPos) {
                        prevX = actualX;
                        actualX = actualX->next;}

                if (actualX == nullptr || actualX->x != xPos) {

                        NodeX* nuevoX = new NodeX(xPos);
                        if (prevX == nullptr) {
                        nuevoX->next = start;
                        start = nuevoX;} 
                        else {
                        nuevoX->next = actualX;
                        prevX->next = nuevoX;}
                        actualX = nuevoX;}

                NodeY* actualY = actualX->col;
                NodeY* prevY = nullptr;

                while (actualY != nullptr && actualY->y < yPos) {
                        prevY = actualY;
                        actualY = actualY->next;}

                if (actualY != nullptr && actualY->y == yPos) {
                        actualY->value = value;} 

                        else {
                        NodeY* nuevoY = new NodeY(yPos, value);
                        if (prevY == nullptr) {
                        nuevoY->next = actualX->col;
                        actualX->col = nuevoY;
                        } else {
                        nuevoY->next = actualY;
                        prevY->next = nuevoY;}
                }}

        int SparseMatrix::get(int xPos, int yPos) {
                NodeX* actualX = start;

                while (actualX != nullptr && actualX->x < xPos){
                        actualX = actualX->next;}

                if (actualX == nullptr || actualX->x != xPos)
                        return 0;

                NodeY* actualY = actualX->col;
                while (actualY != nullptr && actualY->y < yPos){
                        actualY = actualY->next;}

                if (actualY == nullptr || actualY->y != yPos)
                        return 0;

                return actualY->value;}

        void remove(int xPos, int yPos); 
        void printStoredValues(); 
        int density(); 
        SparseMatrix* multiply(SparseMatrix* second); 

        SparseMatrix::SparseMatrix(){start = nullptr;}
        NodeX* SparseMatrix::getStart(){return start;}
        void SparseMatrix::setStart(NodeX* inicial) {start = inicial;}
