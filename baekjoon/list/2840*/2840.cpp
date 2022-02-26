#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <deque>
#include <set>
#define endl "\n"
using namespace std;

stack<pair<int, char> > s;
deque<char> ans;
set<char> isused;
int N, K, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        ans.push_back('?');

    //stack에 넣고 빼면서 확인 (맨 아래부터 넣어야 하므로)
    for (int i = 0; i < K; i++)
    {
        int tmpint;
        char tmpc;
        cin >> tmpint >> tmpc;
        sum += tmpint;
        s.push(make_pair(tmpint, tmpc));
    }
    while (!s.empty())
    {
        if (ans.front() == '?' || ans.front() == s.top().second)
        {
            ans.pop_front();
            ans.push_front(s.top().second);
            for (int i = 0; i < s.top().first; i++)
            {
                char tmpstr = ans.front();
                ans.pop_front();
                ans.push_back(tmpstr);
            }
            s.pop();
        }
        else
        {
            cout << '!';
            exit(0);
        }
    }

    //시작점으로 돌리기
    for (int i = 0; i < N - sum % N; i++)
    {
        char tmpstr = ans.front();
        ans.pop_front();
        ans.push_back(tmpstr);
    }

    //중복되는 문자 있으면 없애야함
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '?')
        {
            if (isused.find(ans[i]) == isused.end())
                isused.insert(ans[i]);
            else
            {
                cout << '!';
                exit(0);
            }
        }
    }

    //출력
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}