#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;

    vector<int> v(n + 1);

    v[11] = 3;

    for (int i = 1; i <= n; i++)
    {
        if (i == 4 || i == 7)
            v[i] = -1;
        else if (i % 5 == 0)
            v[i] = i / 5;
        else if (i % 3 == 0 && i <= 12)
            v[i] = i / 3;
        else if (i % 8 == 0)
            v[i] = 2 * (i / 8);
        else if (i > 12)
        {
            int m = i;
            while (m - 8 >= 3 && m - 8 != 7 && m - 8 != 4 && m - 8 != 12)
            {

                m -= 8;
                if (m % 5 == 0)
                    break;
            }
            v[i] = v[i - m] + v[m];
        }
    }
    // cout << '\n';

    cout << v[n];
}