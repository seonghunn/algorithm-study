#include <iostream>
#include <string>
#include "Deque.cpp"
#include "Node.cpp"

int main()
{
    Deque<int> dq;
    dq.insertFront(3);
    dq.insertFront(8);
    dq.insertFront(5);
    dq.insertFront(9);
    dq.insertFront(1);
    dq.insertBack(2);
    dq.insertBack(7);
    dq.printFront();
    //1 9 5 8 3 2 7
    cout << dq.popBack() << endl;
    //7
    cout << dq.popFront() << endl;
    //1
    dq.printBack();
    //2 3 8 5 9

    Deque<string> strdq;
    strdq.insertFront("testing");
    strdq.insertFront("test1");
    strdq.insertBack("test");
    strdq.printFront();
    //test1 testing test
    cout << strdq.popBack() << endl;
    //test
    strdq.printBack();
    //testing test1
    return 0;
}