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

};


#endif