#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int k; // �̹� ������ �ִ� ������ ����
    int n; // �ʿ��� ������ ����
    cin >> k >> n;

    vector<int> v(k); // ���� ����

    int sum = 0; // ��� ���� ���� ����

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int div = sum / n;
    string div_s = to_string(div);
    v.size()
}