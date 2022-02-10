#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//1,2,3,4 사분면 중 어디 존재하는지를 찾고, res에 해당하는 사분면에 도달하기까지의 값을 더하고 해당하는 변의 길이를 조정한 다음 다시 사분면 탐색을 반복
int z(int len, int row, int col, int res)
{
    if (len == 1)
        return res;

    if (row < len / 2 && col < len / 2) //1사분면
    {
        res += 0;
        return z(len / 2, row, col, res);
    }
    if (row < len / 2 && col >= len / 2) //2사분면
    {
        res += (len * len / 4);
        return z(len / 2, row, col - (len / 2), res);
    }
    if (row >= len / 2 && col < len / 2) //3사분면
    {
        res += 2 * (len * len / 4);
        return z(len / 2, row - (len / 2), col, res);
    }
    if (row >= len / 2 && col >= len / 2) //4사분면
    {
        res += 3 * (len * len / 4);
        return z(len / 2, row - (len / 2), col - (len / 2), res);
    }
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;
    int len = (int)pow(2, N);
    int res;
    res = z(len, r, c, 0);

    cout << res << endl;

    return 0;
}