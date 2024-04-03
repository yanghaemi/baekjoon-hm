#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n; // ����̰� ������ �ִ� ���� ī��

    vector<int> v(n);
    vector<int> answer(20000001, 0);
    // -10000000 ���� 10000000 �淡 �� 20000000��ŭ �޸� ����

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        answer[v[i] + 10000000]++;
        // ������ 0~9,999,999 ����, ����� 10,000,001~20,000,000
        // �ش� �ε����� ���� 1 �÷��༭ ������ ������ ǥ���ߴ�.
    }

    int m;
    cin >> m;
    vector<int> v2(m);

    for (int i = 0; i < m; i++)
    {
        cin >> v2[i]; // ����̰� �� �� ������ �ִ� ���� ī������
    }

    for (int i = 0; i < m; i++)
    {
        cout << answer[v2[i] + 10000000] << " ";
    }
}