#include <iostream>
using namespace std;

int recursion(int row, int col)
{
    if (col == 1)
    {
        return 1;
    }
    if (row == -1)
    {
        return 1;
    }
    return (recursion(row - 1, col) + recursion(row, col - 1));
}
/*
1.     6.    21    56.  
1.     5.    15.   35.   70.  
1      4.    10.   20.   35   56
1      3.     6.    10.   15.  21
1.     2      3.     4.     5.    6 (0행)
1.     1.     1.     1.    1 (-1행)
*/
int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int k, n;
        cin >> k;
        cin >> n;

        int res = recursion(k, n);
        cout << res << endl;
    }

    return 0;
}