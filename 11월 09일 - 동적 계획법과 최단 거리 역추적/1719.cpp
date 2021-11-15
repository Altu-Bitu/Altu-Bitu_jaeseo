#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e8;

//플로이드-워셜
void floydwarshall(int n, vector<vector<int>>& graph,vector<vector<int>>& path) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int dist = graph[i][k] + graph[k][j];//중간에 k를 거쳐서 i에서 j로 감
				if (graph[i][j] > dist) {
					graph[i][j] = dist;
					path[i][j] = path[i][k];//k 거치는 경로 저장
				}
			}
}

int main() {
	int n, m, s, e, w;//n: 집하장 개수, m: 집하장간 경로 개수

	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//가로세로 node개수 정사각형
	vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));//경로

	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;//자기자신 걸리는 시간(대각선)은 0

	while (m--) {
		cin >> s >> e >> w;//s: s로부터, e: e를 향하고, w: 가중치(걸리는 시간)
		graph[s][e] = w;
		graph[e][s] = w;//양방향
		path[s][e] = e;//우선 처음 경로 저장
		path[e][s] = s;//양방향
	}

	floydwarshall(n, graph, path);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i == j) cout << "- ";
			else cout << path[i][j] << ' ';
		cout << '\n';
	}
}