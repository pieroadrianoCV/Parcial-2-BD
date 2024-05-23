#include "./Pagina.h"
Pagina::Pagina(/* args */){}

Pagina::~Pagina(){}

void Pagina::recogerRegistros(int numPagina)
{
    string numPaginaString = to_string(numPagina);
    string nameBloque = "Bloque";
    string rutaCompleta = "./Bloques/" + nameBloque+numPaginaString+".txt";
    ifstream fileReadBloques(rutaCompleta);
    if (!fileReadBloques.is_open())
    {
        cout << "Error t5656: no se pudo abrir "+ rutaCompleta << endl;
    }
    else
    {
        cout << "EXITO t5656: SI se pudo abrir" + rutaCompleta << endl;
        string lineaDeRegistroAux;

        //mientras haya lineas
        this->vectorRegistrosEnPagina.clear();
        while (getline(fileReadBloques,lineaDeRegistroAux))
        {
            this->vectorRegistrosEnPagina.push_back(lineaDeRegistroAux);
        }
        cout<<"Recogida de datos terminado"<<endl;
        
    }
    
}