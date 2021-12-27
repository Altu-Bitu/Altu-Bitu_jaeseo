#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topo(int n, vector<int>& indegree, vector<vector<int>>& graph) {
	vector<int> result;
	queue<int> q;

	//진입차수 0인 정점으로 초기화
	for (int i = 1; i <= n; i++)
		if (!indegree[i])
			q.push(i);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];//연결된 정점
			indegree[next_node]--;//연결된 정점의 차수 1씩 감소

			if (!indegree[next_node])//진입차수 0인 정점
				q.push(next_node);
		}
	}
	if (result.size() != n) return { 0 };//순서를 정하지 못하는 경우는 result에 쌓인 정점 개수가 n이 아닌 경우
	return result;
}

int main() {
	int n, m, w, k;//n: 가수, m: pd
	cin >> n >> m;

	vector<int> indegree(n + 1, 0);//정점의 진입차수
	vector<vector<int>> graph(n + 1, vector<int>(0));//인접그래프

	while (m--) {
		cin >> w;
		vector<int> tmp(w, 0);
		for (int i = 0; i < w; i++) {
			cin >> k;
			tmp[i] = k;
		}
		for (int i = 0; i < w - 1; i++) {
			int first = tmp[i];
			int second = tmp[i + 1];
			indegree[second]++;
			graph[first].push_back(second);
		}
	}
	
	vector<int> result = topo(n, indegree, graph);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';
}