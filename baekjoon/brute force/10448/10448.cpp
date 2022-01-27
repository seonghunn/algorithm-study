#include <iostream>
using namespace std;

int main()
{
    int Tnum[44];
    for (int i = 0; i < 44; i++)
    {
        Tnum[i] = (i + 1) * (i + 2) / 2;
    } //1000미만의 모든 삼각수, 44*45가 1980

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        bool isTrue = false;
        int num;
        cin >> num;
        for (int i = 0; i < 44; i++)
        {
            for (int j = i; j < 44; j++)
            {
                for (int k = i; k < 44; k++)
                {
                    if (Tnum[i] + Tnum[j] + Tnum[k] == num)
                    {
                        isTrue = true;
                        goto EXIT;
                    }
                }
            }
        } //O(n^3)이어도, 케이스가 45개니까 약 10만번 내외의 연산. 완전탐색 가능
    EXIT:
        cout << isTrue << endl;
    }

    return 0;
}