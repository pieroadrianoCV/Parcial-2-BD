#ifndef PAGINA_H
#define PAGINA_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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
};

#endif