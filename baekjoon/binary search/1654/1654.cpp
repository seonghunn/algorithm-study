#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 10001
using namespace std;
typedef long long ll;
ll k, n, sum;
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    ll left = 1;
    ll right = sum / n;

    while (left <= right)
    {
        ll mid = (left + right) / 2;
        int tmpcnt = 0;
        for (int i = 0; i < k; i++)
            tmpcnt += arr[i] / mid;

        //똑같이 tmpcnt가 n이어도 그 중 최댓값을 찾아야 하므로, n과 같거나 크면 무조건 오른쪽 탐색
        if (tmpcnt < n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << right;
    return 0;
}