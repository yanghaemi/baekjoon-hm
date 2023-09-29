#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int num;

    queue<pair<int, int>> q;

    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v[n].push_back(num);

            if (num == 1)
                q.push(pair<int, int>(n, m));
        }
    }
}