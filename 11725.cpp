#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int n1;
    int n2;
    vector<int> v(1000000, 0);
    vector<int> pv(1000000, 0); // parent vector
    pv[1] = 1;                  // 1은 root

    int max = -1;

    for (int i = 0; i < n - 1; i++)
    {

        cin >> n1 >> n2;
        if (pv[n1] == 1)
        {
            if (pv[n2] == 0)
            {
                v[n2] = n1;
                pv[n2] = 1;
                if (max < n2)
                    max = n2;
            }
        }
        else
        {
            v[n1] = n2;
            pv[n1] = 1;
            if (max < n1)
                max = n1;
        }
    }
    int i = 2;
    while (i <= max)
    {
        if (pv[i] != 0)
        {
            cout << v[i]
                 << '\n';
        }
        i++;
    }
}