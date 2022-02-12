#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        //배열 매번 초기화
        int arr[2][100001] =
            {{
                 0,
             },
             {
                 0,
             }};
        int dp[2][100001] =
            {{
                 0,
             },
             {
                 0,
             }};
        int N;
        cin >> N;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> arr[i][j];
            }
        }
        //초기값 설정
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        //bottom-up 방식 구현, 0, 즉 1번째 줄의 i번째 스티커까지의 최댓값은 그 왼쪽의 세개의 ㄱ 또는 ㄴ 모양까지의 최댓값에 그 값을 더한 것이므로 계속 갱신
        //이를 2번째 줄에 뗄 스티커에 대해서도 수행하고, 마지막에 그 두개 중 최댓값을 출력함
        for (int i = 1; i <= N; i++)
        {
            //세 칸까지의 dp 배열에 현재 스티커를 뗐을 떄의 점수를 더한 것의 최댓값이 최댓값을 갱신하는 것
            dp[0][i + 1] = max(dp[0][i - 1], max(dp[1][i], dp[1][i - 1])) + arr[0][i + 1];
            dp[1][i + 1] = max(dp[1][i - 1], max(dp[0][i], dp[0][i - 1])) + arr[1][i + 1];
        }
        cout << max(dp[0][N], dp[1][N]) << endl;
    }

    return 0;
}