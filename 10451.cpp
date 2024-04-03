#include <iostream>
#include <vector>
using namespace std;

void Graph(int num) // num : ���� ũ��
{
    int cnt = 0;

    vector<int> v(num + 1);
    vector<int> visit(num + 1, 0); // �湮 �߳� Ȯ���ϴ� ����
    for (int i = 1; i <= num; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= num; i++)
    {
        // for������ ������� �׷��� ������� ���󰡱�
        if (visit[i] == 0) // visit �� �� �͸� ����
        {
            int j = v[i];
            visit[i] = 1;
            while (1)
            {
                visit[j] = 1;
                if (j == i) // ���ٰ� ���� �� ������ ���� ����Ŭ�̴�
                {
                    cnt++;
                    break;
                }
                j = v[j]; // ���� �� �� ������ ��� �׷��� ���� ����
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;

        Graph(num);
    }
}