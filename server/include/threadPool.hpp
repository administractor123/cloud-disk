#pragma once

class threadPool
{
private:
    int exitPipe[2];
    
public:
    threadPool();
    ~threadPool();
};

threadPool::threadPool()
{
}

threadPool::~threadPool()
{
}
