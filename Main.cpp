#include <iostream>
#include "NodeX.h"
#include "NodeY.h"
#include "SparseMatrix.h"

int main()
{
  SparseMatrix* matriz = new SparseMatrix();
  int opcion = 1;
  while (opcion != 7) {

    cout<<"Menu Matriz"<<endl;
    cout<<""<<endl;
    cout<<"1) Agregar valor"<<endl;
    cout<<"2) Obtener valor"<<endl;
    cout<<"3) Eliminar valor"<<endl;
    cout<<"4) Imprimir valores almacenados"<<endl;
    cout<<"5) Calcular densidad"<<endl;
    cout<<"6) Multiplicar matrices"<<endl;
    cout<<"7.) Salir"<<endl;

    cin>>opcion;

    while (opcion < 1 || opcion > 7){
          cout << "Opción inválida. Intente nuevamente." << endl;
          cin>>opcion;
      }

    if(opcion==1){
      int valor, xPos, yPos;
      cout<<"Ingrese el valor a agregar: ";
      cin>>valor;
      cout<<"Ingrese la posicion x: ";
      cin>>xPos;
      cout<<"Ingrese la posicion y: ";
      cin>>yPos;
      matriz -> add(valor, xPos, yPos);
    }

    else if(opcion==2){
      int xPos, yPos;
      cout<<"Ingrese la posicion x: ";
      cin>>xPos;
      cout<<"Ingrese la posicion y: ";
      cin>>yPos;
      cout<<"El valor en la posicion ("<<xPos<<","<<yPos<<") es: "<<matriz -> get(xPos, yPos)<<endl;
    }

    else if(opcion==3){
      int xPos, yPos;
      cout<<"Ingrese la posicion x: ";
      cin>>xPos;
      cout<<"Ingrese la posicion y: ";
      cin>>yPos;
      matriz -> remove(xPos, yPos);}

    else if(opcion==4){
      matriz -> printStoredValues();}

    else if(opcion==5){
      int densidad = matriz -> density(); 
        if (densidad != 0) {
            cout<<"La densidad de la matriz es: "<< densidad <<"%"<<endl;
        }

    else if(opcion==6){
    }

  };
  }


  
  return 0;
}
