#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001];
int arr[10001];
//dp배열은 i개의 카드팩을 샀을 때 지불하는 최대 가격
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            //i-j개을 만드는 최댓값에 j개를 만드는 가격을 더한 것 중 최댓값을 갱신
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, dp[i]);
    }

    cout << mx;

    return 0;
}