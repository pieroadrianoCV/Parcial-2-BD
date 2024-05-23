#include "./BufferManager.h"
#include <fstream>
using namespace std;

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
    cout<<".-----------------------obtenerUnaPagina() ----------------------"<<endl;
    cout << "----------- Revisando Page Table para insertado de Pagina" << endl;
    if (this->pageTable.columnPageIdSize == 0)
    {
        cout<<"No tiene  ninguna página insertada"<<endl;
        cout<<"---- Insertando Datos de pagina a ser insertada en Page table..."<<endl;
        for (int i = 0; i < this->pageTable.numColumnasEnPageTable; i++)
        {
            if (i==0)
            {
                this->pageTable.pageTableLRU[0][i]=numPagina;
                cout<<"frame id:0 - Page id establecida: "<<numPagina<<endl;
            }
            else if (i==2)
            {
                this->pageTable.pageTableLRU[0][i]=1;
                cout<<"frame id:0 - Pin Count establecida: "<<numPagina<<endl;
            }
            
            else
            {
                this->pageTable.pageTableLRU[0][i]=0;
                cout<<"frame id:0 - Dirty Bit establecida: "<<0<<endl;
                cout<<"frame id:0 - Last used establecida: "<<0<<endl;
            }
            
            
        }
        cout<<"Datos de Page Table actualizado"<<endl;

        cout<<"$$ Primera Pagina, Segun Page Table insertando Pagina A Frame 0"<<endl;
        this->bufferPool.vectorFramesBufferPool[0].paginaEnFrame.recogerRegistros(numPagina);
        
        cout<<"Mostrando Page Table..."<<endl;
        this->pageTable.mostrarPageTableLRU();
        //darle un page id
        //mandarlo a un frame
        //guardar cambios en page table
        // ingresa dato a page table (id page, dirty y lo demás)
        // ingresa a un frame(frame id) del buffer pool
    }
    else
    {
        cout<<"SI tiene páginas insertada"<<endl;
    }
    
}
    