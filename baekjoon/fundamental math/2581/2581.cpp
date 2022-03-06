#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> v;
    for (int i = M; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                cnt++;
            }
        }
        if (cnt == 2)
            v.push_back(i);
    }
    if (v.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int sum = 0; //이걸 0으로 초기화 안하면 undefined behavior... 채점 오류
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }

        cout << sum << endl;
        cout << v.front() << endl;
    }

    return 0;
}