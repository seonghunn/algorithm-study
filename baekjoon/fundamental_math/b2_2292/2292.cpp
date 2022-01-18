#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    num--; //1 2~7 8~19 이런 식으로 되기 때문에 6의 배수를 맞추려면 1을 빼야함

    if (num == 0) //else의 구조대로 하면, num=1일 때 idx가 반드시 1이기 때문에 2를 출력하게 됨, 예외처리 해야함
    {
        cout << 1 << endl;
    }
    else
    {
        int idx;
        for (idx = 1; num > 6 * idx; idx++)
        {
            num -= 6 * idx; //6+12+18..이런식으로 묶어주는 것
        }

        cout << idx + 1 << endl; //맨 중앙에 1도 1개로 취급하므로 +1 해야함
    }

    return 0;
}