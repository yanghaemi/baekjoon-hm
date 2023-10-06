#include <iostream>
#include <vector>
#include <queue>
#define VISIT '1'
using namespace std;

int n;
char c;
int cnt = 0; // 구역 수
int flag = 0;
int x, y;
queue<pair<int, int>> q;      // x, y좌표를 담을 queue 생성
queue<pair<int, int>> next_q; // 다음 구역 시작 좌표를 담을 next_queue 생성

void DFS(vector<vector<char>> &v)
{ // 배열 변경을 위해 참조로 매개변수 가져옴

    int move_x[4] = {1, 0, 0, -1}; // 우하상좌
    int move_y[4] = {0, 1, -1, 0};

    x = q.front().first, y = q.front().second;
    v[y][x] = VISIT;
    cout << "진짜 좌표" << x << ", " << y << '\n';

    int xx = 0, yy = 0; // 임시 좌표 생성

    for (int i = 0; i < 4; i++)
    {
        xx = x + move_x[i], yy = y + move_y[i]; // 임시 좌표 초기화

        if (xx < 0 || yy < 0 || yy >= n || xx >= n)
        {
            continue;
        } // 임시 좌표가 행렬을 넘어가면 continue
        else
        {
            if (v[yy][xx] == c) // 같은 색깔이면
            {
                v[yy][xx] = VISIT;         // 한 번 감 표시
                q.push(make_pair(xx, yy)); // 큐에 넣어줌
            }
            else if (v[yy][xx] != c && v[yy][xx] != VISIT && flag == 0)
            {

                if (next_q.size() == 0)
                {
                    cout << "넥스트 큐에 넣은 좌표: " << xx << ", " << yy << ", " << v[yy][xx] << '\n';
                    next_q.push(make_pair(xx, yy));
                }
                flag = 1; // 다음 구역 시작 좌표를 넣어줬단 표시
                //(좌표는 1개만 넣어야돼서 표시를 해준다)
            }
            cout << "임시 현재 좌표 : " << xx << "," << yy << '\n';
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
    q.push(make_pair(0, 0)); // 시작 좌표 큐에 넣기
    c = v[0][0];
    v[0][0] = VISIT;
    DFS(v);
    while (1)
    {
        while (!q.empty())
        {
            cout << "어디서\n";
            DFS(v);
        }
        cnt += 1;

        if (!next_q.empty())
        {
            c = v[next_q.front().second][next_q.front().first];
            cout << "스왑\n";
            swap(q, next_q);
            flag = 0; // ncxt_q에 없다는 표시
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
            cin >> v[i][j]; // 색 입력

    cout << NotColorBlindness(v) << " "; // 비색약인 구역 구하는 함수
    cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == 'G')
                v[i][j] = 'R'; // 초록색을 빨강색으로 통합시키기

    cout << NotColorBlindness(v); // 색약인 구역 구하는 함수
}