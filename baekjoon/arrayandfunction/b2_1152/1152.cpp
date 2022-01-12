#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int cnt = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (i != 0 && i != s.length() - 1)
        {
            if ((int)s[i] == 32)
                cnt++;
        }
    }

    if (s.length() == 1 && (int)s[0] == 32) //한 글자의 공백은 단어 1개가 아니라 0개로 취급해야함
        cnt = 0;
    cout << cnt << endl;
}