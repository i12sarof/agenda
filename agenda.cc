#include <iostream>
#include <list>
#include "cliente.h"
#include "interfaz.h"

using namespace std;

int main()
{
  int accion;
  Interfaz in;
  Cliente clien;

  do{
    in.menu();
    cin>>accion;
    switch(accion)
    {
      case 1:
        cout<<"\nIntroduce datos del cliente:";
        in.crearCliente();
//        in.verCliente();
        in.addCliente();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
    }
  }while(accion!=0);
  return 0;
}
