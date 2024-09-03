#include <string.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
char str[200010];
int sum[26][200010];
int q;
void input() {
    cin >> str;
    cin >> q;
}
void solve() {
    int l = strlen(str);

    for (int i = 0; i < l; i++) {
        sum[str[i] - 'a'][i] += 1;
        if (i == 0) {
            continue;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            sum[c - 'a'][i] += sum[c - 'a'][i - 1];
        }
    }
    char c;
    int s, e;
    for (int i = 0; i < q; i++) {
        cin >> c >> s >> e;
        if (s == 0) {
            cout << sum[c - 'a'][e] << '\n';
            continue;
        }
        cout << sum[c - 'a'][e] - sum[c - 'a'][s - 1] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        input();
        solve();
    }
    return 0;
}