#include <iostream>
#include "NodeX.h"
#include "NodeY.h"
#include "SparseMatrix.h"

int main()
{

  SparseMatrix* matriz = new SparseMatrix();
  NodeX* nodo1 = new NodeX();
  matriz -> setStart(nodo1);
  NodeY* nodoc = new NodeY(2);
  matriz -> getStart() -> col = nodoc;
  std::cout << matriz -> getStart() -> col -> value << std::endl;
  
  return 0;
}
