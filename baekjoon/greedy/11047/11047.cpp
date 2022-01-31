#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    int cnt = 0;
    int arr[10];

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int idx = N - 1;

    while (idx >= 0)
    {
        if (K / arr[idx] > 0) //가장 큰 값을 가진 동전부터 나누면서 K를 표현할 수 있는지 확인
        {
            cnt += K / arr[idx];
            K %= arr[idx];
        }
        idx--;
    }

    cout << cnt << endl;

    return 0;
}