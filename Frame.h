#ifndef FRAME_H
#define FRAME_H
#include "./Pagina.cpp"

class Frame 
{
public:
    Pagina paginaEnFrame;
    int capacidadBytesDeFrame;
public:
    Frame();
    ~Frame();

    void leerDatosEnPaginaDeFrame(int numPagina);
};



#endif