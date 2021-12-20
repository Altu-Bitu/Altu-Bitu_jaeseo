#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topo(int n, vector<int>& indegree, vector<vector<pair<int, int>>>& graph) {
	vector<int> result;
	queue<int> q;
	vector<int> dp(n + 1, 0);//필요한 부품 개수 저장

	for (int i = 1; i <= n; i++)
		if (!indegree[i])//진입차수가 0이면
			q.push(i);

	dp[n] = 1;//하나의 완제품을 조립하기 위해, 완제품이 필요한 부품 개수 1로 초기화
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;//필요 부품
			int need_num = graph[node][i].second;//필요 부품 개수

			indegree[next_node]--;//연결됐던 필요 부품 1씩 감소
			if (!indegree[next_node])
				q.push(next_node);

			dp[next_node] += dp[node] * need_num;//소요한 개수만큼 더해줌
		}
	}
	return dp;
}

int main() {
	int n, m, x, y, k;//n:완제품번호(1~n), m:관계 수

	cin >> n >> m;

	vector<int> indegree(n + 1, 0);//정점의 진입차수
	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>(0));//인접그래프 +필요한 부품 개수

	while (m--) {
		cin >> x >> y >> k;// X를 만드는데 중간 부품 혹은 기본 부품 Y가 K개 필요하다.

		// 5 1 2 => 5를 만들기 위해 1이 2개 필요하기 때문에,
		indegree[y]++;
		graph[x].emplace_back(y, k);
	}

	vector<int> result = topo(n, indegree, graph);
	for (int i = 1; i <= n; i++)
		if (graph[i].size() == 0)//기본 부품
			cout << i << ' ' << result[i] << '\n';
}