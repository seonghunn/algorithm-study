#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int sub[1000];
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int tmp = L - 1; //1 3 구멍 뚫려 있으면 길이가 3이어야 막음, 즉 L-1만큼의 구멍을 막을수있다.
    int cnt = 1;     //기본값 1 (마지막에 for 탈출하면서 +1 해야함, <=tmp 때문에 else를 한 번 안 지남)
    for (int i = 0; i < N - 1; i++)
    {
        if (v[i + 1] - v[i] <= tmp)
        {
            tmp -= v[i + 1] - v[i]; //테이프 사용
        }
        else
        {
            tmp = L - 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}