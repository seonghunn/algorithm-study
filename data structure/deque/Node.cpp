#include "Node.h"
#include <iostream>
#include <string>

//constructor
template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

//destructure
template <typename T>
Node<T>::~Node() {}

//getter
template <typename T>
T Node<T>::getData()
{
    return data;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
Node<T> *Node<T>::getPrev()
{
    return prev;
}

//setter
template <typename T>
void Node<T>::setNext(Node *node)
{
    this->next = node;
}

template <typename T>
void Node<T>::setPrev(Node *node)
{
    this->prev = node;
}