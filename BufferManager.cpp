#include "./BufferManager.h"
BufferManager::BufferManager(){}

BufferManager::~BufferManager(){}

void BufferManager::crearBufferPoolSegunNumFrames(int numFrames)
{
    this->bufferPool.vectorFramesBufferPool.resize(numFrames);

    this->pageTable.columnaFrameIdSize = numFrames;
    this->pageTable.columnPageIdSize = 0;
    this->pageTable.columnaDirtyIdSize = 0;
    this->pageTable.columnaPinCountSize = 0;
    this->pageTable.columnaLastUsedSize = 0;
}

void BufferManager::establecerLimiteDeFrames(int pesoBytesBLoque)
{
    this->bufferPool.limiteDeCadaFrame = pesoBytesBLoque;

    for (int i = 0; i < this->bufferPool.vectorFramesBufferPool.size(); i++)
    {
        this->bufferPool.vectorFramesBufferPool[i].limiteBytesCapacidad = pesoBytesBLoque;
    }
    
}

void BufferManager::obtenerUnaPagina(int numPagina)
{
    Pagina paginaAux;
    paginaAux.recogerRegistros(numPagina);
    
    cout << "Enviado de Pagina a Frame" << endl;
    if (this->pageTable.columnPageIdSize == 0)
    {
        // ingresa dato a page table (id page, dirty y lo demás)
        
        // ingresa a un frame(frame id) del buffer pool
    }

}
    