#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001];

//n-1에서는 하나만 추가하면 됨, n-2에서는 2X2 모양 조각이 되는 2가지를 곱해서 (경우의 수가 곱해져서 세어짐) 더하면 됨
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
    }

    cout << dp[n] << endl;
    return 0;
}