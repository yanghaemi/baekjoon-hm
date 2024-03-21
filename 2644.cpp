#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
using namespace std;

int a = 0;

stack<int> mem;

int DFSs(vector<vector<int>> v, int start, int k1, int k2, int V_size, vector<bool> visited)
{
    int current = start;

    mem.push(current);
    visited[current] = true;
    cout << "VISIT : " << start << '\n';
    while (!mem.empty())
    {
        int num = 0;
        current = mem.top();
        bool found = false;
        // cout << current << '\n';
        for (int i = 1; i <= V_size; i++)
        {
            if (v[current][i] != 0 && !visited[i])
            {
                current = i;
                mem.push(current);
                visited[current] = true;
                cout << "22VISIT : " << current << "\n";
                num++;
                found = true;
                if (current == k1 || current == k2)
                {
                    a += num;
                    cout << "a " << a << '\n';
                }
                break;
            }
        }
        if (!found)
        {
            // ����� ������ ���ų�, ���� �� �湮�� ������ ���� ���
            mem.pop();
        }
    }
}

int main()
{
    int n = 0;          // ��ü ��� ��
    int k1 = 0, k2 = 0; // �̼��� ����ؾ��ϴ� ���� �ٸ� �� ����� ��ȣ
    int m = 0;          // �θ� �ڽĵ� ���� ������ ����
    vector<bool> visited(101, false);

    cin >> n;
    cin >> k1 >> k2;
    cin >> m;

    vector<vector<int>> v(101, vector<int>(101, 0));

    int num1 = 0; // �θ�
    int num2 = 0; // �ڽ�
    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        v[num1][num2] = 1; //[�θ�][�ڽ�] ���� ��Ŀ� 1�� ǥ��
    }

    // for (int i = 1; i <= 9; i++)
    // {
    //     for (int j = 1; j <= 9; j++)
    //     {
    //         cout << v[i][j];
    //     }
    //     cout << '\n';
    // }

    visited = vector<bool>(101, false);
    for (int i = 1; i < 9; i++) // �ӽ÷� 9�س���
        if (!visited[i])
            DFSs(v, i, k1, k2, m, visited);

    cout << a;
}