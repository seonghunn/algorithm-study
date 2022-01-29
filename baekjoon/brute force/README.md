# Brute Force algorithm

**말 그대로, 가능한 모든 경우의 수를 탐색하는 알고리즘이다. 브루트포스(완전탐색)을 사용하기 위해서는, 완전탐색을 수행할 때의 연산 횟수와 제한시간을 가늠하고 사용한다**

## 다시 풀어볼 문제

- 1182(dfs)★★
- 2503(구현)★
- 3085(구현)★
- 1018(구현, 답->케이스 방향의 비교)★

## DFS

**완전 탐색 문제에서 빈번하게 등장할 수 있는 것이 조합 논리다, 1,2,3,4 가 있을 때, 1,2,3,4,12,13,14,23,24,34,123,124,234,1234 와 같이, 2^n 경우를 가지는 모든 케이스를 탐색해야 할 때가 많은데, 이를 구현할 수 있는 방법이 dfs이다**

### 스택 이용

```c
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v[10] = {{}, {2, 3}, {1, 3, 4, 5}, {1, 2, 6, 7}, {2, 8}, {2, 9}, {3}, {3}, {4}, {5}};
bool isVisited[9];

int main()
{
    stack<int> s;
    cout << "** node" << 1 << " visited! **" << endl;
    cout << "push 1" << endl;

    s.push(1);
    isVisited[1] = true;

    while (!s.empty())
    {
        // if the node has (unvisited) connected node(s)
        bool isConnected = false;
        int cur_node = s.top();

        // search all connected nodes
        for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++)
        {
            // if the node has a unvisited & connected node(s)
            if (!isVisited[*i])
            {
                isConnected = true;

                cout << "** node" << *i << " visited! **" << endl;
                cout << "push " << *i << endl;

                s.push(*i);
                isVisited[*i] = true;
                break;
            } //방문하지 않은 노드가 없다면 isConnected가 계속 false 이므로 아래로 감
        }
        if (!isConnected)
        {
            s.pop();
            cout << "pop" << cur_node << endl;
        }
    }
    return 0;
}
```

```
출력 결과
** node1 visited! **
push 1
** node2 visited! **
push 2
** node3 visited! **
push 3
** node6 visited! **
push 6
pop6
** node7 visited! **
push 7
pop7
pop3
** node4 visited! **
push 4
** node8 visited! **
push 8
pop8
pop4
** node5 visited! **
push 5
** node9 visited! **
push 9
pop9
pop5
pop2
pop1
```

### 재귀 이용

```c
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[10] = {{}, {2, 3}, {1, 3, 4, 5}, {1, 2, 6, 7}, {2, 8}, {2, 9}, {3}, {3}, {4}, {5}};
bool isVisited[9];

void dfs(int cur_node)
{
    cout << "cur node : " << cur_node << endl;
    isVisited[cur_node] = true;
    for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++)
    {
        if (!isVisited[*i])
            dfs(*i);
    }
}

int main(void)
{
    dfs(1);
}
```

```
출력 결과
cur node : 1
cur node : 2
cur node : 3
cur node : 6
cur node : 7
cur node : 4
cur node : 8
cur node : 5
cur node : 9
```

코드 출처: https://choiiis.github.io/algorithm/practice-dfs/
