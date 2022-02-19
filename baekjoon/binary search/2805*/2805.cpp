#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000001
typedef long long ll;

ll arr[MAX];
ll n, m;

ll ps(int left, int right)
{
    ll mid = (left + right) / 2;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - mid >= 0)
            sum += arr[i] - mid;
    }
    //left+1 == right라면, 이미 최소 단위까지 탐색을 완료했으므로, mid는 left 값이 되며, 이는 m보다 많은 양의 나무를 가져갈 수 있는 최대 높이이다(딱 m은 아님)
    if (sum == m || left + 1 == right)
        return mid;
    else if (sum > m) //잘라낸 나무의 합이 원하는 값보다 더 크다면, 더 큰 크기를 잘라야함
        return ps(mid, right);
    else //잘라낸 나무의 합이 원하는 값보다 작다면, 더 작은 크기를 잘라야 함
        return ps(left, mid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << ps(0, *max_element(arr, arr + n));

    return 0;
}