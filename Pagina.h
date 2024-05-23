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
    vector<string> vectoregistrosEnPagina;
public:
    Pagina(/* args */);
    ~Pagina();
    void recogerRegistros(int numPagina);
};

#endif