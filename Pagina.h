#ifndef PAGINA_H
#define PAGINA_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pagina
{
public:
    vector<string> vectorRegistrosEnPagina;
public:
    Pagina(/* args */);
    ~Pagina();
    void recogerRegistros(int numPagina);
    void mostrarContenidoDePagina();
    bool verificarPaginaVacia();
    void leerOescribirEnPagina();
};

#endif