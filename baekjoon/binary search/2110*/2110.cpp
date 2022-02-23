#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
typedef long long ll;
#define MAX 200001
int n, c;
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    //idx 0의 위치에 하나는 무조건 꽂음
    ll hi = arr[n - 1];
    ll lo = 0;
    ll mid = 0;
    while (lo <= hi)
    {
        int cnt = 1;
        ll curdis = 0;
        mid = (hi + lo) / 2;
        for (int i = 1; i < n; i++)
        {
            curdis += arr[i] - arr[i - 1];
            if (curdis >= mid)
            {
                curdis = 0;
                cnt++;
            }
        }
        //같은 c를 가질 때 거리의 최대를 구해야 하므로, 같거나 크면 오른쪽을 탐색
        if (cnt >= c)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    //둘중 작은 값인 오른쪽이 답
    cout << hi;
    return 0;
}