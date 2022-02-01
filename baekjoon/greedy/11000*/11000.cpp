#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int N;
pair<int, int> p[200000];
priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 (greater가 작은 수를 위로 정렬)

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + N);

    pq.push(p[0].second);
    for (int i = 1; i < N; i++) //우선순위 큐를 사용하여, 수업이 끝나는 시간보다 늦게 열리는 수업을 끝난 수업의 자리에 넣음
    {
        if (pq.top() <= p[i].first)
        {
            pq.pop();
            pq.push(p[i].second);
        }
        else
        {
            pq.push(p[i].second);
        }
    }

    cout << pq.size() << endl;

    return 0;
}
