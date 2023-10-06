#include <iostream>
#include <istream>
#include <string>
#include <vector>
using namespace std;

vector<char> stack;
int top = -1;

void push(char c)
{
    stack.push_back(c);
    top++;
}

int main()
{
    string str;
    getline(cin, str);

    int flag = 0;
    char c;

    for (int i = 0; i < str.length(); i++)
    {
        // cout << "flag : " << flag << ", str[" << i << "] : " << str[i] << '\n';
        if (str[i] != '<' && flag == 0 && str[i] != ' ')
        {
            push(str[i]);
        }
        if (str[i + 1] == '<' || str[i + 1] == ' ') //<�� ���� ������ ���� ��� ������ ���
            while (top != -1)
            {
                cout << stack.back();
                stack.pop_back(); // pop_back�Լ� ��ü�� void�� cout<<stack.pop_back()�� �� ��.
                top--;
            }
        if (str[i] == ' ') // ���� ���
            cout << str[i];
        if (str[i] == '<')
        {
            flag = 1;
            cout << '<';

            for (int j = i + 1; str[j - 1] != '>'; j++)
            {
                cout << str[j];
                if (str[j] == '>') // �±װ� �����ٴ� ���� flag ==0
                {
                    flag = 0;
                    i = j;
                }
            }
        }
    }
    while (top != -1)
    {
        cout << stack.back();
        stack.pop_back();
        top--;
    }
    return 0;
}