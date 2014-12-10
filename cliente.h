#include <iostream>
#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

class Cliente{
  private:
    string DNI, Nombre, Apellidos, tlfno, Correo, Direccion, RedesSociales;
    int vistas;

  public:
    void setDNI(string a)  {DNI=a;};
    string getDNI() { return DNI;};
    void setNombre(string a) {Nombre=a;};
    string getNombre() { return Nombre;};
    void setApellidos(string a) { Apellidos=a;};
    string getApellidos() { return Apellidos;};
    void setTlfno(string a) { tlfno=a;};
    string getTlfno() { return tlfno;};
    void setCorreo(string a) { Correo=a;};
    string getCorreo() { return Correo;};
    void setDireccion(string a) { Direccion=a;};
    string getDireccion() { return Direccion;};
    void setRedesSociales(string a) { RedesSociales=a;};
    string getRedesSociales() { return RedesSociales;};
    void setVistas(int b) { vistas=b;};
    int getVistas() { return vistas;};
};

#endif
