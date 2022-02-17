#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define NUM 10007
typedef long long ll;
ll dp[10][1001];

//dp[i][j]는, j자리의 오름수중 마지막 자릿수가 i인 수
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++)
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % NUM;

    int res = 0;
    for (int i = 0; i <= 9; i++)
        res = (res + dp[i][n]) % NUM;

    cout << res % NUM;

    return 0;
}