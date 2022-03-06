#include <iostream>
using namespace std;

int ishansu(int N)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i < 100)
            cnt++;
        if (i > 100 && i < 1000)
            if ((i / 100) + (i % 10) == 2 * ((i % 100) / 10))
                cnt++;
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int res = ishansu(N);

    cout << res << endl;

    return 0;
}