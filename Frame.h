#ifndef FRAME_H
#define FRAME_H
#include "./Pagina.cpp"

class Frame 
{
public:
    Pagina paginaEnFrame;
    int limiteBytesCapacidad;
public:
    Frame();
    ~Frame();
};



#endif