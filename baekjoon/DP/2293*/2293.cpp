#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001];
int cost[101];
int n, k;

int main()
{
    fill(dp, dp + 10001, 0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    dp[0] = 1;
    //초기값 (1로 설정)
    //1,2,5로 예를 들면
    //2까지 써서 3을 만들 때, 1로만 만든 1 1 1에, 3-2인 1을 만든 1에 2를 더해서 1+2, 1+1+1...이런 식으로 갱신
    for (int i = 1; i <= n; i++)
    {
        for (int j = cost[i]; j <= k; j++)
        {
            dp[j] += dp[j - cost[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}