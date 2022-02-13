#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001];

//n-2 번에서 두개짜리를 더하고, n-1 번에서 한개짜리를 더함
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;

    return 0;
}