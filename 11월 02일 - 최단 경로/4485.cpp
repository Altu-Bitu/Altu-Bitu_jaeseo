#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 * 2;//최대 v-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph, int temp) {
	vector<int> dist(vertex * vertex, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;//first: 시작점으로부터의 거리, second: 정점
	//min_으로 구현 greater<>

	//시작 위치 초기화
	dist[start] = temp;
	pq.push({ temp, start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (weight > dist[node])//이미 확인했던 정점
			continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;//연결된 정점
			int next_weight = weight + graph[node][i].second;//시작점으로부터 연결된 정점까지의 거리
			if (dist[next_node] > next_weight)//더 짧은 경로로 갈 수 있다면
			{
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}
	return dist;
}

void setGraph(vector<vector<ci>>& graph, int i, int j, int n, int input) {
	//다음 연결 노드
	//		-n
	//-1		+1
	//		+n
	int cur = i + j;//현재 노드
	if (cur - n >= 0 && cur - n < n * n) graph[cur - n].emplace_back(cur, input);//상
	if (cur + n >= 0 && cur + n < n * n) graph[cur + n].emplace_back(cur, input);//하
	if (cur - 1 >= 0 && cur - 1 < n * n && j != 0) graph[cur - 1].emplace_back(cur, input);//좌
	if (cur + 1 >= 0 && cur + 1 < n * n && j != n - 1) graph[cur + 1].emplace_back(cur, input);//우
}

int main() {
	int n, input, money, temp, total = 0;
	vector<int> result;
	while (1) {
		cin >> n;
		if (n == 0) break;

		vector<vector<ci>> graph(n * n, vector<ci>(0));//인접 리스트

		for (int i = 0; i < n * n; i += n)
			for (int j = 0; j < n; j++) {//0->1->2->...
				cin >> input;//도둑루피 값

				if (i == 0 && j == 0)//다익스트라에서 초기화를 위한 처음 값
					temp = input;

				//다음 연결 노드 세팅
				setGraph(graph, i, j, n, input);
			}

		vector<int> ans = dijkstra(n, 0, graph, temp);

		result.push_back(ans[n * n - 1]);
		total++;
	}

	for (int i = 0; i < total; i++)
		cout << "Problem " << i + 1 << ": " << result[i] << '\n';

}