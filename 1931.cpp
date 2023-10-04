#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n = 0;             // 회의 개수
    int most_late = 0;     // 제일 늦은 시작시간
    int lastest = 9999999; // 제일 이른 종료시간
    int cnt = 0;           // 회의 개수
    int min = 99999999;    // finish[i] - start[i] 중 가장 작은 자연수
    int idx = 0;           // 인덱스
    cin >> n;

    vector<int> start(n), finish(n); // 회의 시작 시간, 종료 시간

    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
        if (most_late < start[i])
            most_late = start[i]; // 가장 늦은 시작시간 구하기
        if (lastest < finish[i])
            lastest = finish[i];
    }

    while (lastest > most_late) // most_late가 0 아래로 가기 전까지
    {
        cnt++; // while문이 돌아갔단 소리는 회의 시작 시간이 0 아래로 안 갔단 소리니까 cnt++
        for (int i = 0; i < n; i++)
        {
            if (most_late >= finish[i] && finish[i] - start[i] < min && finish[i] > finish[idx])
            {
                min = finish[i] - start[i];
                idx = i;
            } // min, index 구하기
        }
        cout << most_late << '\n';

        most_late = start[idx];
    }

    cout << cnt;
}