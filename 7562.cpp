#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int move_x[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int move_y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int ly, lx; // last_y, fist_x
int fy, fx; // first_y, first_x
int result;

int m; // ü���� �� ���� ����

int BFS(vector<vector<int>> &v, queue<pair<int, int>> &q1, queue<pair<int, int>> &q2)
{
    int y = q1.front().first;
    int x = q1.front().second; // ť���� ������
    q1.pop();
    for (int i = 0; i < 8; i++)
    {
        int flag_y = 0, flag_x = 0; // �ӽ� ��ǥ
        flag_y = y + move_y[i];
        flag_x = x + move_x[i];

        if (flag_y < m && flag_y >= 0 && flag_x < m && flag_x >= 0 && v[flag_y][flag_x] != 1) // �湮 �� �� ��
        {

            if (v[flag_y][flag_x] == 3) // �̵� ����
            {
                return ++result;
            }
            else
            {
                q2.push(make_pair(flag_y, flag_x)); // ť�� �ֱ�
                v[flag_y][flag_x] = 1;              // �湮 ǥ��
            }
        }
    }

    if (q1.empty() && !q2.empty())
    {
        // for (int j = 0; j < m; j++)
        // {
        //     for (int k = 0; k < m; k++)
        //     {
        //         cout << v[j][k] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << "----------\n";
        result++;    // ť�� �ٲ�ٴ� �� �̵��� �� �� �ߴٴ� ��!
        q1.swap(q2); // ��������
        BFS(v, q1, q2);
    }
    else
    {
        BFS(v, q1, q2);
    }
    return result; // �߰��ߴ��� ��;;;
}

int solution()
{

    queue<pair<int, int>> q1; // ��ǥ ���� ť
    queue<pair<int, int>> q2; // ���� ��ǥ ���� ť

    result = 0; // ��� �ʱ�ȭ

    cin >> m;

    vector<vector<int>> v(m, vector<int>(m, 0));

    cin >> fy >> fx;
    cin >> ly >> lx;

    v[fy][fx] = 2; // ó�� ��� �湮 ó��
    v[ly][lx] = 3; // 3: ���� �ϴ� ��

    if (fy == ly && fx == lx)
        return 0;

    q1.push(make_pair(fy, fx)); // ����

    BFS(v, q1, q2);
    return result;
}

int main()
{
    int n; // �׽�Ʈ ���̽� Ƚ��
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << solution() << '\n';
    }

    return 0;
}