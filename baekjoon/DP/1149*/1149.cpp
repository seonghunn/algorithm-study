#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[3][1001];

//n번째 색을 r,g,b로 칠했을 때의 최솟값은, dp배열의 각각 다른색으로 칠했을 때+현재 색으로 칠했을 때의 값이고, dp를 계속 갱신하기 때문에
//이미 dp 배열에는 최솟값이 들어있음. 최종적으로 마지막에 r,g,b로 칠했을 때의 최솟값을 출력하면 됨.
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + a;
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + b;
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + c;
    }
    cout << min(dp[0][n], min(dp[1][n], dp[2][n]));

    return 0;
}