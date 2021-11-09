#include<iostream>
#include<vector>
#include<queue>
using namespace std;
				int dist = graph[i][k] + graph[k][j];//중간에 k를 거쳐서 i에서 j로 감

typedef pair<int, int> ci;
const int INF = 1e5; //최대 n-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int n, int start, vector<vector<ci>>& graph) {
	vector<int> dist(n + 1, INF); //정점까지의 최단 시간 저장 배열
	priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터 소요시간, second : 정점
	//min_으로 구현  vector<ci>, greater<>

	//시작 위치 초기화
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int t = pq.top().first;//소요시간
		int node = pq.top().second;//정점
		pq.pop();

		if (t > dist[node]) //이미 더 짧은 경로가 존재한다면
			continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first; //연결된 정점
			int next_t = t + graph[node][i].second; //시작점으로부터 연결된 정점까지의 소요시간
			if (dist[next_node] > next_t) { //더 짧은 경로로 갈 수 있다면
				dist[next_node] = next_t;
				pq.push({ next_t, next_node });
			}
		}
	}
	return dist;
}

/**
 * 1. 각 학생들이 X를 가는 데 걸리는 최단 시간 (i -> x)
 * 2. X에서 다시 돌아오는 데 걸리는 최단 시간 (x -> i)
 *
 * 우선 단방향 그래프이므로 위의 2개 값은 다를 수 있어 따로 구해주어야 함
 * 2번은 시작점이 X인 다익스트라로 구현
 * 1번은 역뱡향 그래프에서 시작점이 X인 다익스트라로 구현 -> 역방향을 다시 원상태로 돌리면 결국 도착점이 X가 됨 (4ms)
*/

int main() {
	int n, m, x, s, e, t;//n : 학생 수(정점 개수), m : 단방향 도로(간선 개수), x : 집에서 가야하는 곳, s: 도로의 시작점, e: 끝점, t: 소요시간
	cin >> n >> m >> x;

	vector<vector<ci>> graph(n + 1, vector<ci>());//그래프
	vector<vector<ci>> rev_graph(n + 1, vector<ci>());//거꾸로 돌아올 그래프

	while (m--) {
		cin >> s >> e >> t;
		graph[s].push_back({ e,t });//단방향
		graph[e].push_back({ s,t });//역방향
	}

	vector<int> dist_go = dijkstra(n, x, rev_graph);//역방향 그래프에서 시작점이 x인 모든 정점의 최단 시간
	vector<int> dist_back = dijkstra(n, x, graph);//(x로 갔다가 돌아오는거니까) 시작점이 x인 모든 정점의 최단 시간

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(dist_go[i] + dist_back[i], ans);//가장 오래 걸리는 소요시간

	cout << ans << '\n';
}