#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int Min(int a, int b) { return a > b ? b : a; } // ���� �� ��ȯ�ϴ� �Լ�

int button[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int min_num = 999999;
int n;

void BF(string s)
{
    for (int i = 0; i < 10; i++)
    {
        if (button[i])
        {
            string str_num = s + to_string(i);                                 // s �ڿ� ���� ��ư �ٿ��ֱ�
            min_num = Min(min_num, abs(n - stoi(str_num)) + str_num.length()); // str_num.length()�� ��ư Ƚ��,
                                                                               // n-stoi(str_num)�� +/-��ư Ƚ��

            if (str_num.length() < 6) // 0<n<500,000�̴ϱ� �ִ� ��ư�� 6�� ���� �Ŵϱ�
                BF(str_num);
        }
    }
}

int main()
{

    cin >> n; // ��ȣ �Է�

    int m = 0;
    cin >> m; // ���峭 ��ư ����

    min_num = Min(min_num, abs(100 - n)); // min_num�� 100�� n ���� ���� �ֱ�
    int k;                                // ���峭 ��ư�� ������ �ӽ� ����
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        button[k] = 0; // ���峭 �Ÿ� 0���� �ʱ�ȭ
    }

    if (m < 10) // ���峭 ��ư�� �ϳ��� ������
        BF("");

    cout << min_num;
}