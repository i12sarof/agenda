#include <iostream>
#include <string>
#include <fstream>
#include "cliente.h"
#include "interfaz.h"

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
//  return clien;
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
  fstream archivo("agenda.txt", ios:: in);

  archivo<<client.getDNI()<<","<<client.getNombre()<<","<<client.getApellidos()<<","<<client.getTlfno()<<","<<client.getCorreo()<<","<<client.getDireccion()<<","<<client.getRedesSociales()<<","<<client.getVistas();

  archivo.close();
  return 1;
}

int Interfaz:: buscarCliente()
{
  return 1;
}
