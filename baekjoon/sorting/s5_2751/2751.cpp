#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//cout, endl은 시간 소모가 큼, endl를 \n으로 바꾸면 시간 단축 가능

int main()
{
    int cnt, tmp;
    cin >> cnt;

    vector<int> v;
    for (int i = 0; i < cnt; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < cnt; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}