#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// 우선 아웃은 가장 나중에되면 좋음.-> 각 이닝별로 다른게 문제임
// 1번은 무조건 4번타자니까

// 87654321
// 5만개의 타순 * 50회->
// 최악의 경우에는 아웃되는놈 한놈만 있을 때 -> 27번 회마다
// 5만 * 30 * 50 -> ㄱㅊ을듯?
// 브루트포스 ㄱ
int N;
int hit[55][10];
int order[10];
bool ok[10];
int ans;
int nowAns;
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> hit[i][j];
        }
    }
}
void realSol() {
    // 정해진 순서대로 게임하면됨
    nowAns = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    // 각 루 상태
    int nowO = 1;
    int out = 0;
    int nowHit;
    for (int i = 0; i < N; i++) {
        out = 0;
        first = 0;
        second = 0;
        third = 0;
        while (out < 3) {
            nowHit = hit[i][order[nowO]];  // 현재 회의 순서 타자가 친거
            switch (nowHit) {
                case 1:
                    nowAns += (third);
                    third = second;
                    second = first;
                    first = 1;
                    break;
                case 2:
                    nowAns += (second + third);
                    third = first;
                    second = 1;
                    first = 0;
                    break;
                case 3:
                    nowAns += (first + second + third);
                    third = 1;
                    second = 0;
                    first = 0;
                    break;
                case 4:
                    nowAns += (first + second + third + 1);
                    third = 0;
                    second = 0;
                    first = 0;
                    break;
                default:  // 아웃
                    out++;
                    break;
            }
            nowO++;
            if (nowO >= 10) {
                nowO %= 9;
            }
        }
    }
}

void backt(int num) {  // 몇명 선택했는지 지금까지
    if (num == 9) {
        realSol();
        ans = max(nowAns, ans);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (ok[i]) continue;  // 이미 확정난놈은 빼고
        ok[i] = true;
        order[i] = num + 1;  // 아직 안정해진 타순에는 되는놈 박기
        backt(num + 1);
        ok[i] = false;
    }
}
void solve() {
    for (int i = 1; i <= 9; i++) {
        ok[i] = false;
        order[i] = 0;
    }
    ok[4] = true;
    order[4] = 1;
    // 4번타순에는 1 박아두고
    backt(1);
    cout << ans << '\n';
}
int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        input();
        solve();
    }
    return 0;
}
