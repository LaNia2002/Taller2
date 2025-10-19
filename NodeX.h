#pragma once
#include <iostream>
#include "NodeY.h"
using namespace std;

class NodeX {
    public:
        NodeY* col;
        NodeX* next;
        NodeX();
        ~NodeX(){};
};
