#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int H, W, N;
        cin >> H >> W >> N;

        int num1, num2;
        num1 = N / H;
        num2 = N % H;

        if (num2 > 0) //앞자리가 1, 첫번째 열 등등을 모두 포함하는 예외처리
            num1++;
        else
            num2 = H;

        cout << num2 * 100 + num1 << endl;
    }

    return 0;
}