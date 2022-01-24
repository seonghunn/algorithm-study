#include <iostream>
using namespace std;

int sum(int input)
{
    int tmp = input;
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = 10;
    }

    int j = 0;
    while (input / 10 != 0)
    {
        arr[j] = input % 10;
        input = input / 10;
        j++;
    }
    arr[j] = input;
    int sum = 0;
    for (int i = 0; i <= j; i++)
    {
        sum += arr[i];
    }

    return sum + tmp;
}

int main()
{
    int num;
    cin >> num;
    int i;
    int res = 0;
    for (i = 0; i <= num; i++)
    {
        if (sum(i) == num)
        {
            res = i;
            break;
        }
    }

    cout << res << endl;
    return 0;
}