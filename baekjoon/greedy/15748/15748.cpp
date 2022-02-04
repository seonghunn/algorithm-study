#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <math.h>
#include <queue>
using namespace std;

long long L, N, rf, rb;
pair<int, int> p[100000];

int main()
{
    cin >> L >> N >> rf >> rb;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].second >> p[i].first; //second에 거리, first에 tasteunits
    }
    sort(p, p + N, greater<>()); //score가 높은 순으로 정렬

    long long rate = rf - rb;
    long long dist = 0;
    long long tunit = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].second > dist)
        {
            tunit += p[i].first * (p[i].second - dist) * rate; //상대속도 2ms 로 7m 지점에 도착하면, 14초 빨리 도착하기 때문에 곱하기
            dist = p[i].second;
        }
    }

    cout << (long long)tunit << endl;
    return 0;
}