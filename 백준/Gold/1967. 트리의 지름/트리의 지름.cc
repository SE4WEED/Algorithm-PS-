#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<pair<int, int>> edge[10010];//첫번째는 연결, 두번째는 가중치
int arr[10010];//출발점에서 i번째가지의 가중치의 합
int visited[10010];
int _max, top, max_i;
int STACK[10010];
void dfs(int start) {
	int pop, vv, d;
	STACK[++top] = start;
	visited[start] = 1;
	while (top > 0) {
		pop = STACK[top--];
		for (int i = 0; i < edge[pop].size(); i++) {
			vv = edge[pop][i].first;
			d = edge[pop][i].second;
			if (visited[vv] == 0) {
				visited[vv] = 1;
				arr[vv] = arr[pop] + d;
				STACK[++top] = vv;
				if (_max <= arr[vv]) {
					_max = arr[vv];
					max_i = vv;
				}
			}
		}
	}
	return;
}
int main() {
	int num, _s, _e, _pl;
	scanf("%d", &num);
	for (int z = 0; z < num - 1; z++) {
		scanf("%d %d %d", &_s, &_e, &_pl);
		edge[_s].push_back({ _e,_pl });
		edge[_e].push_back({ _s,_pl });
	}
	//1에서 출발해서 최대가 되는놈이 k라면, 
	//다시한번 k에서 출발해서 최대가 되면 max
	_max = 0;
	dfs(1);
	for (int i = 0; i <= num + 1; i++) {
		visited[i] = 0;
		arr[i] = 0;
		STACK[i] = 0;
	}
	top = 0;
	_max = 0;
	dfs(max_i);
	printf("%d\n", _max);
	return 0;
}