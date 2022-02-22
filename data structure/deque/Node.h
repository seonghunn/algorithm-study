#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
    T data;
    Node *next;
    Node *prev;

public:
    Node(T data);
    ~Node();
    T getData();
    Node *getNext();
    Node *getPrev();
    void setNext(Node *);
    void setPrev(Node *);
};

#endif