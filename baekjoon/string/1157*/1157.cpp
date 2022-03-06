#include <iostream>
#include <string>
using namespace std;
//사용된 알파벳이 몇 개인가...
//복잡하게 생각하면 안되고, 아스키코드를 배열의 인덱스로 생각해서 각각 카운트 해버리는게 낫다. '사용된 것을 배열에 넣는' 발상은 별로 좋지 않음
int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }

    int cnt[26] = {0};
    int idx;
    int max = 0;
    int maxidx;
    bool isduplicated = false;
    for (int i = 0; i < s.length(); i++)
    {
        idx = (int)s[i] - 65;
        cnt[idx]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (i == 0)
        {
            max = cnt[i];
            maxidx = i;
        }
        else
        {
            if (cnt[i] > max)
            {
                max = cnt[i];
                maxidx = i;
                isduplicated = false;
            }
            else if (cnt[i] == max)
            {
                isduplicated = true;
            }
        }
        //cout << cnt[i] << endl;
    }

    if (isduplicated == false)
        cout << (char)(maxidx + 65) << endl;
    else
        cout << "?" << endl;

    return 0;
}