#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>
#include <vector>

using namespace std;

class PageTable
{
public:
    string columnaFrameId = "FrameId";
    int columnaFrameIdSize;

    string columnaPageId = "PageId";
    int columnPageIdSize;

    string columnaDirttyId = "DirtyId";
    int columnaDirtyIdSize;

    string columnaPinCount = "PinCount";
    int columnaPinCountSize;

    string columnaLastUsed = "LastUsed";
    int columnaLastUsedSize;

    int numColumnasEnPageTable=4;//aparte de frameID

    vector<vector<int>> pageTableLRU;
public:
    PageTable(/* args */);
    ~PageTable();
    void mostrarPageTableLRU();
    bool verificarExistenciaDePagina(int numPagina);
    int getNumFrameDeUnaPagina(int numPagina);

    void descontarPinCountApagina(int numPagina);
    void aumentarPinCountDePagina(int numPagina);

    void cambiarDirtyBitDePagina(int numPagina);

    void descontarLastUsedDePagina(int numPagina);
    void aumentarLastUsedDePagina(int numPagina);

    void actualizarDataAlSolicitarPagina(int numPaginaActualizar, int numFilaFrameId);

    void aplicarLRU(int numPagina);

};


#endif