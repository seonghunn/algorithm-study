**문제를 확실하게 풀고 구현하는 과정 자체는 비교적 순탄했지만 이 문제는 시간 초과가 수십번이나 뜰 정도로 감을 못 잡은 문제였다. 정답 코드는 다음과 같다.**

```c
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int a[21];
long long cnt;
int len, wid, hei, N;
void count(int x, int y, int z, int cur_idx)
{
    if (x == 0 || y == 0 || z == 0)
        return;

    int minimum = min({x, y, z});
    int idx;
    int min = log2(minimum);
    bool isvalid = false;
    for (idx = min; idx >= 0; idx--)//최소 모서리 길이보다 작은 것 중, 큐브가 존재하는 것을 찾는다. 0이 될때까지 없으면 제공된 큐브로는 육면체를 구성할 수 없다.
    {
        if (a[idx] > 0)
        {
            cur_idx = idx;
            isvalid = true;
            break;
        }
    }
    if (!isvalid)
    {
        cout << -1 << "\n";
        exit(0);
    }
    a[idx]--;
    cnt++;
    int tmplen = pow(2, idx);

    count(x - tmplen, tmplen, tmplen, cur_idx); //큐브 세 조각에 대해서 다시 수행
    count(x, y - tmplen, tmplen, cur_idx);
    count(x, y, z - tmplen, cur_idx);
}
```

**시간 초과가 무지하게 뜬, 초반에 내가 구현한 코드는 다음과 같다**

```c
#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
pair<long long, long long> p[20];
int a[20];
int len, wid, hei, N;
long long cnt;
bool isvalid = true;

bool checkvalid()
{
if (p[0].second < 0)
return false;
else
return true;
}

void count(int a, int b, int c)
{
if (a == 0 || b == 0 || c == 0)
return;

    int arr[3] = {a, b, c};
    int res[3];
    sort(arr, arr + 3); //오름차순 정렬
    int idx = N - 1;
    while (p[idx].first > arr[0] || p[idx].second == 0) //큐브의 길이가 육면체의 가장 작은 길이보다 크다면, 큐브의 길이를 가장 작은 길이보다 같거나 작을 때까지 줄인다.
    {
        idx--;
    }
    if (idx == 0) //길이가 1인것만 남았을 경우
    {
        p[idx].second -= arr[0] * arr[1] * arr[2]; //해당 부피를 전부 1로 바꾼다
        cnt += arr[0] * arr[1] * arr[2];
        isvalid = checkvalid(); //1이 부족하면 false로 만든다.
        if (!isvalid)
        {
            cout << -1 << endl;
            exit(0); //1이 부족하면 바로 종료
        }
        return; //성공적으로 수행했다면 return
    }
    p[idx].second--;
    cnt++;
    for (int i = 0; i < 3; i++)
    {
        res[i] = arr[i] - p[idx].first;
    }
    count(res[0], p[idx].first, p[idx].first); //큐브 세 조각에 대해서 다시 수행
    count(arr[0], res[1], p[idx].first);
    count(arr[0], arr[1], res[2]);

}

int main()
{
cin >> len >> wid >> hei;
cin >> N;
for (int i = 0; i < N; i++)
{
cin >> p[i].first >> p[i].second; //first 길이, sec 개수
p[i].first = pow(2, p[i].first);
}
count(len, wid, hei);
if (isvalid)
cout << cnt << endl;

    return 0;

}
```

**우선, 단순 배열의 인덱스로 처리할 수 있는 큐브의 모서리 길이를, 굳이 pair로 계산하여 시간 소모가 많이 들었다. <br/>또한 매 순간 while로 전체를 탐색할 필요 없이 매번 길이보다 작거나 같은 것 중에서 큐브가 존재하는지를 확인하면 되기 때문에 불필요한 탐색으로 인한 시간 소모를 줄인다(재귀를 사용하므로 시간이 굉장히 많이 듬)<br/>마지막으로, 굳이 길이가 1이 남을 때의 경우를 따로 처리했다. 사실, 이것이 더 직관적이어서 처음엔 이렇게 구현했지만 예외가 최대한 없는 일반적인 코드를 구현해 판단에 소모되는 과정을 줄여야 했다.<br/> 한 함수가 실행될 때 최대 3개의 함수를 재귀적으로 실행하므로, 3^n 의 시간 복잡도를 가지기 때문에 최대한 예외를 줄이고, 연산을 줄여야 시간 초과가 나지 않을 수 있다.**
