#include <iostream>
#include <algorithm>
using namespace std;

int T[11];
int V[11];
int main()
{
    for (int i = 0; i < 11; i++)
    {
        cin >> T[i] >> V[i];
    }
    sort(T, T + 11);
    int sum = 0;
    int Vsum = 0;
    for (int i = 0; i < 11; i++)
    {
        sum += (11 - i) * T[i]; //푼 시점에서까지 걸린 시간을 더하므로, 짧게 걸리는 문제를 먼저 풀어야함
    }

    for (int i = 0; i < 11; i++)
    {
        Vsum += 20 * V[i]; //V는 시간에 관계없이 20을 곱해서 더해진다
    }

    cout << sum + Vsum << endl;

    return 0;
}