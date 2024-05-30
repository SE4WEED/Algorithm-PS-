#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;
int Q;
map<int, int> mp;
long long ans = 0;
void input() {
    cin >> Q;
    long long que, pos, nowmax, now;
    for (int i = 0; i < Q; i++) {
        nowmax = -1;
        cin >> que;
        if (que == 1) {
            cin >> pos;
            for (int kk = pos; kk < pos + 4; kk++) {
                if (mp.find(kk) != mp.end()) {//찾은거
                    now = mp[kk];
                } else {//못찾은거
                    now = 0;
                }
                nowmax = max(now, nowmax);
            }
            nowmax += 1;
            for (int kk = pos; kk < pos + 4; kk++) {
                if (mp.find(kk) != mp.end()) {//찾은거
                    mp[kk] = nowmax;
                } else {//못찾은거
                    mp.insert({ kk,nowmax });
                }
            }
        } else if (que == 2) {
            cin >> pos;
            if (mp.find(pos) != mp.end()) {
                now = mp[pos];
            } else {
                now = 0;
            }
            now += 4;
            if (mp.find(pos) != mp.end()) {
                mp[pos] = now;
            } else {
                mp.insert({pos,now});
            }
        } else if (que == 3) {
            cin >> pos;
            if (mp.find(pos) != mp.end()) {
                cout << mp[pos]<<'\n';
            } else {
                cout << "0\n";
            }
        }
    }
    return;
}
void solve() {


    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cc;
    cc = 1;
    //cin >> cc;
    for (int i = 0; i < cc; i++) {
        input();
        solve();
    }
}