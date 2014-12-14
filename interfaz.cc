#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "cliente.h"
#include "interfaz.h"

using namespace std;

void Interfaz:: menu()
{
  cout<<"\nAccion a realizar:";
  cout<<"\nCrear cliente-------------->1.";
  cout<<"\nBuscar cliente------------->2.";
  cout<<"\nBorrar cliente------------->3.";
  cout<<"\nModificar cliente---------->4.";
  cout<<"\nCrear copia de seguridad--->5.";
  cout<<"\nOrdenar clientes----------->6.";
  cout<<"\nSalir---------------------->0.\n";
}

void Interfaz:: crearCliente()
{
  string aux;
  cout<<"\nDNI:";
  cin>> aux;
  client.setDNI(aux);
  cout<<"\nNombre:";
  cin>> aux;
  client.setNombre(aux);
  cout<<"\nApellidos:";
  cin>> aux;
  client.setApellidos(aux);
  cout<<"\nTlfno:";
  cin>> aux;
  client.setTlfno(aux);
  cout<<"\nCorreo:";
  cin>> aux;
  client.setCorreo(aux);
  cout<<"\nDireccion:";
  cin>> aux;
  client.setDireccion(aux);
  cout<<"\nRedes Sociales:";
  cin>> aux;
  client.setRedesSociales(aux);
  client.setVistas(0);
//  return client;
}

void Interfaz:: verCliente()
{
  cout<<"DNI:"<<client.getDNI();
  cout<<"\nNombre:"<<client.getNombre();
  cout<<"\nApellidos:"<<client.getApellidos();
  cout<<"\nTlfno:"<<client.getTlfno();
  cout<<"\nCorreo:"<<client.getCorreo();
  cout<<"\nDireccion:"<<client.getDireccion();
  cout<<"\nRedes Sociales:"<<client.getRedesSociales();
  cout<<"\nVeces visitado:"<<client.getVistas();
}

int Interfaz:: addCliente()
{
  ofstream archivo("agenda.txt", ios::app);

 // setCliente(persona);
  archivo<<client.getDNI()<<","<<client.getNombre()<<","<<client.getApellidos()<<","<<client.getTlfno()<<","<<client.getCorreo()<<","<<client.getDireccion()<<","<<client.getRedesSociales()<<","<<client.getVistas()<<"\n";
  archivo.close();
  return 1;
}

int Interfaz:: buscarCliente(string apellido)
{
  ifstream archivo("agenda.txt");
  char dni[128], nombre[128], apellidos[128], tlfno[128], correo[128], direccion[128], redes[128], vistas[128];
  int existe=0;
  while( archivo.getline(dni,128, ',') )
  {
    archivo.getline(nombre, 128, ',');
    archivo.getline(apellidos, 128, ',');
    archivo.getline(tlfno, 128, ',');
    archivo.getline(correo, 128, ',');
    archivo.getline(direccion, 128, ',');
    archivo.getline(redes, 128, ',');
    archivo.getline(vistas, 128, '\n');
    if(apellido==apellidos)
    {
      existe=1;
      break;
    }
  }
  archivo.close();
  if(existe==1)
  {
    client.setDNI(dni);
    client.setNombre(nombre);
    client.setApellidos(apellido);
    client.setTlfno(tlfno);
    client.setCorreo(correo);
    client.setDireccion(direccion);
    client.setRedesSociales(redes);
    client.setVistas(atoi(vistas));
  }
  return existe;
}

int Interfaz:: borrarCliente(string apellido)
{
  int existe=0;
  Interfaz inter;
  char dni[128], nombre[128], apellidos[128], tlfno[128], correo[128], direccion[128], redes[128], vistas[128];
  existe=inter.buscarCliente(apellido);
  if(existe)
  {
    ifstream archivo("agenda.txt");
    ofstream archivo2("tmp.txt");
    while( archivo.getline(dni, 128, ','))
    {
      archivo.getline(nombre, 128, ',');
      archivo.getline(apellidos, 128, ',');
      archivo.getline(tlfno, 128, ',');
      archivo.getline(correo, 128, ',');
      archivo.getline(direccion, 128, ',');
      archivo.getline(redes, 128, ',');
      archivo.getline(vistas, 128, '\n');
      if(apellidos!=apellido)
      {
          archivo2<<dni<<","<<nombre<<","<<apellidos<<","<<tlfno<<","<<correo<<","<<direccion<<","<<redes<<","<<vistas<<"\n";
      }
    }
    archivo.close();
    archivo2.close();
    remove("agenda.txt");
    rename("tmp.txt", "agenda.txt");
    return existe;
  }
  else
  {
    return existe;
  }
}
