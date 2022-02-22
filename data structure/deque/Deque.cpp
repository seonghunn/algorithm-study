#include "Deque.h"
#include <iostream>
using namespace std;

//constructor
template <typename T>
Deque<T>::Deque()
{
    this->first = NULL;
    this->end = NULL;
}

//destructor
template <typename T>
Deque<T>::~Deque()
{
    Node<T> *delNode = first;
    while (delNode != NULL)
    {
        first = delNode->getNext();
        delete delNode;
        delNode = first;
    }
}

template <typename T>
int Deque<T>::getsize()
{
    return size;
}

template <typename T>
void Deque<T>::insertFront(T data)
{
    Node<T> *newNode = new Node(data);
    if (this->getsize() == 0)
    {
        first = newNode;
        end = newNode;
        size++;
        return;
    }

    newNode->setNext(first);
    first->setPrev(newNode);
    first = newNode;
    size++;
    return;
}

template <typename T>
void Deque<T>::insertBack(T data)
{
    Node<T> *newNode = new Node(data);
    if (this->getsize() == 0)
    {
        first = newNode;
        end = newNode;
        size++;
        return;
    }

    end->setNext(newNode);
    newNode->setPrev(end);
    end = newNode;
    size++;
    return;
}

template <typename T>
T Deque<T>::popFront()
{
    Node<T> *tmp = first;
    T tmpdata = tmp->getData();
    first = tmp->getNext();
    first->setPrev(NULL);
    delete tmp;
    size--;
    return tmpdata;
}

template <typename T>
T Deque<T>::popBack()
{
    Node<T> *tmp = end;
    T tmpdata = tmp->getData();
    end = end->getPrev();
    end->setNext(NULL);
    delete tmp;
    size--;
    return tmpdata;
}

template <typename T>
void Deque<T>::printFront()
{
    Node<T> *iter = first;
    while (iter != NULL)
    {
        cout << iter->getData() << " ";
        iter = iter->getNext();
    }
    cout << "\n";
}

template <typename T>
void Deque<T>::printBack()
{
    Node<T> *iter = end;
    while (iter != NULL)
    {
        cout << iter->getData() << " ";
        iter = iter->getPrev();
    }
    cout << "\n";
}