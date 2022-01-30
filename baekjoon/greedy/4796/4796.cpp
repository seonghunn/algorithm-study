#include <iostream>
using namespace std;

int cnt = 1;
int main()
{
    while (true)
    {
        int L, P, V;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        else
        {
            int tmp = V / P;
            int ans = tmp * L;
            if (V % P >= L)
                ans += L;
            else
                ans += V % P;

            cout << "Case " << cnt << ": " << ans << endl;
            cnt++;
        }
    }
    return 0;
}