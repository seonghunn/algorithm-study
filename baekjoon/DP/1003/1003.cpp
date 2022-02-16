#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> dp[41];

//1을 사용한 횟수와 0을 사용한 횟수를 dp에 저장하고, 이전에 계산한 값은 다시 계산하지 않는다.
int main()
{
    int n;
    cin >> n;
    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;
    for (int i = 2; i <= 40; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << dp[num].first << " " << dp[num].second << endl;
    }

    return 0;
}