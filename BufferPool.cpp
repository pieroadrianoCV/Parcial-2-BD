#include "./BufferPool.h"

BufferPool::BufferPool(/* args */) {}

BufferPool::~BufferPool() {};

void BufferPool::agregarNuevaPaginaBufferPool(int numFrame, int numPagina)
{
    this->vectorFramesBufferPool[numFrame].leerDatosEnPaginaDeFrame(numPagina);
}


void BufferPool::mostrarFramePagina(int numPagina)
{
    this->vectorFramesBufferPool[numPagina-1].paginaEnFrame.mostrarContenidoDePagina();
}