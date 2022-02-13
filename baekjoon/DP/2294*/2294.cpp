#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000000

int cost[101];
int dp[10001];
int n, k;

void coin()
{
    for (int i = 1; i <= k; i++)
    {
        dp[i] = MAX;
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = cost[i]; j <= k; j++)
        {
            dp[j] = min(dp[j - cost[i]] + 1, dp[j]); //최솟값 갱신, 나머지는 모두 최댓값+1 로 초기화 되어있고, dp[0]이 0이기 때문에 계속 갱신가능
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    coin();

    if (dp[k] == MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[k] << endl;
    }

    return 0;
}