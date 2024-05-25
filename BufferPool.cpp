#include "./BufferPool.h"

BufferPool::BufferPool(/* args */) {}

BufferPool::~BufferPool() {};

void BufferPool::agregarNuevaPaginaBufferPool(int numFrame, int numPagina)
{
    cout<<"-----------------agregarNuevaPaginaBufferPool() -----------------"<<endl;

    /*FALTA CORREGIR: error de insertado de pagina en vector FRAMES*/
    this->vectorFramesBufferPool[numFrame].leerDatosEnPaginaDeFrame(numPagina);


}

void BufferPool::mostrarFramePagina(int numPagina)
{
    cout<<"-------------------------mostrarFramePagina()--------------------------"<<endl;
    /*FALTA CORREGIR: error de lectura de pagina en vector FRAMES ()*/
    this->vectorFramesBufferPool[numPagina-1].paginaEnFrame.mostrarContenidoDePagina();
}