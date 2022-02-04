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
    for (idx = min; idx >= 0; idx--) //최소 모서리 길이보다 작은 것 중, 큐브가 존재하는 것을 찾는다. 0이 될때까지 없으면 제공된 큐브로는 육면체를 구성할 수 없다.
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

int main()
{
    int first, sec;
    cin >> len >> wid >> hei;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> first >> sec;
        a[i] = sec;
    }
    count(len, wid, hei, N - 1);
    cout << cnt << "\n";

    return 0;
}

/*pair<long long, long long> p[20];
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
}*/