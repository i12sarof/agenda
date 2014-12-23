#include <iostream>
#include <list>
#include "cliente.h"
#ifndef INTERFAZ_H
#define INTERFAZ_H

using namespace std;

class Interfaz{
  private:
    Cliente client;
  public:
    void menu();
    void setCliente(Cliente man) { client=man;};
    Cliente getCliente() { return client;};
    Cliente crearCliente();
    int addCliente(Cliente tipo, string nombre);
    void verCliente(Cliente aux);
    Cliente buscarCliente(string apellido, int &existe);
    int borrarCliente(string apellido);
    int menuMod();
    list <Cliente> getLista();
    void modificaCliente(string apellido, string aux, int accion);
    void copiaSeguridad();
};

#endif
