#include "./Pagina.h"
Pagina::Pagina(/* args */){}

Pagina::~Pagina(){}

void Pagina::recogerRegistros(int numPagina)
{
    string numPaginaString = to_string(numPagina);
    string nameBloque = "Bloque";
    string rutaCompleta = "./Bloques/" + nameBloque+numPaginaString;
    ifstream fileReadBloques(rutaCompleta);
    if (!fileReadBloques.is_open())
    {
        cout << "Error t5656: no se pudo abrir "+ rutaCompleta << endl;
    }
    else
    {
        cout << "EXITO ROTUNDO EN PROCESO DE ADMISION" + rutaCompleta << endl;
        string lineaDeRegistroAux;

        //mientras haya lineas
        int i = 0;
        while (getline(fileReadBloques,lineaDeRegistroAux))
        {
            this->vectorRegistrosEnPagina[i] = lineaDeRegistroAux;
            i++;
        }
        cout<<"Recogida de datos terminado"<<endl;
        
    }
    
}