#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NUM 10007

int dp[1001][1001];
//dp 배열은 파스칼의 삼각형을 눕혀놓은 것, 3C2 의 경우 좌표 (1,2)에 대응 (nCk=>(n-k,k))
//파스칼의 삼각형에서 위의 두개를 더하면 아래의 값이 나오는거를 2차원 배열로 대응시켜서 풀이
int main()
{
    int n, k;
    cin >> n >> k;

    //초기화
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n - k; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % NUM;

    cout << dp[n - k][k] % NUM;

    return 0;
}