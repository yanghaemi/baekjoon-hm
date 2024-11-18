#include <iostream>
#include <vector>
using namespace std;

int n, m;
int res = 64; // ���� �ٲٴ� Ƚ��

void solutionW(int y, int x, vector<vector<char>> v)
{
    int flag_res = 0;
    int i = y;

    if (v[y][x] != 'W')
    {
        flag_res++;
    }
    v[y][x] = 'W';

    for (int j = x; j < x + 7; j++) // ù ��
    {
        if (v[i][j] == 'B')
        {
            if (v[i][j + 1] == 'B')
            {

                flag_res++;

                v[i][j + 1] = 'W';
            }
        }
        else if (v[i][j] == 'W')
        {
            if (v[i][j + 1] == 'W')
            {

                flag_res++;

                v[i][j + 1] = 'B';
            }
        }
    }
    for (int i = y + 1; i < y + 8; i++)
    {
        if (v[i][x] == v[i - 1][x])
        {
            if (v[i][x] == 'B')
            {
                v[i][x] = 'W';
                flag_res++;
            }
            else if (v[i][x] == 'W')
            {
                v[i][x] = 'B';
                flag_res++;
            }
        }
        for (int j = x; j < x + 7; j++)
        {

            if (v[i][j] == 'B')
            {
                if (v[i][j + 1] == 'B')
                {

                    flag_res++;

                    v[i][j + 1] = 'W';
                }
            }
            else if (v[i][j] == 'W')
            {
                if (v[i][j + 1] == 'W')
                {

                    flag_res++;

                    v[i][j + 1] = 'B';
                }
            }
        }
    }

    res = min(flag_res, res);
    // cout << "res: " << res << ", flag_res:" << flag_res << " W\n";

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << v[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << "------------\n";
}

void solutionB(int y, int x, vector<vector<char>> v)
{
    int flag_res = 0;
    int i = y;

    if (v[y][x] != 'B')
    {
        flag_res++;
    }
    v[y][x] = 'B'; // ó�� ���ڰ� B�� ��

    for (int j = x; j < x + 7; j++) // ù ��
    {
        if (v[i][j] == 'B')
        {
            if (v[i][j + 1] == 'B')
            {

                flag_res++;

                v[i][j + 1] = 'W';
            }
        }
        else if (v[i][j] == 'W')
        {
            if (v[i][j + 1] == 'W')
            {

                flag_res++;

                v[i][j + 1] = 'B';
            }
        }
    }
    for (int i = y + 1; i < y + 8; i++)
    {
        if (v[i][x] == v[i - 1][x])
        {
            if (v[i][x] == 'B')
            {
                v[i][x] = 'W';
                flag_res++;
            }
            else if (v[i][x] == 'W')
            {
                v[i][x] = 'B';
                flag_res++;
            }
        }
        for (int j = x; j < x + 7; j++)
        {

            if (v[i][j] == 'B')
            {
                if (v[i][j + 1] == 'B')
                {

                    flag_res++;
                    v[i][j + 1] = 'W';
                }
            }
            else if (v[i][j] == 'W')
            {
                if (v[i][j + 1] == 'W')
                {

                    flag_res++;

                    v[i][j + 1] = 'B';
                }
            }
        }
    }

    res = min(flag_res, res);
    // cout << "res: " << res << ", flag_res:" << flag_res << '\n';

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << v[i][j];
    //     }
    //     cout << '\n';
    // }
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j]; // �Է� �ޱ�
        }
    }

    for (int i = 0; i < n - 8 + 1; i++)
    {
        for (int j = 0; j < m - 8 + 1; j++)
        {
            solutionB(i, j, v);
            solutionW(i, j, v);
        }
    }

    cout << res;
    return 0;
}