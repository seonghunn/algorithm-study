#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[21][21];
int N;

//예외처리를 통과하면 (보석개수, 붏순물 개수로) 불순물에서 일자로 보석이 없다면, 그 방향으로 자르고 나누어진 두 판에 대하여 재귀호출
//type는 가로->세로->가로 혹은 세로->가로->세로 로 자르기 위한 로직
int stonePlate(int rstart, int cstart, int rend, int cend, int type)
{
    set<int> improwidx; //불순물의 행 정보 , 중복 방지 위해 set을 사용
    set<int> impcolidx; //불순물의 열 정보
    int jewcnt = 0;     //보석 수
    int impcnt = 0;     //불순물 수
    for (int i = rstart; i <= rend; i++)
    {
        for (int j = cstart; j <= cend; j++)
        {
            if (arr[i][j] == 1)
            {
                impcnt++;
                improwidx.insert(i);
                impcolidx.insert(j);
            }
            if (arr[i][j] == 2)
            {
                jewcnt++;
            }
        }
    }
    if (jewcnt == 1 && impcnt == 0) //보석1개, 불순물 0개면 완료 된 것
        return 1;
    if (impcnt == 0) //불순물 X 는 불가능
        return 0;
    if (jewcnt == 0) //보석 X는 불가능
        return 0;

    int res = 0;   //결과값
    if (type != 0) //1은 가로, 0은 세로
    {
        set<int>::iterator iter;
        for (iter = improwidx.begin(); iter != improwidx.end(); iter++)
        {
            bool canDivide = true;
            for (int j = cstart; j <= cend; j++)
            {
                if (arr[*iter][j] == 2)
                {
                    canDivide = false;
                    break;
                }
            }
            if (canDivide) //위아래로 자르고 위, 아래를 탐색해서 결괏값에 더해줌
            {
                res += stonePlate(rstart, cstart, *iter - 1, cend, 0) * stonePlate(*iter + 1, cstart, rend, cend, 0); //경우의 수를 생각하면 곱으로 받아야함
            }                                                                                                         //곱하는 이유는 수형도로 생각하면 쉽게 도출 가능
        }
    }
    if (type != 1) //세로로 자르기
    {
        set<int>::iterator iter;
        for (iter = impcolidx.begin(); iter != impcolidx.end(); iter++)
        {
            bool canDivide = true;
            for (int i = rstart; i <= rend; i++)
            {
                if (arr[i][*iter] == 2)
                {
                    canDivide = false;
                    break;
                }
            }
            if (canDivide)
            {
                res += stonePlate(rstart, cstart, rend, *iter - 1, 1) * stonePlate(rstart, *iter + 1, rend, cend, 1);
            }
        }
    }
    return res;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    int res = stonePlate(1, 1, N, N, -1);

    if (res == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}