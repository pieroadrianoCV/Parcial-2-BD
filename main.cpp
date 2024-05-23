#include <iostream>
#include "./BufferManager.cpp"

using namespace std;

int main()
{
    cout << "Bienvenido a implementación de BUFFER" << endl;
    int pesoBytesBLoque;
    cout << "Ingrese el peso de su bloque de Disco: " << endl;
    cin >> pesoBytesBLoque;
    int numFrames;
    cout << "Ingrese la cantidad de Frames a tener en el Buffer Pool: " << endl;
    cin >> numFrames;

    /*Creación de buffer pool*/
    BufferManager bufferManagerPrincipal;
    bufferManagerPrincipal.crearBufferPoolSegunNumFrames(numFrames);
    bufferManagerPrincipal.establecerLimiteDeFrames(pesoBytesBLoque);

    //solicitar 1 página
    int numPagina;
    cout << "Ingrese el numero de pagina que desea OBTENER (Modo Prueba 1 - 6): "<<endl;
    cin >> numPagina;
    
    bufferManagerPrincipal.obtenerUnaPagina(numPagina);


    return 0;
}