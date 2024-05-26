#include "./Pagina.h"

Pagina::Pagina(/* args */){}

Pagina::~Pagina(){}

bool isNumber(const std::string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0 && ch != '.')
            return false;
    }
    return true;
}

void Pagina::recogerRegistros(int numPagina)
{
    string numPaginaString = to_string(numPagina);
    string nameBloque = "Bloque";
    /* Por si acaso si no funciona es ../, de caso contrario ./ */
    string rutaCompleta = "../Bloques/" + nameBloque+numPaginaString + ".txt";
    cout << "Intentando abrir el archivo en: " << rutaCompleta << endl;
    ifstream fileReadBloques(rutaCompleta);

    
    if (!fileReadBloques.is_open())
    {
        cout << "Error t5656: no se pudo abrir " + rutaCompleta << endl;
    }
    else
    {
        cout << "EXITO t5656: SI se pudo abrir" + rutaCompleta << endl;
//PIERO
        string lineaDeRegistroAux;
        string valor;
        //mientras haya lineas
        this->vectorRegistrosEnPagina.clear();
        cout << "tamanio string: " << endl;
        int tamanio;
        cin >> tamanio;
        string linea_registro = " ";
        while (getline(fileReadBloques,lineaDeRegistroAux))
        {
            //this->vectorRegistrosEnPagina.push_back(lineaDeRegistroAux);
            stringstream ss(lineaDeRegistroAux);
            while (getline(ss,valor,','))
            {
                    int peso = valor.size();
                    if (isNumber(valor)) {
                        linea_registro += valor + ',';
                        continue;
                    }
                    else {
                        
                        do {
                            valor += " ";
                            peso++;
                        }
                        while (peso < tamanio);
                        linea_registro += valor + ',';
                        break;
                    }
            }
            this->vectorRegistrosEnPagina.push_back(linea_registro);
        }
        cout<<"Recogida de datos terminado"<<endl;
        
    }
    
}

void Pagina::mostrarContenidoDePagina()
{
    cout << "-------------------PAgina: mostrarContenidoDePagina()-------------------" << endl;
    for (size_t i =0 ; i < this->vectorRegistrosEnPagina.size(); i++) {
        cout << this->vectorRegistrosEnPagina[i] << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    
}


bool Pagina::verificarPaginaVacia()
{
    if (this->vectorRegistrosEnPagina.empty())
    {
        return true;
    }
    else
    {
        return false;
    }    
}

