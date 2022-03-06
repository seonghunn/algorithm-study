#include <iostream>
using namespace std;

int main()
{
    int A, B, V;
    cin >> A >> B >> V;

    int res;

    res = (V - A) / (A - B); // V이상 올라가면, 떨어지는것 없이 끝나므로, V-A까지!

    if ((V - A) % (A - B) == 0)
    {
        cout << res + 1 << endl;
    }
    else //연산은 나머지를 없애버리므로, 나머지가 0이 아니면 그만큼을 한번 더 올라가야함
    {
        cout << res + 2 << endl;
    }
    return 0;
}