#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr[1000001];
    for (int i = 0; i < 1000001; i++)
    {
        arr[i] = 1;
    }

    int M, N;
    cin >> M >> N;
    arr[1] = false;

    for (int i = 2; i <= 1000; i++)
    {
        if (arr[i])
        {
            for (int j = 2 * i; j <= 1000000; j += i) //int j=i*i
            {
                arr[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++)
    {

        if (arr[i])
            cout << i << "\n"; //시간 초과 : \n 사용하기
    }

    return 0;
}