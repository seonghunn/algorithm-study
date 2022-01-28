#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char board[50][50];
    char ans1[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == j % 2)
                ans1[i][j] = 'B';
            else
                ans1[i][j] = 'W';
        }
    }

    char ans2[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == j % 2)
                ans2[i][j] = 'W';
            else
                ans2[i][j] = 'B';
        }
    } //답을 정해놓고 비교
    //답을 정해놓지 않고 원래 하던대로 오른쪽 맨 위 글자 등을 기준으로 비교하면 꼭짓점만 칠해서 될 경우에 비효율정인 cnt 가 올라가게 됨

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    int xidx = 0;
    int yidx = 0;
    int min = 9999; //최솟값을 갱신할 것이므로, 굉장히 큰 값으로 만듬

    for (int m = 0; m <= N - 8; m++) //N: 세로, M: 가로, 이동시키면서 8x8 영역 탐색
    {
        for (int n = 0; n <= M - 8; n++)
        {
            int cnt = 0;
            for (int i = m; i < m + 8; i++)
            {
                for (int j = n; j < n + 8; j++)
                {
                    if (board[i][j] != ans1[i - m][j - n])
                        cnt++;
                }
            }

            if (cnt < min)
                min = cnt;

            cnt = 0;
            for (int i = m; i < m + 8; i++)
            {
                for (int j = n; j < n + 8; j++)
                {
                    if (board[i][j] != ans2[i - m][j - n])
                        cnt++;
                }
            }

            //8X8 하나 탐색 끝
            if (cnt < min)
                min = cnt;
        }
    }

    cout << min << endl;

    return 0;
}