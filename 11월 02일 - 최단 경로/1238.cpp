#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e7;//최대 n-1개의 간선을 지나게 됨

//플로이드-워셜
void floydwarshall(int n, vector<vector<int>>& graph) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int dist = graph[i][k] + graph[k][j];//중간에 k를 거쳐서 i에서 j로 감
				graph[i][j] = min(graph[i][j], dist);
			}
}

int main() {
	int n, m, x, s, e, t;//n : 학생 수(정점 개수), m : 단방향 도로(간선 개수), x : 집에서 가야하는 곳, s: 도로의 시작점, e: 끝점, t: 소요시간
	cin >> n >> m >> x;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//가로세로 node개수 길이인 2차 정사각형

	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;//자기 자신과의 거리(대각선)는 0

	while (m--) {
		cin >> s >> e >> t;
		graph[s][e] = t;//중복간선이 없기 때문에 min처리 안해도 됨
	}

	floydwarshall(n, graph);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < graph[i][x] + graph[x][i])
			ans = graph[i][x] + graph[x][i];

	cout << ans;
}