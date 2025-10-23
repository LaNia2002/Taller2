#pragma once
#include <iostream>
using namespace std;

class NodeY {
    public:
    
        int y;
        int value;
        NodeY* next;
        NodeY(int yPosicion, int val);
        ~NodeY(){};
};
