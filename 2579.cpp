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
        flag = 1; // �� ĭ�� �� �� ���ٴ� ǥ��
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

    cin >> n; // ��� ����
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i]; // ��� data
    }

    cout << "���" << DP(v);
}