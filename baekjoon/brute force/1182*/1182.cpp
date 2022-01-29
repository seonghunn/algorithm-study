#include <iostream>cd
using namespace std;

int arr[20];
int cnt = 0;
void dfs(int, int);
int N, S;

int main()
{
    cin >> N >> S; //N은 20 이하이므로, 전체 조합 경우의 수의 합을 고려할 때 2^20 이하이다. 따라서 완전탐색 가능

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    dfs(0, 0);

    cout << cnt << endl;

    return 0;
}

void dfs(int idx, int cur)
{
    if (idx >= N)
        return;
    if (S == cur + arr[idx])
        cnt++;

    dfs(idx + 1, cur);
    dfs(idx + 1, cur + arr[idx]);
}

/*void dfs(int idx, int cur) //재귀 호출 dfs test용
{
    if (idx >= N)
    { //탈출
        cout << "idx:" << idx << " return" << endl;
        return;
    }
    if (S == cur + arr[idx])
        cnt++;
    cout << "idx:" << idx << endl;
    cout << "cur:" << cur << endl;
    cout << "cur test:" << cur << "+" << arr[idx] << endl;
    dfs(idx + 1, cur);
    cout << "*" << endl;
    dfs(idx + 1, cur + arr[idx]); //1 2 3 / 12 / 123
}*/

/*
1 2 3 4
idx:0
cur:0
cur test:0+1
idx:1
cur:0
cur test:0+2
idx:2
cur:0
cur test:0+3
idx:3
cur:0
cur test:0+4
idx:4 return
*
idx:4 return
*
idx:3
cur:3
cur test:3+4
idx:4 return
*
idx:4 return
*
idx:2
cur:2
cur test:2+3
idx:3
cur:2
cur test:2+4
idx:4 return
*
idx:4 return
*
idx:3
cur:5
cur test:5+4
idx:4 return
*
idx:4 return
*
idx:1
cur:1
cur test:1+2
idx:2
cur:1
cur test:1+3
idx:3
cur:1
cur test:1+4
idx:4 return
*
idx:4 return
*
idx:3
cur:4
cur test:4+4
idx:4 return
*
idx:4 return
*
idx:2
cur:3
cur test:3+3
idx:3
cur:3
cur test:3+4
idx:4 return
*
idx:4 return
*
idx:3
cur:6
cur test:6+4
idx:4 return
*
idx:4 return
0
*/