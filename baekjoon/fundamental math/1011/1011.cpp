#include <iostream>
using namespace std;

int main()
{
    int testnum;
    cin >> testnum;

    for (int i = 0; i < testnum; i++)
    {
        long long x, y, dis; //2^31까지 나오므로, long long
        cin >> x >> y;

        dis = y - x;
        int idx = 0;
        long long sum = 0;
        int res = 0;

        while (dis > sum)
        {
            idx++;
            sum += 2 * idx;
        } //5 넣으면 idx=2 ,idx는 안되는 숫자의 시작으로 맞추기 위함

        if (sum == dis)
        {
            res = 2 * idx; //ex: 20같이 2 4 6 8로 끝날 때 idx =5 -> 보정:4
        }
        else
        {
            sum -= idx * 2; //우선 sum을 초기화
            if (sum + idx < dis)
            {
                res = 2 * (idx - 1) + 2; //ex)19: 2+4+6 이고, +4까지는 가능, 하지만 거기다 +3 해야함
            }
            else if (sum + idx >= dis)
            {
                res = 2 * (idx - 1) + 1; //ex)16,15
            }
        }

        cout << res << endl;
    }

    return 0;
}