#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "./BufferPool.cpp"
using namespace std;

class BufferManager
{
    public:
        BufferPool bufferPool;
        BufferManager(/* args */);
        ~BufferManager();
        void crearBufferPool(int numFrames);

};

#endif