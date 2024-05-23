#include "./Frame.h"

Frame::Frame(/* args */)
{
}

Frame::~Frame()
{
}

void Frame::leerDatosEnPaginaDeFrame(int numPagina)
{
    this->paginaEnFrame.recogerRegistros(numPagina);
}
