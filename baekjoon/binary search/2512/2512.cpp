#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define MAX 100000

ll arr[MAX];
ll n, m;

ll ps(ll left, ll right)
{
    ll sum = 0;
    ll mid = (left + right) / 2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            sum += mid;
        else
            sum += arr[i];
    }

    if (sum == m || left + 1 == right)
        return mid;
    else if (sum > m) //투자해야되는 값이 예산보다 크다면, 더 적게 배정한다
        return ps(left, mid);
    else //투자값이 예산보다 작다면, 더 많이 배정한다.
        return ps(mid, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> m;

    //sum보다 배정된 예산이 크다면, 계산을 할 필요 없음
    if (m >= sum)
        cout << *max_element(arr, arr + n);
    //시작점을 *min_element가 아니라 0부터 해야함, 10, 20 예산 12의 경우, 10과 20사이에 상한 예산이 존재하지 않기 때문임.
    else
        cout << ps(0, *max_element(arr, arr + n));

    return 0;
}