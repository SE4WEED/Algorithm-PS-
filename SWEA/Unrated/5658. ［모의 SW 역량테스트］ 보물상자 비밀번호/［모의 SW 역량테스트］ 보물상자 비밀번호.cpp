#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N, K;
string str;
void input()
{
    cin >> N >> K;
    cin >> str;
}
long long hextodec1(char c)
{
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    switch (c)
    {
    case 'A':
        return 10;
        break;
    case 'B':
        return 11;
        break;
    case 'C':
        return 12;
        break;
    case 'D':
        return 13;
        break;
    case 'E':
        return 14;
        break;
    case 'F':
        return 15;
        break;

    default:
        break;
    }
    return -1;
}
long long hextodec(string str)
{
    int len = str.length();
    long long scale = 1;
    long long ret = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        ret += hextodec1(str[i]) * scale;
        // cout << str[i] << " " << hextodec1(str[i]) << " " << hextodec1(str[i]) * scale << " | ";

        scale *= 16;
    }
    // cout << "\n"
    //      << ret << "\n\n";
    return ret;
}
void solve()
{
    vector<long long> ans;
    int len = N / 4;
    for (int i = 0; i < len; i++)
    {
        // i만큼 rotate
        string rot;
        int roti = 0;
        for (int j = i; j < N; j++)
        {
            rot += str[j];
            roti++;
        }
        int stri = 0;
        for (; roti < N; roti++)
        {
            rot += str[stri];
            stri++;
        }
        for (int j = 0; j < 4; j++)
        {
            // j번째 변 숫자.
            string nownum = rot.substr(j * len, len);
            ans.push_back(hextodec(nownum));
        }
    }
    sort(ans.begin(), ans.end());
    int rank = 1;
    if (K == 1)
    {
        cout << ans[ans.size() - 1] << '\n';
        return;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (i == ans.size() - 1)
            continue;
        if (ans[i] != ans[i + 1])
        {
            rank++;
        }
        if (rank == K)
        {
            cout << ans[i] << '\n';
            break;
        }
    }
}
int main()
{

    int tt = 1;
    cin >> tt;
    int rt = tt;
    while (tt--)
    {
        input();
        cout << "#" << rt - tt << " ";
        solve();
    }
    return 0;
}