#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    pair<int, int> arr[100000];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].second >> arr[i].first; //first가 끝나는 시간, second가 시작하는 시간
    }

    sort(arr, arr + N); //끝나는 시간이 빠른 순 정렬

    int tmp = arr[0].first; //가장 끝나는 시간이 빠른 회의가 끝나는 시간
    int cnt = 1;

    for (int i = 1; i < N; i++)
    {
        if (tmp <= arr[i].second) //시작 시간이 끝나는 시간보다 같거나 클 때 갱신, 끝나는 시간은 시작하는 시간보다 더 크므로
        //정렬된 상태에서 끝나는 시간의 인덱스를 기준으로 i를 증가시키며 탐색해도 어긋나는 케이스가 없다.
        {
            cnt++;
            tmp = arr[i].first;
        }
    }
    cout << cnt << endl;

    return 0;
}