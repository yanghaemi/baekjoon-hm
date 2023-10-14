#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int n;
int flag = 0;

int Max(int a, int b)
{
    if (a < b)
    {
        flag = 1; // 한 칸을 두 번 갔다는 표시
        n = n - 2;
    }
    return a < b ? b : a;
}

int DP(vector<int> &v)
{

    if (flag == 1)
    {
        res += v[n] + v[n - 2];
        flag = 0;
    }
    else
    {
        cout << v[n] + v[n - 2] << ", " << v[n] + v[n - 2] << '\n';
        res += Max(v[n] + v[n - 2], v[n] + v[n - 1] + v[n - 2]);
    }

    if (n - 2 > 0)
        DP(v);
    else
    {
        return res;
    }
}

int main()
{

    cin >> n; // 계단 개수
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i]; // 계단 data
    }

    cout << "결과" << DP(v);
}