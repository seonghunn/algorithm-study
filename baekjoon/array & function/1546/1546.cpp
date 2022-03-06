#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int score[num];
    for (int i = 0; i < num; i++)
    {
        cin >> score[i];
    }

    int max;
    int sum;
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            max = score[i];
            sum = score[i];
        }
        else
        {
            if (max < score[i])
            {
                max = score[i];
            }
            sum += score[i];
        }
    }

    cout << (sum / (max * (float)num)) * 100 << endl;

    return 0;
}