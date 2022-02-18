#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int dp[1001][1001];
//dp[i][j]는 , s1에서 i까지의 문자, s2에서 j까지의 문자로 이루어진 문자열 중 LCS의 길이를 담고 있음
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    //i,j번째 문자가 같다면, i-1, j-1의 LCS +1을 해주고, 다르다면 각각 1씩을 뺀 LCS의 크기중 큰 것을 선택한다.
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1]) //s1, s2의 idx는 0부터이므로 1을 빼주는 것이 i,j에 해당하는 문자임
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[s1.length()][s2.length()];

    return 0;
}