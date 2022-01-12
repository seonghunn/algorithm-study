#include <iostream>
#include <string>
using namespace std;
//iterator는 linked list 공부할 때 tmp포인터라고 생각하면 됨
//vector는 동적 할당된 linked list라고 생각하면 됨

//for를 이용한 탐색을 통해 다시 한번 풀어오기 (바뀌기 이전까지의 알파벳 탐색)
int main()
{
    int num;
    int cnt = 0;

    cin >> num;
    string tmp;

    for (int i = 0; i < num; i++)
    {
        bool isgroupword = true;
        bool isused[26] = {false}; //각각의 알파벳 아스키 코드를 배열의 인덱스로, 사용되면 true로 바꿈
        cin >> tmp;
        for (int j = 1; j < tmp.length(); j++)
        {
            if (tmp[j] != tmp[j - 1] && isused[tmp[j] - 97] == true) //문자가 바뀔 때, 바뀌는 문자가 사용된 문자면 바로 groupword =false
            {
                isgroupword = false;
                break;
            }

            if (tmp[j] != tmp[j - 1] && isused[tmp[j - 1] - 97] == false) //문자가 바뀔 때, 바뀌기 전 문자가 사용되지 않았다면 true로 바꿈
            {
                isused[tmp[j - 1] - 97] = true;
            }
        }
        if (isgroupword)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}