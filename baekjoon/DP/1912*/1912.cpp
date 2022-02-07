#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000];
int N;

//전형적인 dp 유형
//연속합과 새로운원소 중 큰 것을 골라 dp 배열에 넣으며 maximum을 갱신해 나간다. 새로운원소를 고른다는 것은 그 자리에서 연속합이 끊겨야 최댓값이 나온다는 뜻이다.
//혼자인게 더 큰가 vs 합해야 더 큰가 중 하나를 선택하는 것
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    int maximum = dp[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        if (maximum < dp[i]) //dp 배열(연속합과 개별 원소 중 큰 것이 입력된 배열)에서 가장 큰 값을 갱신한다.
            maximum = dp[i];
    }

    cout << maximum << "\n";

    return 0;
}