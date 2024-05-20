#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <vector>
#include <iostream>

#include "./Frame.cpp"
using namespace std;

class BufferPool 
{
    public:
        int pesoBytesBloque;
        int numFrames;
        vector<Frame> vectorFramesBufferPool;
    public:
        BufferPool(/* args */);
        ~BufferPool();
};

#endif