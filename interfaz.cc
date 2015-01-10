#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <list>
#include "cliente.h"
#include "interfaz.h"

using namespace std;

void Interfaz:: menu()
{
  cout<<"\nElige accion a realizar:";
  cout<<"\nCrear cliente-------------->1.";
  cout<<"\nBuscar cliente------------->2.";
  cout<<"\nBorrar cliente------------->3.";
  cout<<"\nModificar cliente---------->4.";
  cout<<"\nOrdenar clientes----------->5.";
  cout<<"\nCrear copia de seguridad--->6.";
  cout<<"\nSalir---------------------->0.\n";
}

int Interfaz:: menuMod()
{
  int aux;
  cout<<"\nSelecciona que modificar:";
  cout<<"\nDNI------------------------>1.";
  cout<<"\nNombre--------------------->2.";
  cout<<"\nApellidos------------------>3.";
  cout<<"\nCambiar Tlfno-------------->4.";
  cout<<"\nAñadir Tlfno--------------->5.";
  cout<<"\nCorreo--------------------->6.";
  cout<<"\nDireccion------------------>7.";
  cout<<"\nRedes---------------------->8.\n";
  cin>>aux;
  return aux;
}

Cliente Interfaz:: crearCliente()
{
  string aux; Cliente tipo;
  cout<<"\nDNI:";
  cin>> aux;
  tipo.setDNI(aux);
  cout<<"\nNombre:";
  cin>> aux;
  tipo.setNombre(aux);
  cout<<"\nApellidos:";
  cin>> aux;
  tipo.setApellidos(aux);
  cout<<"\nTlfno:";
  cin>> aux;
  aux+=";";
  tipo.setTlfno(aux);
  cout<<"\nCorreo:";
  cin>> aux;
  tipo.setCorreo(aux);
  cout<<"\nDireccion:";
  cin>> aux;
  tipo.setDireccion(aux);
  cout<<"\nRedes Sociales:";
  cin>> aux;
  tipo.setRedesSociales(aux);
  tipo.setVistas(0);
  return tipo;
}

void Interfaz:: verCliente(Cliente aux)
{
  string auxb;
  cout<<"\nDNI:"<<aux.getDNI();
  cout<<"\nNombre:"<<aux.getNombre();
  cout<<"\nApellidos:"<<aux.getApellidos();
  cout<<"\nTelefono/s:";

  auxb=aux.getTlfno();
  cout<<"\n";
  for(unsigned int i=0; i!=auxb.length(); i++)
  {
    if(auxb[i]!=';')
      cout<<auxb[i];
    else
      cout<<"\n";
  }
  cout<<"Correo:"<<aux.getCorreo();
  cout<<"\nDireccion:"<<aux.getDireccion();
  cout<<"\nRedes Sociales:"<<aux.getRedesSociales();
  cout<<"\nVeces visitado:"<<aux.getVistas()<<"\n";
}

int Interfaz:: addCliente(Cliente tipo, string nombre)
{
  ofstream archivo(nombre.c_str(), ios::app);

  archivo<<tipo.getDNI()<<","<<tipo.getNombre()<<","<<tipo.getApellidos()<<","<<tipo.getTlfno()<<","<<tipo.getCorreo()<<","<<tipo.getDireccion()<<","<<tipo.getRedesSociales()<<","<<tipo.getVistas()<<"\n";
  archivo.close();
  return 1;
}

Cliente Interfaz:: buscarCliente(string apellido, int &existe)
{
  ifstream archivo("agenda.txt");
  char dni[128], nombre[128], apellidos[128], tlfno[128], correo[128], direccion[128], redes[128], vistas[128];
  Cliente aux;
  existe=0;
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
    aux.setDNI(dni);
    aux.setNombre(nombre);
    aux.setApellidos(apellido);
    aux.setTlfno(tlfno);
    aux.setCorreo(correo);
    aux.setDireccion(direccion);
    aux.setRedesSociales(redes);
    aux.setVistas(atoi(vistas));
  }
  return aux;
}

int Interfaz:: borrarCliente(string apellido)
{
  int existe=0;
  Interfaz inter;
  char dni[128], nombre[128], apellidos[128], tlfno[128], correo[128], direccion[128], redes[128], vistas[128];
  Cliente clien;
  clien=inter.buscarCliente(apellido, existe);
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

list <Cliente> Interfaz:: getLista()
{
  list <Cliente> aux;
  char dni[128], nombre[128], apellidos[128], tlfno[128], correo[128], direccion[128], redes[128], vistas[128];

  ifstream archivo("agenda.txt");

  while( archivo.getline(dni, 128, ','))
  {
    archivo.getline(nombre, 128, ',');
    archivo.getline(apellidos, 128, ',');
    archivo.getline(tlfno, 128, ',');
    archivo.getline(correo, 128, ',');
    archivo.getline(direccion, 128, ',');
    archivo.getline(redes, 128, ',');
    archivo.getline(vistas, 128, '\n');

    client.setDNI(dni);
    client.setNombre(nombre);
    client.setApellidos(apellidos);
    client.setTlfno(tlfno);
    client.setCorreo(correo);
    client.setDireccion(direccion);
    client.setRedesSociales(redes);
    client.setVistas(atoi(vistas));

    aux.push_back(client);
  }
  return aux;
}

void Interfaz:: modificaCliente(string apellido, string aux, int accion)
{
  list <Cliente> lista;
  list <Cliente>:: iterator i;
  Interfaz in; int auxb;
  lista=in.getLista();
  for(i=lista.begin(); i!=lista.end(); i++)
  {
    if(i->getApellidos()==apellido)
    {
      switch(accion)
      {
        case 1:
          i->setDNI(aux);
          break;
        case 2:
          i->setNombre(aux);
          break;
        case 3:
          i->setApellidos(aux);
          break;
        case 4:
          i->setTlfno(aux);
          break;
        case 5:
          aux+=";";
          aux+=i->getTlfno();
          i->setTlfno(aux);
          break;
        case 6:
          i->setCorreo(aux);
          break;
        case 7:
          i->setDireccion(aux);
          break;
        case 8:
          i->setRedesSociales(aux);
          break;
        case 100:
          auxb=i->getVistas();
          i->setVistas((auxb+1));
          break;
      }
    }
    in.addCliente(*i, "tmp.txt");
  }
  remove("agenda.txt");
  rename("tmp.txt", "agenda.txt");
}

void Interfaz:: copiaSeguridad()
{
  list <Cliente> lista;
  Interfaz in;
  lista=in.getLista();
  list <Cliente>:: iterator i;
  ofstream copia("agendabin", ios:: binary);

  for(i=lista.begin(); i!=lista.end(); i++)
  {
    copia<<i->getDNI()<<","<<i->getNombre()<<","<<i->getApellidos()<<","<<i->getTlfno()<<","<<i->getCorreo()<<","<<i->getDireccion()<<","<<i->getRedesSociales()<<","<<i->getVistas()<<"\n";
  }
  copia.close();
}

bool comparapellidos(Cliente &c1, Cliente &c2)
{
  return c1.getApellidos()<c2.getApellidos();
}

void Interfaz:: ordenar()
{
  list <Cliente> clientes;
  list <Cliente>:: iterator i;
  clientes=getLista();

/*  cout<<"\nLista sin ordenar:\n";
  for(i=clientes.begin(); i!=clientes.end(); i++)
  {
    verCliente(*i);
  }*/

  clientes.sort(comparapellidos);
//  cout<<"\nLista ordenada:\n";
  for(i=clientes.begin(); i!=clientes.end(); i++)
  {
//    verCliente(*i);
    addCliente(*i, "tmp.txt");
  }
  remove("agenda.txt");
  rename("tmp.txt", "agenda.txt");
}
