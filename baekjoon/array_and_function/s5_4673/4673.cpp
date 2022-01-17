#include <iostream>
using namespace std;

int selfNum(int num)
{
    if (num < 10)
    {
        return num + num;
    }
    else if (num >= 10 && num < 100)
    {
        return num + num / 10 + num % 10;
    }
    else if (num >= 100 && num < 1000)
    {
        return num + num / 100 + (num % 100) / 10 + num % 10;
    }
    else if (num >= 1000 && num < 10000)
    {
        return num + num / 1000 + (num % 1000) / 100 + (num % 100) / 10 + num % 10;
    }
    else if (num == 10000)
    {
        return num + num / 10000 + (num % 10000) / 1000 + (num % 1000) / 100 + (num % 100) / 10 + num % 10;
    }
}

int main()
{

    int arr[10000];
    for (int i = 0; i < 10000; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 10000; i++)
    {
        int res = selfNum(i);
        if (res < 10000)
        {
            arr[res] = 0;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << endl;
    }

    return 0;
}