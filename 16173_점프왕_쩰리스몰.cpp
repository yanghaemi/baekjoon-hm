#include <iostream>
#include <vector>
using namespace std;

int flag = 0;

bool BFS(int n, vector<vector<int>> &v, int py, int px)
{
    int x_move[2] = {1, 0}; // ➡️⬇️
    int y_move[2] = {0, 1};

    for (int i = 0; i < 2; i++)
    {
        int cx = px + (x_move[i] * v[py][px]);
        int cy = py + (y_move[i] * v[py][px]);

        if (cx >= 0 && cx < n && cy >= 0 && cy < n)
        {
            if (v[cy][cx] == -1)
            {
                flag = 1;
                return true;
            }

            BFS(n, v, cy, cx);
        }
    }

    return false;
}

int main()
{
    int n; // 게임 구역의 크기
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n)); // 게임판의 구역(맵)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    BFS(n, v, 0, 0);

    if (flag)
    {
        cout << "HaruHaru";
    }
    else
        cout << "Hing";

    return 0;
}