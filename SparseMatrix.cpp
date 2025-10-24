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

        void SparseMatrix::remove(int xPos, int yPos) {

                NodeX* actualX = start;
                NodeX* prevX = nullptr;
                 
                while (actualX != nullptr && actualX->x < xPos) {
                        prevX = actualX;
                        actualX = actualX->next;}

                if (actualX == nullptr || actualX->x != xPos){
                        return;}

                NodeY* actualY = actualX->col;
                NodeY* prevY = nullptr;

                while (actualY != nullptr && actualY->y < yPos) {
                        prevY = actualY;
                        actualY = actualY->next;}

                if (actualY == nullptr || actualY->y != yPos){
                        return;} 

                if (prevY == nullptr){
                        actualX->col = actualY->next;}
                else{
                        prevY->next = actualY->next;}

                delete actualY;
                 
                if (actualX->col == nullptr) {
                        if (prevX == nullptr)
                        start = actualX->next;
                        else
                        prevX->next = actualX->next;

                        delete actualX;}} 

        void SparseMatrix::printStoredValues() {
                NodeX* actualX = start;

                if (actualX == nullptr) {
                        cout << "La matriz se encuentra vacía" << endl;
                        return;}

                while (actualX != nullptr) {

                        NodeY* actualY = actualX->col;
                        while (actualY != nullptr) {

                        cout << "En la cordenada x: " << actualX->x << " y en la cordenada y: " << actualY->y << " , se encuentra el valor: " << actualY->value << endl;
                        actualY = actualY->next;}

                        actualX = actualX->next;}}

        int SparseMatrix::density(){
                  NodeX* actualX = start;
                  int sizeX = 0;
                  int sizeY = 0;
                  int nodes = 0;
                  if (actualX == nullptr){
                           cout << "La matriz se encuentra vacía" << endl;
                  return 0;}
            
            while (actualX != nullptr) {
                NodeY* actualY = actualX -> col;
                while (actualY != nullptr){
                    if (actualY -> value != 0){
                        nodes++;
                    }
                    if (actualY -> y > sizeY){
                        sizeY = actualY -> y;
                    }
                    actualY = actualY -> next;
                }
                if (actualX -> x > sizeX){
                    sizeX = actualX -> x;
                }
                actualX = actualX -> next;
            }
            sizeY++;
            sizeX++;
            int size = sizeY * sizeX;
            double porcentage = (double) nodes/size * 100;
            return porcentage;
        }

        SparseMatrix* multiply(SparseMatrix* second); 

        SparseMatrix::SparseMatrix(){start = nullptr;}
        NodeX* SparseMatrix::getStart(){return start;}
        void SparseMatrix::setStart(NodeX* inicial) {start = inicial;}
