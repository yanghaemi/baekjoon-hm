#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &v1, const pair<int, int> &v2)
{
    if (v1.second == v2.second)
    {
        return v1.first < v2.first; // 종료시간이 같으면 시작시간이 이른 쪽을 앞으로
    }
    return v1.second < v2.second; // 종료시간이 이른 시간 순대로
}

int main()
{
    int n = 0;
    int _start = 99999999;
    int _finish = 0;
    int cnt = 1;
    int idx = 0;
    cin >> n;

    if (n == 0)
    {
        cout << "0";
        return 0;
    }

    vector<pair<int, int>> v(n); // 회의 시작, 종료 시간 입력 받기

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int min = 999;

    sort(v.begin(), v.end(), compare); // 정렬

    int flag = 0;

    for (;;)
    {
        flag = 0;

        for (int i = idx + 1; i < n; i++)
        {

            if (v[i].first == v[idx].second)
            {
                idx = i;
                cnt++;
                // cout << "(" << v[idx].first << " " << v[idx].second << ")" << '\n';
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            v[idx].second++;
        }
        if (v[idx].second >= v[n - 1].second)
        {
            break;
        }
    }
    cout << cnt;

    return 0;
}