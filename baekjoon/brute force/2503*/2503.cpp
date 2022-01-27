#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool arr[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = true;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (i < 123)
            arr[i] = false;
        string tmp = to_string(i);
        if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
            arr[i] = false;
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) //중복된 수, 0이 포함된 수, 범위를 벗어난 수 전부 제거
            arr[i] = false;
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) //질문 개수는 100 이하이므로, 100*1000*9 는 1억번 이하의 연산, 완전탐색 가능
    {
        int num, S, B;
        cin >> num >> S >> B;
        for (int j = 0; j < 1000; j++) //리스트 안의 가능한 것을 추려서 질문과 맞는지 비교함 (질문->답 이 아니라 답->질문 방향의 접근)
        {

            if (arr[j])
            {                                 //이미 배제되지 않은 것들만 골라서
                string tmp1 = to_string(num); //string으로 바꿔서 각각의 자리수에 대하여 모두 비교
                string tmp2 = to_string(j);
                int tmpS = 0;
                int tmpB = 0;
                for (int m = 0; m < 3; m++) //strike, ball이 합당하게 나왔으면 "가능한 숫자"
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (m == n && tmp1[m] == tmp2[n])
                            tmpS++;
                        if (m != n && tmp1[m] == tmp2[n]) //자릿수가 다르지만 값은 같으면 볼
                            tmpB++;
                    }
                }
                if (tmpS != S || tmpB != B) //스트라이크, 볼 조건이 다르면 배제
                    arr[j] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i])
            cnt++;
    }

    cout << cnt << endl;
}