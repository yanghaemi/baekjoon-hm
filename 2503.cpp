#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n = 0;     // �������� ���� Ƚ��
    string answer; // �� ���� ����
    string flag;   // �ӽ÷� �� ������ flag ����
    cin >> n;      // ���� �Է� �ޱ�

    vector<string> v(n);   // �������� ���ڸ� ���� ����, �ڸ����� �� �Ŷ� string ����
    vector<int> strike(n); // ��Ʈ����ũ ���� int ����
    vector<int> ball(n);   // �� ���� int ����

    cin >> v[0] >> strike[0] >> ball[0]; // ù ��° ���� ��Ʈ �Է�
    for (int i = 1; i < n - 1; i++)
    {
        cin >> v[i] >> strike[i] >> ball[i]; // �� �Է� �ޱ�
        if (strike[i] <= 3 && strike[i] > 0)
        { // ��Ʈ����ũ�� 1 �̻��̸�
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                    if (answer[k] == v[i][j])
                    {
                        flag[j] = v[i][j];
                        continue; // �̰� �־�ߵǳ�? break�� ��
                    }
            }
        }
        else
        {
        }
        if (ball[i] <= 3 && ball[i] > 0)
        {
            // ���� 1 �̻��̸�
        }
        else
        {
        }
    }

    cout << answer; // �� ���
}