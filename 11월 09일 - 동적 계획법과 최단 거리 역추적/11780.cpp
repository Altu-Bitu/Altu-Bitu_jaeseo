#include<iostream>
#include<vector>
//https://cocoon1787.tistory.com/468

using namespace std;
const int INF = 1e5;//최대 n-1개의 간선을 지나게 됨

//역추적
vector<int> back(int start, int end, vector<vector<int>>& path) {//start,end: 역추적 시작하는 위치 좌표, path: 경로
	vector<int> result(0);//경로 저장
	int x = path[start][end];//시작점

	while (x != 0)//0 은 경로 없음
	{
		result.push_back(x);
		x = path[start][x];//다음 경로
	}
	return result;
}

//플로이드-워셜
void floydwarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& path) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int dist = graph[i][k] + graph[k][j];//중간에 k를 거쳐서 i에서 j로 감
				if (graph[i][j] > dist) {
					graph[i][j] = dist;
					path[i][j] = path[k][j];//k 거치는 경로 저장
				}
			}
}

int main() {
	int n, m, a, b, c;//도시 개수, 버스 개수
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//가로세로 node개수 길이인 2차 정사각형
	vector<vector<int>> path(n * n, vector<int>(n + 1, 0));//경로

	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;//자기 자신과의 거리(대각선)는 0

	while (m--) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);//중복 간선이 들어올 수 있으니까 최솟값을 사용해준다
		path[a][b] = a;//우선 처음 경로 저장
	}

	floydwarshall(n, graph, path);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> result = back(i, j, path);//역추적 결과

			//i에서 j로 갈 수 없는 경우(연결이 안된 경우 또는 i==j)
			if (graph[i][j] == INF || result.empty())
				cout << 0;
			else {//갈 수 있는 경우
				cout << result.size() + 1 << ' ';//최소 비용에 포함된 도시 개수
				for (int i = result.size() - 1; i >= 0; i--)//가는 경로
					cout << result[i] << ' ';
				cout << j << ' ';//도착점
			}
			cout << '\n';
		}
	}
}