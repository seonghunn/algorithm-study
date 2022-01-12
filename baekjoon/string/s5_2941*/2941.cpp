#include <iostream>
#include <string>
#include <vector>
using namespace std;
//문자열에서 크로아티아를 찾지 말고, 크로아티아 알파벳 배열을 미리 선언한 다음 문자열에서 그것들을 찾는 방식으로 해야한다.
//if문이 많아질수록 예외처리 개빡셈.
/*int filter(string str)
{
    int total = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 99 && i < str.length() - 1) //c=, c-
        {
            if (str[i + 1] == 61 || str[i + 1] == 45)
                total++;
        }

        if (str[i] == 100 && i < str.length() - 2) //dz=
        {
            if (str[i + 1] == 122)
            {
                if (str[i + 2] == 61)
                    total = total + 2;
            }
        }

        if (str[i] == 100 && i < str.length() - 1) //d-
        {
            if (str[i + 1] == 45)
                total++;
        }

        if (str[i + 1] == 106 && i < str.length() - 1) //lj,nj
        {
            if (str[i] == 108 || str[i] == 110)
                total++;
        }

        if (str[i + 1] == 61 && i < str.length() - 1) //s=,z=
        {
            if (str[i] == 122 || str[i] == 115)
                total++;
        }

        return total;
    }
}
*/
/*
vector<string> croatian = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

string filter(string str)
{
    for (int i = 0; i < 8; i++)
    {
        str.replace(str.find(croatian[i]), croatian[i].length(), "#");
    }

    return str;
}

int main()
{
    int cnt;
    string str;
    cin >> str;

    str = filter(str);

    cout << str.length() << endl;

    return 0;
}
*/

//여기서부터 정답

/*
vector<string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

string input;

//결과
int res = 0;

int main()
{

    //입력 ex) input : ddz=z=
    cin >> input;

    for (int i = 0; i < croatia.size(); i++)
    {
        //크로아티아 문자열 찾기(while을 사용하는 이유는 두 번 검색될 수 있기 때문)
        while (true)
        {
            int index = input.find(croatia[i]);

            //크로아티아 문자열이 없을 경우
            if (index == string::npos)
            {
                break;
            }

            //크로아티아 문자열 -> "#"으로 바꾸기
            input.replace(index, croatia[i].length(), "*");
        }
    }

    //ex) input : d**
    res = input.length();

    //출력
    cout << res << "\n";
}*/