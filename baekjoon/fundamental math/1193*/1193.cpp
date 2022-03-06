#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;

    int idx = 1;
    while (true)
    {
        if (idx >= input)
            break;
        input -= idx;
        idx++;
    } //idx가 input보다 커지면 (ex: 9면 1+2+3 하고 4 전에 멈춤)
    //idx : 대각선 줄의 인덱스, 남은 input: 그 중 몇번째 수인가?

    int sumof_num_den = idx + 1;

    if (idx % 2 == 0)
    {
        cout << input << "/" << sumof_num_den - input << endl;
    }
    else
    {
        cout << sumof_num_den - input << "/" << input << endl;
    }

    return 0;
}