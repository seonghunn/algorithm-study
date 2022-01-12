#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    int max = 0;
    int maxidx;

    cin >> arr[0] >> arr[1] >> arr[2];

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            max = arr[0];
            maxidx = 0;
        }

        if (max < arr[i])
        {
            max = arr[i];
            maxidx = i;
        }
    }

    int tmp;

    for (int i = 0; i < 3; i++)
    {
        if (i != maxidx)
        {
            tmp += arr[i];
        }
    }

    if (tmp == max)
        cout << "right" << endl;
    else
        cout << "non right" << endl;

    return 0;
}