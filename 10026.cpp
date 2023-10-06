#include <iostream>
#include <vector>
#include <queue>
#define VISIT '1'
using namespace std;

int n;
char c;
int cnt = 0; // ���� ��
int flag = 0;
int x, y;
queue<pair<int, int>> q;      // x, y��ǥ�� ���� queue ����
queue<pair<int, int>> next_q; // ���� ���� ���� ��ǥ�� ���� next_queue ����

void DFS(vector<vector<char>> &v)
{ // �迭 ������ ���� ������ �Ű����� ������

    int move_x[4] = {1, 0, 0, -1}; // ���ϻ���
    int move_y[4] = {0, 1, -1, 0};

    x = q.front().first, y = q.front().second;
    v[y][x] = VISIT;
    cout << "��¥ ��ǥ" << x << ", " << y << '\n';

    int xx = 0, yy = 0; // �ӽ� ��ǥ ����

    for (int i = 0; i < 4; i++)
    {
        xx = x + move_x[i], yy = y + move_y[i]; // �ӽ� ��ǥ �ʱ�ȭ

        if (xx < 0 || yy < 0 || yy >= n || xx >= n)
        {
            continue;
        } // �ӽ� ��ǥ�� ����� �Ѿ�� continue
        else
        {
            if (v[yy][xx] == c) // ���� �����̸�
            {
                v[yy][xx] = VISIT;         // �� �� �� ǥ��
                q.push(make_pair(xx, yy)); // ť�� �־���
            }
            else if (v[yy][xx] != c && v[yy][xx] != VISIT && flag == 0)
            {

                if (next_q.size() == 0)
                {
                    cout << "�ؽ�Ʈ ť�� ���� ��ǥ: " << xx << ", " << yy << ", " << v[yy][xx] << '\n';
                    next_q.push(make_pair(xx, yy));
                }
                flag = 1; // ���� ���� ���� ��ǥ�� �־���� ǥ��
                //(��ǥ�� 1���� �־�ߵż� ǥ�ø� ���ش�)
            }
            cout << "�ӽ� ���� ��ǥ : " << xx << "," << yy << '\n';
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << v[i][j];
                cout << '\n';
            }
            cout << "=========\n";
        }
    }
    if (!q.empty())
        q.pop();
}

int NotColorBlindness(vector<vector<char>> v)
{
    q.push(make_pair(0, 0)); // ���� ��ǥ ť�� �ֱ�
    c = v[0][0];
    v[0][0] = VISIT;
    DFS(v);
    while (1)
    {
        while (!q.empty())
        {
            cout << "���\n";
            DFS(v);
        }
        cnt += 1;

        if (!next_q.empty())
        {
            c = v[next_q.front().second][next_q.front().first];
            cout << "����\n";
            swap(q, next_q);
            flag = 0; // ncxt_q�� ���ٴ� ǥ��
        }

        else
            break;
        cout << q.empty();
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] != '1')
                q.push(make_pair(x, y));
    return cnt;
}

int main()
{

    cin >> n;

    vector<vector<char>> v(n, vector<char>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j]; // �� �Է�

    cout << NotColorBlindness(v) << " "; // ������� ���� ���ϴ� �Լ�
    cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == 'G')
                v[i][j] = 'R'; // �ʷϻ��� ���������� ���ս�Ű��

    cout << NotColorBlindness(v); // ������ ���� ���ϴ� �Լ�
}