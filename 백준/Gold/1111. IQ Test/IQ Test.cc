#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> num;
void input()
{
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
}
void solve()
{
    if (num.size() == 1)
    {
        cout << "A" << '\n';
        return;
    }
    else if (num.size() == 2)
    {
        if (num[0] != num[1])
        {
            cout << "A" << '\n';
        }
        else
        {
            cout << num[0] << '\n';
        }
        return;
    }
    // 1개나 2개가 아닌경우에는
    // 각 숫자 사이의 차이를 저장한다.
    // 정상적인 규칙이 존재한다면,
    // 차이 또한 단계를 거듭할수록 a 배가 되어야 함 ㅇㅇ
    // a배가 아니라면 B를 나타내어주자
    int a, b;
    vector<int> diff;
    for (int i = 0; i < num.size() - 1; i++)
    {
        diff.push_back(num[i + 1] - num[i]);
    }
    // 여기 있는 diff들이 계속해서 a배 되는가가 중요한거
    if (diff[0] == 0 && diff[1] == 0) // 첫 세수가 모두 같은경우지 이건 뒤에수도 다 같아야함
    {
        a = 1;
        b = 0;
    }
    else if (diff[0] == 0 && diff[1] != 0) // 앞 두수는 같은데 뒷수가 다른경우
    // 존재할수가 있냐? 없음
    {
        cout << "B" << '\n';
        return;
    }
    else if (diff[0] != 0 && diff[1] == 0)
    // 앞 두수는 다른데
    // 뒷두수가 같은경우
    //  가능한가?
    // a=0, b=num[1]이면 됨
    {
        a = 0;
        b = num[1];
    }
    else
    // 앞두개, 뒷두개 서로 다른경우 ㅇㅇ
    // 처음이랑 3번은 같을수도야 있긴 하지
    {
        if (abs(diff[0]) > abs(diff[1]))
        {
            cout << "B" << '\n';
            return;
        } // 차이가 줄어든다는것은, a가 정수일 수 없다는것
        a = diff[1] / diff[0];
        b = num[1] - num[0] * a;
    }

    for (int i = 0; i < num.size() - 1; i++)
    {
        // cout << num[i + 1] << " " << num[i] * a + b << "\n";
        if (num[i + 1] != num[i] * a + b)
        {
            cout << "B" << '\n';
            return;
        }
    }

    cout << num[num.size() - 1] * a + b << '\n';
    return;
    // num
    // num*a + b
    // num*a*a + b*a +b
    // num*a*a*a + b*a*a + b*a + b

    // (a-1)num + b
    // (a-1)a(num) + b*a
    // (a-1)aa(num) + b*a*a
}
//-24 12 -6
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