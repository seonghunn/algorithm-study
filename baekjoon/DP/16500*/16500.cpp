#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string str[101];
bool dp[101];

//s 문자열에서, str 내의 문자들을 시작 지점부터 같은지 찾는다. 찾는다면 그 부분 문자열의 끝에 해당하는 인덱스에 1을 넣는다
//이후 계속 이어서 끝에 1을 채워가면서 문자열을 확인하고, 맨 끝에 1이 적히면 구성 가능, 0이라면 구성 불가능이 된다.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> str[i];

    dp[0] = 1;

    //pos의 값에 따라 찾는데, dp[pos]=1 인 곳에 문자열이 존재해야 공백 없이 이어진 단어를 구성할 수 있다.
    //또한 pos 값을 뛰어넘지 않고 계속 증가시키는 이유는, software, soft 처럼 부분 문자열이 있는 경우도 예외 없이 카운트하기 위함이다.
    for (int pos = 0; pos < s.length(); pos++)
        for (int j = 1; j <= n; j++)
            if (s.find(str[j], pos) == pos && dp[pos] == 1)
                dp[pos + str[j].length()] = 1;

    cout << dp[s.length()];

    return 0;
}