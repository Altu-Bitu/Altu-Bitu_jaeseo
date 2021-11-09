#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e7;//최대 n-1개의 간선을 지나게 됨

//플로이드-워셜
void floydwarshall(int n, vector<vector<bool>>& graph) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (graph[i][k] == true && graph[k][j] == true)//1 3, 3 4 라면
					graph[i][j] = true;//1 4 이기 때문에
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, pre, after, s;//n: 사건의 개수, k: 사건의 전후 관계의 개수

	cin >> n >> k;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));//가로세로 node개수 길이인 2차 정사각형
	for (int i = 1; i <= n; i++)
		graph[i][i] = false;//자기 자신과의 거리(대각선)는 0

	while (k--) {
		cin >> pre >> after;
		graph[pre][after] = true;//역사사건이 연결 된 경우 1
	}

	floydwarshall(n, graph);

	cin >> s;
	while (s--) {
		cin >> pre >> after;

		if (graph[pre][after] == true)//연결 돼있으면
			cout << -1 << '\n';
		else if (graph[after][pre] == true)//연결 돼있으면
			cout << 1 << '\n';
		else //연결 안돼있으면
			cout << 0 << '\n';
	}
}