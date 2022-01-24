#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[9];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int index[2]; //안 되는 인덱스
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] + arr[j] == sum - 100)
            {
                index[0] = i;
                index[1] = j;
                goto EXIT;
            }
        }
    }

EXIT:
    int res[9];
    for (int i = 0; i < 10; i++)
    {
        if (i != index[0] && i != index[1])
        {
            res[i] = arr[i];
        }
        else
        {
            res[i] = 0;
        }
    }

    sort(res, res + 9);

    for (int i = 2; i < 9; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}