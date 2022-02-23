#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
int sum;
int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    //최솟값은 하루에 사용하는 최대 액수가 되어야지 한번의 인출로 사용할 수 있음. 그보다 작다면 아무리 인출해도 하루 양을 채우질 못하기 때문
    int left = *max_element(arr, arr + n);
    int right = sum;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int tmpsum = 0;
        //묶음은 시작값이 1
        int tmpcnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (tmpsum + arr[i] <= mid)
                tmpsum += arr[i];
            else
            {
                tmpsum = arr[i];
                tmpcnt++;
            }
        }
        //m번 인출한다 하더라도, 그 중 최솟값을 찾아야 하기 때문에 왼쪽에서 탐색한다.
        if (tmpcnt <= m)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left;

    return 0;
}