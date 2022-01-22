#include <iostream>
using namespace std;

int main()
{
    int num;
    int cnt = 0;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int a;
        cin >> a;
        bool is_primenum = true;

        for (int j = 2; j < a; j++)
        {
            if (a % j == 0)
                is_primenum = false;
        }

        if (a == 1)
            is_primenum = false;
        if (is_primenum)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}