#include <iostream>
#include <string>
#include <vector>
using namespace std;

//가변 배열(vector)말고, 그냥 a[10001] 이런 식으로 해서 res[10001]에 a+b를 그대로 박아도 됨

int main()
{
    string A, B;
    cin >> A >> B;

    if (A.size() < B.size())
    {
        string tmp = A;
        A = B;
        B = tmp;
    }

    vector<int> a, b, res;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        a.push_back(A[i] - '0');
    }
    for (int i = B.size() - 1; i >= 0; i--)
    {
        b.push_back(B[i] - '0');
    } //뒤부터 넣으니까 순서 주의

    int isover10 = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] + b[i] + isover10 >= 10)
        {
            res.push_back(a[i] + b[i] + isover10 - 10);
            isover10 = 1;
        }
        else
        {
            res.push_back(a[i] + b[i] + isover10);
            isover10 = 0;
        }
    }

    for (int i = b.size(); i < a.size(); i++) //b의 인덱스가 정의되지 않은 부분
    {
        if (a[i] + isover10 >= 10)
        {
            res.push_back(a[i] + isover10 - 10);
            isover10 = 1;
        }
        else
        {
            res.push_back(a[i] + isover10);
            isover10 = 0;
        }
    }
    if (isover10 == 1) //999+1 처럼 a의 인덱스보다 큰 곳에 1이 존재할 수 있음
    {
        res.push_back(1);
    }

    vector<int>::iterator iter;
    for (iter = res.end() - 1; iter != res.begin() - 1; iter--) //pushback이므로 뒤부터 출력
    {
        cout << *iter;
    }
    cout << endl;

    return 0;
}