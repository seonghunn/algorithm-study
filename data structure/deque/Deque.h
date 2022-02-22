#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"

template <typename T>
class Deque
{
private:
    Node<T> *first;
    Node<T> *end;
    int size;

public:
    Deque();
    ~Deque();
    int getsize();
    void insertFront(T data);
    void insertBack(T data);
    T popFront();
    T popBack();
    void printFront();
    void printBack();
};

#endif