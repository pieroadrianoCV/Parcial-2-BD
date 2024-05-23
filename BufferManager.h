#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "./BufferPool.cpp"
#include "./PageTable.cpp"

#include <vector>

using namespace std;

class BufferManager
{
    public:
        //Atributos
        BufferPool bufferPool;
        PageTable pageTable;
    public:
        BufferManager();
        ~BufferManager();
        void crearBufferPoolSegunNumFrames(int numFrames);
        void establecerLimiteDeFrames(int pesoBytesBLoque);
        void obtenerUnaPagina(int numPagina);

};

#endif