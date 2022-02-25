#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#define endl "\n"
using namespace std;

deque<int> dq;
int N, K;
//O(N^2)로도 수행이 충분하므로, 문제에서 요구하는 그대로 수행한다
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        //K번째니까 K-1번 돌리고 그 뒤 pop 수행
        for (int j = 0; j < K - 1; j++)
        {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
        cout << dq.front();
        if (i != N - 1)
            cout << ", ";
        dq.pop_front();
    }
    cout << ">";

    return 0;
}