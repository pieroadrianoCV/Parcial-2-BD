#include "./BufferManager.h"
BufferManager::BufferManager(/* args */)
{
}

BufferManager::~BufferManager(){}

void BufferManager::crearBufferPool(int numFrames)
{
    this->bufferPool.vectorFramesBufferPool.resize(numFrames);
}