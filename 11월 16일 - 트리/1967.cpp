//풀이참고 : https://codingwell.tistory.com/61
#include<iostream>
#include<vector>
using namespace std;

const int SIZE = 10000 + 1;
vector<pair<int, int>> tree[SIZE];//first: 자식, second: 간선 가중치(길이)
vector<bool> visited;
int dia = 0, far = 0;//지름, 가장 멀리있는 점

void dfs(int n, int len) {
	if (visited[n])//방문했으면 리턴
		return;

	//처음방문
	visited[n] = true;

	if (dia < len) far = n;	//가장 멀리있는 점 갱신
	dia = max(dia, len);	//지름 갱신

	for (int i = 0; i < tree[n].size(); i++) {
		int child = tree[n][i].first;//자식
		int weight = len + tree[n][i].second;//길이 = 현재 길이 + 자식 가중치

		dfs(child, weight);
	}
}

int main() {
	int n, a, b, c;

	cin >> n;
	visited.assign(n + 1, false);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	//가장 끝 점에 있는 두 지점이 지름이기 때문에
	//첫 노드에서 가장 멀리 있는 점과 그 점에서 가장 멀리 있는 점의 거리를 구하기

	dfs(1, 0);//가장 멀리있는 점 구하기(첫 노드는 항상 1, 처음 지름은 0)

	dia = 0;
	visited.assign(n + 1, false);

	dfs(far, 0);//지름 구하기(제일 멀리있는 점, 처음 지름은 0)

	cout << dia << '\n';
}