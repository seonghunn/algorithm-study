#include <iostream>
#include <algorithm>
#include <vector>
#define NUM 1000000000
using namespace std;

long long dp[10][101];
//dp[i][j]는 j자리 계단수 중 i라는 끝 자리를 가지는 계단수
int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        dp[i][1] = 1;
    }

    //끝자리가 1이라면 그 다음에는 숫자가 0이 되어야, 9일때는 다음 숫자가 8이어야 되고
    //나머지 숫자는 그 다음 계단숫자가 될 수 있는 숫자가 2개씩 있다.
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            //오버플로우가 나기 때문에 계산할 때 NUM의 나머지를 더해주며 연산해야함
            if (j == 0)
                dp[j + 1][i] = (dp[j + 1][i] + dp[j][i - 1]) % NUM;
            else if (j == 9)
                dp[j - 1][i] = (dp[j - 1][i] + dp[j][i - 1]) % NUM;
            else
            {
                dp[j + 1][i] = (dp[j + 1][i] + dp[j][i - 1]) % NUM;
                dp[j - 1][i] = (dp[j - 1][i] + dp[j][i - 1]) % NUM;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans = (ans + (dp[i][N])) % NUM;
    }
    cout << ans % NUM;
    return 0;
}