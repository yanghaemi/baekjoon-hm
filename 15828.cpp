#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 15828 : Router
int main()
{
    int n; // ����� ���ο� �����ϴ� ������ ũ��

    cin >> n;

    vector<int> v;
    queue<int> q;

    int cnt = 0;
    int num;

    while (1)
    {
        cin >> num;

        if (num == -1)
            break;

        v.push_back(num); // ���Ϳ� push back���ֱ�

        cnt++;

        if (cnt >= 200000)
        {
            break;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0 && q.size() < n)
            q.push(v[i]);
        else if (v[i] == 0)
            q.pop();
    }

    if (!q.empty())
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    else
        cout << "empty";
}