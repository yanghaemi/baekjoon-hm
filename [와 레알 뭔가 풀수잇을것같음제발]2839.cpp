#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;

    if (n == 4 || n == 7)
        cout << "-1";
    else if (n % 5 == 0)
        cout << n / 5;
    else if (n % 8 == 0)
        cout << n / 4;
    else if (n < 10 || n == 12)
        cout << n / 3;
    else
    {
        cnt += (n / 8) * 2 - 4;
        cout << "[cnt] :" << cnt << '\n';
        int a = n % 8;
        if (a == 1 || a == 3 || a == 5 || a == 7)
            cout << cnt + 3;
        else if (a == 2)
            cout << cnt + (n / 5);
        else if (a == 6 || a == 4)
            cout << cnt + 4;
    }
}