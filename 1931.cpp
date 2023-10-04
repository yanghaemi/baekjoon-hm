#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n = 0;             // ȸ�� ����
    int most_late = 0;     // ���� ���� ���۽ð�
    int lastest = 9999999; // ���� �̸� ����ð�
    int cnt = 0;           // ȸ�� ����
    int min = 99999999;    // finish[i] - start[i] �� ���� ���� �ڿ���
    int idx = 0;           // �ε���
    cin >> n;

    vector<int> start(n), finish(n); // ȸ�� ���� �ð�, ���� �ð�

    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
        if (most_late < start[i])
            most_late = start[i]; // ���� ���� ���۽ð� ���ϱ�
        if (lastest < finish[i])
            lastest = finish[i];
    }

    while (lastest > most_late) // most_late�� 0 �Ʒ��� ���� ������
    {
        cnt++; // while���� ���ư��� �Ҹ��� ȸ�� ���� �ð��� 0 �Ʒ��� �� ���� �Ҹ��ϱ� cnt++
        for (int i = 0; i < n; i++)
        {
            if (most_late >= finish[i] && finish[i] - start[i] < min && finish[i] > finish[idx])
            {
                min = finish[i] - start[i];
                idx = i;
            } // min, index ���ϱ�
        }
        cout << most_late << '\n';

        most_late = start[idx];
    }

    cout << cnt;
}