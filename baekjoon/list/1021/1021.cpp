#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#define endl "\n"
using namespace std;

int n, m;
int arr[51];
int cnt;
deque<int> dq;
//n의 최대가 50이므로, 단순히 두 케이스를 비교하며 더 작은 방향의 것을 선택하며 구현
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    for (int i = 0; i < m; i++)
    {
        deque<int> tmpdq1, tmpdq2;
        tmpdq1 = dq;
        tmpdq2 = dq;
        int tmpcnt1 = 0;

        while (tmpdq1.front() != arr[i])
        {
            int tmp = tmpdq1.front();
            tmpdq1.pop_front();
            tmpdq1.push_back(tmp);
            tmpcnt1++;
        }
        tmpdq1.pop_front();
        int tmpcnt2 = 0;
        while (tmpdq2.front() != arr[i])
        {
            int tmp = tmpdq2.back();
            tmpdq2.pop_back();
            tmpdq2.push_front(tmp);
            tmpcnt2++;
        }
        tmpdq2.pop_front();
        if (tmpcnt1 < tmpcnt2)
        {
            dq = tmpdq1;
            cnt += tmpcnt1;
        }
        else
        {
            dq = tmpdq2;
            cnt += tmpcnt2;
        }
    }
    cout << cnt;

    return 0;
}