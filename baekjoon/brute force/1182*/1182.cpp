#include <iostream>
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
check 1 2 3 4
return idx 4
check 34
return idx 4
check 23 24
return idx 4
check 234
retrun idx 4
check 12 13 14
return idx 4
*(cur+arr 수행)
check 134
return idx 4
*
check 123 124
return idx 4
*
check 1234

*/