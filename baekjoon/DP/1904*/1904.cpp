#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dp[1000001];

//2개짜리를 붙이려면 n-2 에 해당하는 개수에 붙이고, 1개짜리를 붙이려면 n-1에 해당하는 개수에 붙여야하므로 피보나치 수열임
int main()
{
    int N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746; //수가 매우 커지므로 미리 나머지를 넣는다
    }

    cout << dp[N] << endl;

    return 0;
}