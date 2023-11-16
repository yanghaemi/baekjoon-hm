#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b, int c, int d)
{
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    int max = -1;
    for (int i = 0; i < 4; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int res = 0;
    if (n == 1) // ��� 1��
        cout << v[0];
    else if (n == 2) // ��� 2��
        cout << v[0] + v[1];
    else if (n == 3) // ��� 3��
        cout << max(v[0] + v[2], v[1] + v[2]);
    else if (n == 4) // ��� 4��
        cout << max(v[0] + v[1] + v[3], v[0] + v[2] + v[3]);
    else // ����� 5�� �̻�
    {

        res += max(v[0] + v[1] + v[3], v[1] + v[2] + v[4]);
        for (int i = 0; i < n;)
        {
            if (i == n - 1) // ��� 1��
                res += v[i];
            else if (i == n - 2) // ��� 2��
                res += v[i] + v[i + 1];
            else if (i == n - 3) // ��� 3��
                res += max(v[i] + v[i + 2], v[i + 1] + v[i + 2]);
            else if (i == n - 4) // ��� 4��
                res += max(v[i] + v[i + 1] + v[i + 3], v[i] + v[i + 2] + v[i + 3]);
            else
            {
                res += max(v[i] + v[i + 1] + v[i + 3], v[i] + v[i + 2] + v[i + 3], v[i + 1] + v[i + 2] + v[i + 4], v[i + 1] + v[i + 3] + v[i + 4]);
                i += 5;
            }
        }
    }
}