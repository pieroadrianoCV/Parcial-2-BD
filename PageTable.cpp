#include "./PageTable.h"

PageTable::PageTable(/* args */)
{
}

PageTable::~PageTable()
{
}

void PageTable::mostrarPageTableLRU()
{
    int numFilas=this->pageTableLRU.size();
    int numColumas=this->numColumnasEnPageTable;
    cout<<"Frame id \t PageId \t DirtyBit \t Pin Count \t Last Used"<<endl;
    for (int i = 0; i < numFilas; i++)
    {
        cout<<i<<"\t\t";
        for (int j = 0; j < numColumas; j++)
        {
            cout<<this->pageTableLRU[i][j]<<"\t\t";
        }
        cout<<endl;
        
    }
    
}
