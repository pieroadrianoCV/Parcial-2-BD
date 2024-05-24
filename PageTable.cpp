#include "./PageTable.h"

PageTable::PageTable(/* args */)
{
}

PageTable::~PageTable()
{
}

void PageTable::mostrarPageTableLRU()
{
    int numFilas = this->pageTableLRU.size();
    int numColumas = this->numColumnasEnPageTable;
    cout << "Frame id \t PageId \t DirtyBit \t Pin Count \t Last Used" << endl;
    for (int i = 0; i < numFilas; i++)
    {
        cout << i << "\t\t";
        for (int j = 0; j < numColumas; j++)
        {
            cout << this->pageTableLRU[i][j] << "\t\t";
        }
        cout << endl;
    }
}

bool PageTable::verificarExistenciaDePagina(int numPagina)
{
    cout << "----------------verificarExistenciaDePagina()--------------" << endl;
    int j = 0;
    for (int i = 0; i < this->columnaFrameIdSize; i++)
    {
        if (this->pageTableLRU[i][j] == numPagina)
        {
            cout << "PAG " + to_string(numPagina) + " SI existe" << endl;
            return true;
        }
    }
    cout << "PAG " + to_string(numPagina) + " NO existe" << endl;
    return false;
}

int PageTable::getNumFrameDeUnaPagina(int numPagina)
{
    cout << "--------------------------getNumFrameDeUnaPagina()--------------------" << endl;

    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                cout << "PAgina hallada devolviendo numero de frame: " << endl;
                return i;
            }
        }
    }
    else
    {
        cout << "No existe dicha Página para obtener el numero de fram" << endl;
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j])
            {
                cout << "PAgina si tiene valor" << endl;
            }
            else
            {
                cout << "Espacio vacio page id confirmado" << endl;
                return i;
            }
        }
    }
}

void PageTable::descontarPinCountApagina(int numPagina)
{
    cout << "-------------------descontarPinCountApagina()-----------.------" << endl;
    int numFilaElegida;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                numFilaElegida = i;
            }
        }
        int numColumnaPinCount = 2; // 0,1,2,3

        this->pageTableLRU[numFilaElegida][numColumnaPinCount] = this->pageTableLRU[numFilaElegida][numColumnaPinCount] - 1;
    }
}
void PageTable::aumentarPinCountDePagina(int numPagina)
{
    cout << "-------------------aumentarPinCountDePagina()-----------.------" << endl;
    int numFilaElegida;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                numFilaElegida = i;
            }
        }
        int numColumnaPinCount = 2; // 0,1,2,3

        this->pageTableLRU[numFilaElegida][numColumnaPinCount] = this->pageTableLRU[numFilaElegida][numColumnaPinCount] + 1;
    }
}

void PageTable::cambiarDirtyBitDePagina(int numPagina)
{
    cout << "-------------------cambiarDirtyBitDePagina()-----------.------" << endl;
    int numFilaElegida;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                numFilaElegida = i;
            }
        }
        int numColumnaDirtyBit = 1; // 0,1,2,3
        if (this->pageTableLRU[numFilaElegida][numColumnaDirtyBit] == 1)
        {
            cout << "DirtyBit 1 de pagina numero: " << numPagina << endl;
            this->pageTableLRU[numFilaElegida][numColumnaDirtyBit] = 0;
            cout << "DirtyBit cambiado a : " << this->pageTableLRU[numFilaElegida][numColumnaDirtyBit] << endl;
        }
        else
        {
            cout << "DirtyBit 0 de pagina numero: " << numPagina << endl;
            this->pageTableLRU[numFilaElegida][numColumnaDirtyBit] = 1;
            cout << "DirtyBit cambiado a : " << this->pageTableLRU[numFilaElegida][numColumnaDirtyBit] << endl;
        }
    }
}

void PageTable::renovarLastUsedDePagina(int numPagina)
{
    cout << "-------------------renovarLastUsedDePagina()-----------.------" << endl;
    int numFilaElegida;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                numFilaElegida = i;
            }
        }
        int numColumnaLastUsed = 3; // 0,1,2,3

        this->pageTableLRU[numFilaElegida][numColumnaLastUsed] = 0;
    }
}
void PageTable::aumentarLastUsedDePagina(int numPagina)
{
    cout << "-------------------aumentarLastUsedDePagina()-----------.------" << endl;
    int numFilaElegida;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        int j = 0;
        for (int i = 0; i < this->columnaFrameIdSize; i++)
        {
            if (this->pageTableLRU[i][j] == numPagina)
            {
                numFilaElegida = i;
            }
        }
        int numColumnaLastUsed = 3; // 0,1,2,3

        this->pageTableLRU[numFilaElegida][numColumnaLastUsed] = this->pageTableLRU[numFilaElegida][numColumnaLastUsed] + 1;
    }
}

void PageTable::aumentarLastUsedDeTodasLasDemasPaginas(int numFrameAignorar)
{
    cout << ".-----------------------aumentarLastUsedDeTodasLasDemasPaginas() ----------------------" << endl;
    cout << ">>> Actualizando PageTAble" << endl;
    int numIdPaginaAux;
    for (int i = 0; i < this->columnaFrameIdSize; i++)
    {
        for (int j = 0; j < this->numColumnasEnPageTable; j++)
        {
            if (i == numFrameAignorar)
            {
                continue;
            }
            else
            {
                if (j == 3)
                {
                    numIdPaginaAux = this->pageTableLRU[i][0];
                    this->aumentarLastUsedDePagina(numIdPaginaAux);
                    cout << "frame id: " << i << " - Aumento dado en LastUsed" << endl;
                    cout << "Agregando +1 a Last Used de todos los demás Pages" << endl;
                }
            }
        }
    }

    cout << "Datos de Page Table actualizado" << endl;
}

void PageTable::actualizarInfoDePageTableSolictandoNuevaPagina(int numPaginaActualizar, int numFilaFrameId)
{
    cout << ".-----------------------actualizarInfoDePageTableSolictandoNuevaPagina() ----------------------" << endl;
    cout << ">>> Actualizando PageTAble" << endl;
    for (int i = 0; i < this->numColumnasEnPageTable; i++)
    {
        if (i == 0)
        {
            this->pageTableLRU[numFilaFrameId][i] = numPaginaActualizar;
            cout << "frame id: " << numFilaFrameId << " - Page id establecida: " << numPaginaActualizar << endl;
        }
        else if (i == 1)
        {
            // Dirty bit:
            if (this->pageTableLRU[numFilaFrameId][i] == 1)
            {
                cout << "frame id: " << numFilaFrameId << " - No se cambió el DirtyBit=1" << endl;
            }
            else
            {
                this->pageTableLRU[numFilaFrameId][i] = 0;
                cout << "frame id: " << numFilaFrameId << " - DirtyBit=0" << endl;
            }
        }
        else if (i == 2)
        {
            this->aumentarPinCountDePagina(numPaginaActualizar);
            cout << "frame id: " << numFilaFrameId << " - Pin Count establecida: " << numPaginaActualizar << endl;
        }
        else if (i == 3)
        {
            this->renovarLastUsedDePagina(numPaginaActualizar);
            cout << "frame id: " << numFilaFrameId << " - Aumento dado en LastUsed" << endl;
            cout << "Agregando +1 a Last Used de todos los demás Pages" << endl;
            int numFrameAignorar = this->getNumFrameDeUnaPagina(numPaginaActualizar);
            this->aumentarLastUsedDeTodasLasDemasPaginas(numFrameAignorar);
        }
    }
    cout << "Datos de Page Table actualizado" << endl;
}

void PageTable::aplicarLRU(int numPagina)
{
}

void PageTable::analizarPageTableParaAgregarPagina(int numPagina)
{
    cout << "---------------------analizarPageTableParaAgregarPagina()----------------" << endl;
    if (this->verificarExistenciaDePagina(numPagina) == true)
    {
        cout << "Pagina ya encontrada" << endl;
        int numFrame = this->getNumFrameDeUnaPagina(numPagina);
        this->actualizarInfoDePageTableSolictandoNuevaPagina(numPagina, numFrame);
    }
    else
    {
        cout << "Pagina NO ESTA EN PAGE TABLE" << endl;
        if (this->verificarFrameLlenos()==true)
        {
            aplicarLRU();
        }
        else
        {
            int numFrame = this->getNumFrameDeUnaPagina(numPagina);
            this->actualizarInfoDePageTableSolictandoNuevaPagina(numPagina, numFrame);
        }

    }
}

bool PageTable::verificarFrameLlenos()
{
    int acumulador=0;
    int j = 0;
    for (int i = 0; i < this->columnaFrameIdSize; i++)
    {
        if (this->pageTableLRU[i][j])
        {
            continue;
        }
        else
        {
            acumulador++;
        }
        
    }
    if (acumulador!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
    
}