#ifndef BUFFERPOOL_H
#define BUFFERPOOL_H

#include <vector>
#include <iostream>

#include "./Frame.cpp"
using namespace std;

class BufferPool 
{
    public:
        //atributos
        int limiteDeCadaFrame;
        vector<Frame> vectorFramesBufferPool;
    public:
        //Funciones
        BufferPool(/* args */);
        ~BufferPool();
};

#endif