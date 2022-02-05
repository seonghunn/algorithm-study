#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

//2*2*2*2*2 를 2*2 2*2 2 로 나누고, 이를 2 2로 나눠서, 각각 나머지를 구한 뒤 제곱해서 올린다 (분할 -> 병합)
ll A, B, C;
ll calculate(ll a, ll b, ll c)
{
    if (b == 1) // base case:a를 c로 나눈 것을 출력하면 됨
        return a % c;
    ll tmp = calculate(a, b / 2, c);
    tmp = tmp * tmp % c; //병합 과정
    if (b % 2 == 0)      //짝수면 2로 나눠 쪼갠 것을 제곱한 것의 나머지
        return tmp;
    return tmp * a % c; //홀수면 거기에 남아버린 a 하나를 더 곱해 나머지를 리턴
}
int main()
{
    cin >> A >> B >> C;
    cout << calculate(A, B, C) << endl;
    return 0;
}