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
        sum += (11 - i) * T[i];
    }

    for (int i = 0; i < 11; i++)
    {
        Vsum += 20 * V[i];
    }

    cout << sum + Vsum << endl;

    return 0;
}