#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001] = {
    0,
}; //dp[i]는 i를 1로 만들게 하기 위한 최소 연산값

//탑다운 방식 구현
int makeOnetdn(int N)
{
    if (N == 1)
        return 0;
    if (dp[N] != 0) //이미 계산한 수는 그 계산한 수를 돌려준다 (재귀로 검증하며 이전 값을 찾아야 할 때)
        return dp[N];

    int res = makeOnetdn(N - 1) + 1; //기본 result
    if (N % 3 == 0)
        res = min(res, makeOnetdn(N / 3) + 1); //-1까지 한 수에 +1한 것과 /3 한 수에 +1한것 중 작은 걸 res에
    if (N % 2 == 0)
        res = min(res, makeOnetdn(N / 2) + 1); //2,3 동시에 나누어지는 수도 위에서 최솟값을 한번 갱신했기 때문에 여기서 비교하면 진짜 최소를 찾을 수 있음

    dp[N] = res;
    return res;
}

//bottom-up 방식 구현
void makeOnebtu(int N)
{
    for (int i = 2; i <= N; i++)
    {
        int res = dp[i - 1] + 1;
        if (i % 3 == 0)
            res = min(dp[i / 3] + 1, res);
        if (i % 2 == 0)
            res = min(dp[i / 2] + 1, res);
        // 2,3 둘다 나눠지는 것도 res를 계속 갱신하기 때문에 둘다 필터링 되는 것을 알 수 있음
        dp[i] = res;
    }
    //셋 중 최솟값을 더해주는 코드를 구현
}

int main()
{
    int N;
    cin >> N;
    //makeOnebtu(N);
    //cout << dp[N] << endl;
    cout << makeOnetdn(N) << endl;
    return 0;
}