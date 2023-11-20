#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int k; // 이미 가지고 있는 랜선의 개수
    int n; // 필요한 랜선의 개수
    cin >> k >> n;

    vector<int> v(k); // 랜선 길이

    int sum = 0; // 모든 랜선 더한 길이

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int div = sum / n;
    string div_s = to_string(div);
    v.size()
}