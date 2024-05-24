#include "./BufferPool.h"

BufferPool::BufferPool(/* args */) {}

BufferPool::~BufferPool() {};

void BufferPool::agregarNuevaPaginaBufferPool(int numFrame, int numPagina)
{
    cout<<"-----------------agregarNuevaPaginaBufferPool() -----------------"<<endl;
    // bool vectorVacio=false;
    // int numeroDeFrame;
    // for (int i = 0; i < this->vectorFramesBufferPool.size(); i++)
    // {
    //     if (this->vectorFramesBufferPool[i].paginaEnFrame.verificarPaginaVacia()==true)
    //     {
    //         vectorVacio=true;
    //         numeroDeFrame=i;
    //     }
    //     else
    //     {
    //         continue;
    //     }
        
    // }

    // if (vectorVacio==false)
    // {
    //     cout<<"Vector lleno, extrayendo...."<<endl;
    //     /* code */
    // }
    // else
    // {
    //     this->vectorFramesBufferPool[numeroDeFrame].leerDatosEnPaginaDeFrame(numPagina);
    // }


    this->vectorFramesBufferPool[numFrame].leerDatosEnPaginaDeFrame(numPagina);


}

void BufferPool::mostrarFramePagina(int numPagina)
{
    cout<<"-------------------------mostrarFramePagina()--------------------------"<<endl;
    // bool vectorVacio=false;
    // int numeroDeFrame;
    // for (int i = 0; i < this->vectorFramesBufferPool.size(); i++)
    // {
    //     if (this->vectorFramesBufferPool[i].paginaEnFrame.verificarPaginaVacia()==true)
    //     {
    //         vectorVacio=true;
    //         numeroDeFrame=i;
    //     }
    //     else
    //     {
    //         if (/* condition */)
    //         {
    //             /* code */
    //         }
            
    //         continue;
    //     }
        
    // }
    this->vectorFramesBufferPool[numPagina-1].paginaEnFrame.mostrarContenidoDePagina();
}