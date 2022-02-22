#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 100000
typedef long long ll;
ll m, n;
ll sum;
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    //초기값 범위: 최대 원소~ 합
    ll left = *max_element(arr, arr + m);
    ll right = sum;
    ll mid = (left + right) / 2;
    //이렇게 루프를 구성해야 불가능 / 가능 의 경계까지 간 후, 가능한 최솟값을 찾아낼 수 있음
    while (left <= right)
    {
        ll tmpsum = 0;
        ll tmpcnt = 1; //블루레이는 1개부터 시작, 끊길 때마다 1개가 더생김
        ll mid = (left + right) / 2;
        for (int i = 0; i < m; i++)
        {
            if (tmpsum + arr[i] <= mid)
                tmpsum += arr[i];
            else
            {
                tmpsum = 0;
                tmpcnt++;
                tmpsum += arr[i];
            }
        }
        //똑같이 tmpcnt가 n이어도, 최솟값을 찾기 위해서는 왼쪽 영역을 탐색해야 하므로 tmpcnt<=n
        if (tmpcnt <= n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left;
    return 0;
}