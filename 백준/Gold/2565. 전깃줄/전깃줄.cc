#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define iint pair<int, int>
using namespace std;
int N;  // 전깃줄 개수
vector<iint> input_vector;
vector<iint> ansvector;
vector<int> ind;
bool cmp(iint a, iint b) { return a.first < b.first; }
bool cmp2(iint a, iint b) { return a.second < b.second; }
void input() {
    cin >> N;
    int i = 0;
    int a, b;
    while (i < N) {
        cin >> a >> b;
        input_vector.push_back({a, b});
        i++;
    }
    sort(input_vector.begin(), input_vector.end(), cmp);
    return;
}
void solve() {
    // LIS를 찾아야지?
    // LIS에 못들어간놈들을 지우면 됨.
    ansvector.push_back(input_vector[0]);
    ind.push_back(0);
    for (int i = 1; i < N; i++) {
        if (ansvector.back().second < input_vector[i].second) {
            ansvector.push_back(input_vector[i]);
            ind.push_back(ansvector.size()-1);
        } else {
            auto lb = lower_bound(ansvector.begin(), ansvector.end(), input_vector[i], cmp2) - ansvector.begin();
            ansvector[lb] = input_vector[i];
            ind.push_back(lb);
        }
    }
    cout << N - ansvector.size() << '\n';
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cc;
    cc = 1;
    // cin >> cc;
    for (int i = 0; i < cc; i++) {
        input();
        solve();
    }
}