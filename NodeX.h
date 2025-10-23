#pragma once
#include <iostream>
#include "NodeY.h"
using namespace std;

class NodeX {
    public:
        int x;
        NodeY* col;
        NodeX* next;
        NodeX(int xPosicion);
        ~NodeX(){};
};
