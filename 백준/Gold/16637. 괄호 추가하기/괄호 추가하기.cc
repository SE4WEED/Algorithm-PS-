#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
using namespace std;
char str[30];
int N;
int op;
int p;
int priorityPos[30]; // 우선순위를 받은놈의 위치를 저장
int okOp[30];        // 해당위치 오퍼레이션이 오케이인지,
int ans;
bool firstAns;
void input()
{
    cin >> N;
    cin >> str;
}
void realSolve(int fi)
{
    // 이제 연산을 하면 되는데
    // priorityPos[1,2,...,fi]에 있는놈들을 우선
    //+ 0 으로 바꿔버리고
    // 순차계산을 하자
    char tmp[30];
    int num[30];
    strcpy(tmp, str);
    for (int i = 0; i < N; i += 2)
    {
        num[i] = tmp[i] - '0';
    }
    for (int i = 1; i <= fi; i++)
    {
        switch (tmp[priorityPos[i]])
        {
        case '+':
            num[priorityPos[i] - 1] += num[priorityPos[i] + 1];
            break;
        case '-':
            num[priorityPos[i] - 1] -= num[priorityPos[i] + 1];
            break;
        case '*':
            num[priorityPos[i] - 1] *= num[priorityPos[i] + 1];
            break;

        default:
            break;
        }
        tmp[priorityPos[i]] = '+';
        num[priorityPos[i] + 1] = 0;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     if (i % 2)
    //     {
    //         cout << tmp[i];
    //     }
    //     else
    //     {
    //         cout << num[i];
    //     }
    // }
    int tmpans = num[0];
    char curOp;
    for (int i = 1; i < N; i++)
    {
        if (i % 2)
        { // 연산자
            curOp = tmp[i];
            // cout << tmp[i] << '\n';
        }
        else
        { // 숫자
            int nowNum = num[i];
            switch (curOp)
            {
            case '+':
                tmpans += nowNum;
                break;
            case '-':
                tmpans -= nowNum;
                break;
            case '*':
                tmpans *= nowNum;
                break;

            default:
                cout << i << " << now i ";
                cout << curOp << " is ";
                cout << "invalid op\n";
                exit(0);
                break;
            }
        }
    }
    // cout << " " << tmpans << "\n";
    if (firstAns)
    {
        firstAns = false;
        ans = tmpans;
    }
    else
    {
        ans = max(ans, tmpans);
    }
    return;
}
void init()
{
    for (int i = 0; i <= 29; i++)
    {
        priorityPos[i] = 0;
        okOp[i] = false;
    }
    priorityPos[0] = -1;
}
void backt(int last, int num)
{
    if (last == num)
    {
        realSolve(last);
    }
    for (int i = priorityPos[num] + 2; i < N; i += 2)
    {
        if (okOp[i])
            continue;
        if (i - 2 > 0)
        {
            if (okOp[i - 2]) // 직전놈이 선택되었다면 불가 ㅇㅇ
                continue;
        }
        okOp[i] = true;
        priorityPos[num + 1] = i;
        backt(last, num + 1);
        okOp[i] = false;
    }
    return;
}
void solve()
{
    // 이제 최대로 묶을 괄호를 찾는데,
    // 연산자를 기준으로 찾자.
    // 연산자는 N/2개 존재함.
    op = N / 2;
    // 연산자가 op개 있을 때,
    // 괄호는 최대 (op+1)/2 개
    firstAns = true;
    p = (op + 1) / 2;
    for (int last = 0; last <= p; last++)
    {
        init();
        backt(last, 0);
    }
    cout << ans << '\n';
}
int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}