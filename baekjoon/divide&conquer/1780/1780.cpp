#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2188][2188];
int N;
int cnt1, cnt2, cnt3;

void check(int x_start, int y_start, int size)
{
    if (size == 0)
        return;
    bool isSameMatrix = true;
    //시작점에서 size 만큼 전체를 탐색
    for (int i = x_start; i < x_start + size; i++)
    {
        for (int j = y_start; j < y_start + size; j++)
        {
            if (arr[i][j] != arr[x_start][y_start])
            {
                isSameMatrix = false;
                goto EXIT;
            }
        }
    }
EXIT:
    if (isSameMatrix)
    {
        if (arr[x_start][y_start] == -1)
        {
            cnt1++;
        }
        else if (arr[x_start][y_start] == 0)
        {
            cnt2++;
        }
        else if (arr[x_start][y_start] == 1)
        {
            cnt3++;
        }
    }
    //만약 하나라도 다른게 있을 시, 9등분하여 재진행
    else
    {
        for (int i = x_start; i < x_start + size; i += (size / 3))
        {
            for (int j = y_start; j < y_start + size; j += (size / 3))
            {
                check(i, j, size / 3);
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    check(1, 1, N);
    cout << cnt1 << "\n";
    cout << cnt2 << "\n";
    cout << cnt3 << "\n";
    return 0;
}