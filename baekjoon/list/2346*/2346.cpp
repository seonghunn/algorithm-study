#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#define endl "\n"
using namespace std;

int N;
deque<pair<int, int> > dq;

//런타임에러, divisionbyzero 에러에 유의. %연산자를 사용할 때는 항상 0으로 나누는 경우가 있는지 고려
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        pair<int, int> tmpp = make_pair(i + 1, tmp);
        dq.push_back(tmpp);
    }
    while (dq.size() != 1)
    {
        cout << dq.front().first << " ";
        int nextidx = dq.front().second;
        dq.pop_front();
        if (nextidx > 0)
        {
            for (int j = 0; j < (nextidx - 1) % dq.size(); j++)
            {
                pair<int, int> tmpp = dq.front();
                dq.pop_front();
                dq.push_back(tmpp);
            }
        }
        else
        {
            for (int j = 0; j < -nextidx % dq.size(); j++)
            {
                pair<int, int> tmpp = dq.back();
                dq.pop_back();
                dq.push_front(tmpp);
            }
        }
    }
    cout << dq.front().first;

    return 0;
}