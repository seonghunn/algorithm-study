#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;
#define MX 100001
typedef long long ll;

ll N, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> k;
    ll hi = N * N;
    ll lo = 1;
    while (lo <= hi)
    {
        ll mid = (hi + lo) / 2;
        ll cnt = 0;
        //row를 탐색하며 각 row에 mid보다 작은 숫자의 개수를 센다. 수가 굉장히 많으므로 이진 탐색을 활용
        for (int i = 1; i <= N; i++)
            cnt += min(mid / i, N);
        //개수가 k보다 작으면 더 큰 값을 찾기
        if (k > cnt)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << lo;

    return 0;
}