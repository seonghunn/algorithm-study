#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
using namespace std;

int arr[100];
set<int> s;
deque<int> dq;
int N, K;
int cnt = 0;
int main()
{
    cin >> K >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
        dq.push_back(num);
    }

    for (int i = 0; i < N; i++)
    {
        if (s.size() != K || s.count(arr[i]))
            s.insert(arr[i]);
        else
        {
            int idx = i;
            map<int, bool> m; //map에 인덱스로 매핑
            int lastNum = 0;
            for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
            {
                m[*iter] = 0;
            }
            cnt++;
            //꽂혀 있는 것 중 제일 뒤에 사용한 것을 뽑음(1 4 3 2 5 4 3 2 5 3 4 2 3 4 일 때, 인덱스 4의 5를 꼽을 때 4가 아닌 2를 뽑아야 함), 예외는 사용하는게 없을 때 (value=0일 때)
            while (idx < N)
            {
                if (s.count(dq[idx]) && m[dq[idx]] == 0)
                {
                    lastNum = dq[idx];
                    m[dq[idx]] = 1;
                }
                idx++;
            }
            auto iter = m.begin();
            while (iter != m.end())
            {
                if (!iter->second) //한번도 안나온 값이 있으면
                {
                    s.erase(iter->first); //그 값을 지우고 그 자리에 넣는다
                    s.insert(arr[i]);
                    break;
                }
                iter++;
            }
            if (iter == m.end()) //한번도 안나온 값이 없을때
            {
                s.erase(lastNum); //맨 뒤에있는 걸 지우고 그 자리에 넣는다
                s.insert(arr[i]);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}