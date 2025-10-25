#include "SparseMatrix.h" 
using namespace std;
#include <iostream>
#include <string.h>
#include <cmath>
#include <random>
#include <chrono>
#include <string>
#include <stack>
using namespace std::chrono;

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

                        cout << "( " << actualX->x << ", " << actualY->y << " )" << actualY->value << endl;
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

int SparseMatrix::getXSize(){
            NodeX* actualX = start;
            int sizeX = 0;
            while (actualX != nullptr) {
                NodeY* actualY = actualX -> col;
                if (actualX -> x > sizeX){
                    sizeX = actualX -> x;
                }
                actualX = actualX -> next;
            }
            return sizeX;
        }
        
        int SparseMatrix::getYSize(){
            NodeX* actualX = start;
            NodeY* actualY = actualX -> col;
            int sizeY = 0;
            while (actualX != nullptr) {
                NodeY* actualY = actualX -> col;
                while (actualY != nullptr){
                    if (actualY -> y > sizeY){
                        sizeY = actualY -> y;
                    }
                    actualY = actualY -> next;
                }
                actualX = actualX -> next;
            }
            return sizeY;
        }

        SparseMatrix::SparseMatrix(){start = nullptr;}
        NodeX* SparseMatrix::getStart(){return start;}
        void SparseMatrix::setStart(NodeX* inicial) {start = inicial;}
        
        
        void SparseMatrix::TestAll(){
            int datos;
            int density;
            int cols;
            int fils;
            stack<int> coordX;
            stack<int> coordY;
            double totalTime;
            cout<<"Ingrese el número de datos: ";
            std::cin >> datos;
            cout<<"Ingrese la densidad a testear: ";
            cin >> density;
            while (density >= 40 && density =< 70){
                cout<<"Ingrese la densidad a testear(Mayor a 70 o menor a 30): ";
                cin >> density;
            } 
            if (density > 70){
                cols = sqrt(datos) + 1;
                fils = sqrt(datos) + 1;
            } else if (density < 40){
                cols = datos / 3;
                fils = datos / 3;
            }
            for (int i = 1; i <= datos; i++){
                int x = rand() % cols - 1;
                int y = rand() % fils - 1;
                int value = rand() % 100 + 1;
                auto start = std::chrono::system_clock::now();
                add(value, x, y);
                auto final = std::chrono::system_clock::now();
                std::chrono::duration<double> timeAdd = (final - start);
                double ms1 = timeAdd.count() * 1000.0;
                totalTime += ms1;
                std::cout << "Añadir test " <<i<<": "<< ms1 << " ms" << std::endl;

            }
            cout << "El tiempo total de ejecución de los algoritmos es de: " << totalTime << endl;
            cout << "-----------------------------------"<<endl;
            
            for (int i = 1; i <= datos; i++){
                auto start = std::chrono::system_clock::now();
                get(coordX.top(), coordY.top());
                coordY.pop();
                coordX.pop();
                auto final = std::chrono::system_clock::now();
                std::chrono::duration<double> timeAdd = (final - start);
                double ms1 = timeAdd.count() * 1000.0;
                totalTime += ms1;
                std::cout << "Añadir test " <<i<<": "<< ms1 << " ms" << std::endl;

            }
            cout<< "El tiempo total de ejecución de los algoritmos get es de: " << totalTime << endl;
            cout<< "Terminando testeo."<< endl;
            
        }

       
