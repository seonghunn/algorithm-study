#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

//dp 배열은 가장 긴 증가수열의 원소 개수를 가지고 있음
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int mx = 1;
        //만약 arr[i]가 arr[j]보다 크다면, dp 배열에서 가장 긴 증가수열의 원소 수를 불러와 mx에서 갱신
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                mx = max(mx, dp[j] + 1);
        dp[i] = mx;
    }

    //그중 가장 큰 원소가 가장 긴 증가수열의 원소 수
    cout << *max_element(dp, dp + n);
}

/*
//dp[i]는 i번째까지 가장 큰 증가수열
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    fill(dp, dp + 1001, 1);
    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[j] > max)
                    max = dp[j];
            }
        }
        dp[i] += max;
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }

    cout << max << endl;

    return 0;
}
*/