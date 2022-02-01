#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int N, K;
int arr[100000];
int sub[9999];
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++)
    {
        sub[i] = arr[i + 1] - arr[i];
    }
    sort(sub, sub + N - 1, greater<>()); //오름차순 정렬

    int sum = 0;
    for (int i = K - 1; i < N - 1; i++)
    {
        sum += sub[i]; //차이 중 가장 많은 것 K-1개를 제외하고 나머지를 더함 (칸막이를 친다고 생각하기 때문에 K-1개를 사용해야 묶음이 나옴)
    }

    cout << sum << endl;

    return 0;
}