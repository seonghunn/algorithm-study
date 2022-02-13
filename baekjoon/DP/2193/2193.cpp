#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dp[91];

//01 로 끝나면 n-2 값에 더하고, 0으로 끝나면 n-1에 더한다 => 피보나치 수열
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}