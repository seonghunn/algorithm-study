#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int _num;
        cin >> _num;
        int score[_num];
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < _num; j++)
        {
            cin >> score[j];
            sum += score[j];
        }
        float avg = (float)sum / _num;
        for (int j = 0; j < _num; j++)
        {
            if (score[j] > avg)
            {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << ((float)cnt / _num) * 100 << "%" << endl;
    }

    return 0;
}