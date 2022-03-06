#include <iostream>
using namespace std;

//5로 나눈 몫을 최대로 잡고, 그 몫을 숫자에서 뺀 값이 3으로 나누어 떨어지지 않으면 몫에서 -1을 계속 해가며 계산 진행
//몫이 0까지 진행 (3으로만 나누는 게 됨)
int main()
{
    int num;
    cin >> num;
    int quot = num / 5;

    while (quot >= 0)
    {
        int tmp = num - 5 * quot;
        if (tmp % 3 == 0)
        {
            cout << tmp / 3 + quot << endl;
            break;
        }
        else
        {
            quot--;
        }
    }

    if (quot < 0)
        cout << -1 << endl;

    return 0;
}