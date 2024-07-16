#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> arr;
int numCheck[400010];
void input()
{
    cin >> N;
    int tmpN = N;
    int tmp;
    while (tmpN--)
    {
        cin >> tmp;
        arr.push_back(tmp);
        numCheck[tmp] = 1;
    }
}
void solve()
{
    // 일단 너무 크면 안되는거지
    // 예를들어 2개 넣었는데 최소가 4일수는 없지 아무리 채워넣어도 3이 최소지
    // 그거보다 작은거는 다 들어있어야함
    // 주어진 수가 non-decreasing아니면 불가
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "No\n";
            return;
        }
    }
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (i + 2 < arr[i])
        {
            cout << "No\n";
            return;
        }
    }
    if (arr[N - 1] != N + 1)
    {
        cout << "No\n";
        return;
    }
    // 마킹 안된거중에 최소들을 쭉쭉 출력해주고
    // 숫자 바뀌게되면 바뀐놈을 그 다음에 바로 출력해주기
    cout << "Yes\n";
    int idx = 1;
    while (numCheck[idx] == 1)
        idx++;
    // 넘쳌이 1 아닌최소에서 멈추는거지 이럼
    int cur = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (cur != arr[i])
        {
            cout << cur << ' ';
            numCheck[cur] = 0;
        }
        else
        {
            cout << idx << ' ';
            idx++;
            while (numCheck[idx] == 1)
                idx++;
        }

        cur = arr[i];
    }
    cout << '\n';
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