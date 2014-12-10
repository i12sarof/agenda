#include <iostream>
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
    void crearCliente();
    int addCliente();
    void verCliente();
    int buscarCliente();
};

#endif
