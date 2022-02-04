#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[1001]; //v[마감시간][점수]
vector<int> res;
int sum = 0;

bool compare(int i, int j)
{
    return j < i;
}
//n일차에 수행할 수 있는 과제의 수는 n개이므로, n개 초과시 가장 작은것부터 쳐낸다
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int first, second;
        cin >> first >> second;
        v[first].push_back(second);
    }
    int idx = 1;
    while (idx <= 1000)
    {
        for (int j = 0; j < v[idx].size(); j++)
        {
            res.push_back(v[idx][j]);
        }
        sort(res.begin(), res.end(), compare); //내림차순 정렬

        if (res.size() > idx) //ex) 4일차인데 4보다 많이 들어있으면, 점수가 높은 순으로 4개만 선택한다
        {
            while (idx < res.size()) //idx만큼(마감까지 걸리는 시간) size를 조정해야 하는데, res는 삭제할수록 길이가 변하므로 이렇게 삭제한다
            {
                res.erase(res.begin() + idx);
            }
        }
        idx++;
    }

    for (int i = 0; i < res.size(); i++)
    {
        sum += res[i];
    }

    cout << sum << endl;
    return 0;
}