#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
typedef long long ll;
#define MX 1000000

struct abc
{
    int a;
    int b;
    int c;
};

abc arr[MX];
ll n, k, d;

//가장 뒤에 있는 상자의 값을 기준으로 이전까지 다 채울수 있는지 없는지를 검사해서 이분탐색
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> d;
    int mx = 0;
    int mi = MX + 1;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        //최대: 가장 끝, 최소: 가장 앞
        mx = max(arr[i].b, mx);
        mi = min(arr[i].a, mi);
    }
    int lo = mi;
    int hi = mx;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        ll tmpcnt = 0;
        for (int i = 0; i < k; i++)
        {
            // 나누기 간격 +1
            //arr[i].b와 mid 중에 작은 값을 기준으로 구간을 정해야함(10 100 기준일 때 200이 mid일 때와, 10 100 기준일 때 50이 mid 일 때를 비교해보면
            //각각 구간의 길이는 90과 40이 되어야 하므로, 두 값중에 최소를 해야함)
            if (min(arr[i].b, mid) >= arr[i].a)
                tmpcnt += 1 + ((min(arr[i].b, mid) - arr[i].a) / arr[i].c);
        }
        if (tmpcnt >= d)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    cout << lo;

    return 0;
}