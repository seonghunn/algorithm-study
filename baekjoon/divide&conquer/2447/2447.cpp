#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char arr[6562][6562];
int N;
//가운데 부분 삭제하는 함수
void deleteStar(int row, int col, int size)
{
    if (size == 1)
        return;
    for (int i = row + (size / 3); i < row + 2 * (size / 3); i++)
    {
        for (int j = col + (size / 3); j < col + 2 * (size / 3); j++)
        {
            arr[i][j] = ' ';
        }
    }
    for (int i = row; i < row + size; i += (size / 3))
    {
        for (int j = col; j < col + size; j += (size / 3))
        {
            if (i == row + (size / 3) && j == col + (size / 3)) //가운데는 delete 이미 수행됨
                continue;
            deleteStar(i, j, size / 3);
        }
    }
}

int main()
{
    cin >> N;
    fill(arr[1], arr[N + 1], '*'); //*로 다 채우고
    deleteStar(1, 1, N);           //해당하는 부분 지움
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}