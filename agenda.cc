#include <iostream>
#include <list>
#include <fstream>
#include "cliente.h"
#include "interfaz.h"

using namespace std;

int main()
{
  int accion, existe; string aux, aux2;
  Interfaz in;
  Cliente clien;
  list <Cliente> lista;

  do{
    in.menu();
    cin>>accion;
    switch(accion)
    {
      case 1:
        cout<<"\nIntroduce datos del cliente:";
        clien=in.crearCliente();
//        in.verCliente(clien);
        in.addCliente(clien, "agenda.txt");
        cout<<"\nCliente introducido.\n";
        break;
      case 2:
        cout<<"\nIntroduce el apellido del cliente a buscar:";
        cin>> aux;
        clien=in.buscarCliente(aux, existe);
        switch(existe)
        {
          case 0:
            cout<<"\nNo existe el cliente "<<aux<<".\n";
            break;
          case 1:
            cout<<"\nDatos del cliente:\n";
            in.verCliente(clien);
            in.modificaCliente(clien.getApellidos(), "nada", 8);
            break;
        }
        break;
      case 3:
        cout<<"\nIntroduce el cliente a borrar:";
        cin>>aux;
        existe=in.borrarCliente(aux);
        if(existe)
        {
          cout<<"\nCliente borrado.\n";
        }else
        {
          cout<<"\nNo se encontro el cliente o se produjo un error.\n";
        }
        break;
      case 4:
        cout<<"\nIntroduce el apellido del cliente a modificar:";
        cin>>aux;
        clien=in.buscarCliente(aux, existe);
        switch(existe)
        {
          case 0:
            cout<<"\nNo se encontro el cliente o se produjo un error en la lectura.\n";
            break;
          case 1:
            cout<<"\nIntroduce el campo a modificar:";
            accion=in.menuMod();
            cout<<"\nIntroduce el nuevo valor:";
            cin>>aux2;
            in.modificaCliente(aux, aux2, accion);
            break;
         }
        break;
      case 5:
        in.ordenar();
        cout<<"\nClientes ordenados.";
        break;
      case 6:
        in.copiaSeguridad();
        ifstream archivo("agendabin", ios:: binary);
        if(archivo.is_open())
        {
          cout<<"\nCopia de seguridad realizada con exito.\n";
          archivo.close();
        }else{
          cout<<"\nError, no se pudo crear la copia de seguridad.\n";
          archivo.close();
        }
        break;
    }
  }while(accion!=0);
  return 0;
}
