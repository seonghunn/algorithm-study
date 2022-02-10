#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//입력 주의!! 띄워져서 받지 않으므로 입력 처리에 신경써야함
//입력 처리가 잘 안되어서 파이썬으로 먼저 풀었음
int arr[65][65];
int N;
void quadTree(int start_x, int start_y, int size)
{
    if (size == 1)
    {
        cout << arr[start_x][start_y];
        return;
    }
    bool isCompressable = true;
    for (int i = start_x; i < start_x + size; i++)
    {
        for (int j = start_y; j < start_y + size; j++)
        {
            if (arr[i][j] != arr[start_x][start_y])
            {
                isCompressable = false;
                goto EXIT;
            }
        }
    }
EXIT:
    if (isCompressable)
    {
        cout << arr[start_x][start_y];
        return;
    }
    else
    {
        cout << "(";
        for (int i = start_x; i < start_x + size; i += (size / 2))
        {
            for (int j = start_y; j < start_y + size; j += (size / 2))
            {
                quadTree(i, j, size / 2);
            }
        }
        cout << ")";
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); j++)
        {
            arr[i][j] = s[j - 1] - '0';
        }
    }
    quadTree(1, 1, N);
    return 0;
}