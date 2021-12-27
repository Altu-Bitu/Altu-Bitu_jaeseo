#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

vector<string> topo(int n, unordered_map<string, int>& indegree, unordered_map<string, vector<string>>& graph, set<string>& item) {
	vector<string> result;
	queue<string> q;

	for (const auto& i : item)
		if (indegree[i] == 0)//진입차수가 0이면
			q.push(i);

	while (!q.empty()) {
		//현재 구매할 수 있는 아이템 중 아직 구매하지 않은 아이템을 모두 찾는다
		vector<string> tmp;
		int n = q.size();
		while (n--) {
			string node = q.front();
			q.pop();

			tmp.push_back(node);
			for (const auto& next_node : graph[node]) {
				indegree[next_node]--;
				if (indegree[next_node] == 0)
					q.push(next_node);
			}
		}

		sort(tmp.begin(), tmp.end());//사전 순으로
		for (const auto& i : tmp)
			result.push_back(i);
	}
	if (result.size() < item.size()) return { "-1" };//아이템을 구매할 수 없을 시
	return result;
}

int main() {
	int n;
	string a, b;

	cin >> n;

	set<string> item;//아이템 저장(중복x)
	unordered_map<string, int> indegree;//정점의 진입차수
	unordered_map<string, vector<string>> graph;//인접그래프

	while (n--) {
		cin >> a >> b;

		item.insert(a);
		item.insert(b);
		indegree[b]++;
		graph[a].push_back(b);
	}

	vector<string> result = topo(n, indegree, graph, item);

	for (const auto& i : result)
		cout << i << '\n';
}