#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>> leftPq;
priority_queue<int, vector<int>, greater<int>> rightPq;
void solve()
{
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        // i : 지금까지 넣은 개수
        if (i == 0)
        {
            leftPq.push(tmp);
            // 처음이면 왼쪽에 넣고 일단
        }
        else if (i % 2 == 0)
        { // 짝수 -> 무조건 왼쪽이 늘어나야
            // 2개 이미 들어있는 경우부터니까 양쪽에 하나씩은 어차피 있음 ㅇㅇ
            if (rightPq.top() < tmp)
            { // 오른쪽에 가야하는 놈이면
                leftPq.push(rightPq.top());
                rightPq.pop();
                rightPq.push(tmp);
            }
            else
            {
                leftPq.push(tmp);
            }
        }
        else
        { // 홀수 -> 왼쪽이 하나 더 많은상태. -> 오른쪽이 늘어나야
            if (leftPq.top() > tmp)
            {
                rightPq.push(leftPq.top());
                leftPq.pop();
                leftPq.push(tmp);
            }
            else
            {
                rightPq.push(tmp);
            }
        }
        cout << leftPq.top() << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}