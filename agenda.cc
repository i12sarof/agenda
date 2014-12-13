#include <iostream>
#include <list>
#include "cliente.h"
#include "interfaz.h"

using namespace std;

int main()
{
  int accion, aux1; string aux;
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
        cout<<"\nIntroduce el apellido del cliente a buscar:";
        aux1=0;
        cin>> aux;
        aux1=in.buscarCliente(aux);
        switch(aux1)
        {
          case 0:
            cout<<"\nNo existe el cliente "<<aux<<".\n";
            break;
          case 1:
            cout<<"\nDatos del cliente:\n";
            in.verCliente();
            break;
        }
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
