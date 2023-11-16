#include <iostream>
#include <vector>
using namespace std;
// ���Ḯ��Ʈ ���!
typedef struct node
{
    int data;          // ����
    struct node *next; // ���� ��� ������
} node;                // ���

node *head = (node *)malloc(sizeof(node)); // head ����
int n, k;                                  // �Է� ���
int Copy_n;

void headnode(int data)
{
    head->data = data;
    head->next = NULL;
    return;
}

void insert(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data; // newnode�� ������ �־��ֱ�
    newnode->next = NULL;

    node *cur = head;

    while (cur->next != NULL)
    {
        cur = cur->next; // cur�� ������ ������ �̵�
    }
    cur->next = newnode;

    if (data == n)
    {
        newnode->next = head; // ���� ���Ḯ��Ʈ
                              // ������ ����� next�� head�� ����Ű�� ��
    }
}

void deletenode(int k)
{
    node *cur = head;
    if (k == 1) // k�� 1�� �� ����ó��
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    for (int i = 0; i < k - 2; i++)
    {
        cur = cur->next;
    }
    node *temp = cur->next;
    cur->next = cur->next->next;
    head = cur->next;
    cout << temp->data;
    delete temp;

    Copy_n--;

    return;
}

void getList()
{
    node *cur = head;

    for (int i = 0; i <= Copy_n; i++)
    {
        cout << cur->data << "->";
        cur = cur->next;
    }
    cout << '\n';
}

int main()
{

    int i;
    cin >> n >> k;
    Copy_n = n;
    headnode(1); // 1�� ���� ����
    if (i >= 2)
    {
        for (i = 2; i <= n; i++)
        {
            insert(i); // 2~n���� ���Ḯ��Ʈ ����
        }
    }

    // getList();
    cout << "<";

    for (int j = 0; j < n - 1; j++)
    {
        deletenode(k);
        cout << ", ";
        // getList();
    }
    deletenode(k);
    cout << ">";
}