#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int count(char[50][50], int);

int main()
{
    int N;
    cin >> N;
    char arr[50][50]; //입력에 공백이 없으므로 char 자료형 사용

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max = 0;

    for (int i = 0; i < N; i++) //열
    {
        int tmpmax = 0;
        for (int j = 0; j < N - 1; j++) //행에서 양옆 바꾸기
        {
            swap(arr[i][j], arr[i][j + 1]); //바꿈, 양옆이 같다면 바꿔도 동일하므로, 굳이 if문을 사용할 필요가 없다
            tmpmax = count(arr, N);
            if (tmpmax > max)
            {
                max = tmpmax;
            }
            swap(arr[i][j], arr[i][j + 1]); //계산 후 원상복귀
        }
    }

    for (int j = 0; j < N; j++) //행
    {
        int tmpmax = 0;
        for (int i = 0; i < N - 1; i++)
        {
            swap(arr[i][j], arr[i + 1][j]);
            tmpmax = count(arr, N);
            if (tmpmax > max)
            {
                max = tmpmax;
            }
            swap(arr[i][j], arr[i + 1][j]); //계산 후 원상복귀
        }
    }
    cout << max << endl;

    return 0;
}

int count(char arr[50][50], int N)
{
    int max = 0;
    for (int m = 0; m < N; m++)
    {
        char s = arr[m][0];
        int cnt = 0;
        for (int n = 0; n < N; n++)
        {
            if (s == arr[m][n])
            {
                cnt++;
            }
            else
            {
                s = arr[m][n];
                cnt = 1;
            }
            if (cnt > max)
            {
                max = cnt;
            } //이게 else 안에 있으면 한줄이 다 같을때 체킹이 되지 않음
        }
    }
    for (int n = 0; n < N; n++)
    {
        char s = arr[0][n];
        int cnt = 0;
        for (int m = 0; m < N; m++)
        {
            if (s == arr[m][n])
            {
                cnt++;
            }
            else
            {

                s = arr[m][n];
                cnt = 1;
            }
            if (cnt > max)
            {
                max = cnt;
            }
        }
    }

    return max;
}