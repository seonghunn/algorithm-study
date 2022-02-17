#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[101][100001];

//dp[i][j]는 무게 j의 가방을 i까지의 물품을 사용해서 담았을 때의 가치의 최댓값
//0-1 knapsack problem
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= k; j++)
        {
            if (j - a >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a] + b);
            else
                dp[i][j] = dp[i - 1][j]; //둘 중 비교가 아니라면, 그대로 값을 내려받음
        }
    }

    cout << dp[n][k];

    return 0;
}