#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
#define MAX 1e18
typedef long long ll;
typedef struct tah
{
    int t;
    int a;
    int h;
};

ll n, H_atk, H_curhp, H_maxhp;
tah arr[123456];

bool dg(ll Health, ll H_atk)
{
    ll tmpAtk = H_atk;
    ll tmpHealth = Health;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].t == 1)
        {
            //공격받아서 체력이 깎임
            tmpHealth -= arr[i].a * (((arr[i].h + tmpAtk - 1) / tmpAtk) - 1);
            //용사가 먼저 몬스터를 떄려 몬스터가 죽으면 다음 피격을 안받기 때문에, 몫을 올림하고 -1한 값을 몬스터의 공격력에 곱해야함
        }
        else
        {
            //체력 회복, 공격력 갱신
            tmpAtk += arr[i].a;
            tmpHealth += arr[i].h;
            //회복량이 최대체력보다 많으면 최대체력으로
            if (tmpHealth >= Health)
                tmpHealth = Health;
        }

        if (tmpHealth <= 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> H_atk;
    for (int i = 0; i < n; i++)
        cin >> arr[i].t >> arr[i].a >> arr[i].h;

    ll lo = 1;
    ll hi = MAX;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        //가능하면 더 작은 범위가 있는지 탐색
        if (dg(mid, H_atk))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    cout << lo;

    return 0;
}