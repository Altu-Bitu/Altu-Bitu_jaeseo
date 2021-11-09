#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 * 2;//최대 n*n칸을 지나게 됨

//다익스트라
int dijkstra(int n, vector<vector<int>>& board) {
	int dr[4] = { -1, 1, 0, 0 };//상하좌우
	int dc[4] = { 0, 0, -1, 1 };//상하좌우

	vector<vector<int>> dist(n, vector<int>(n, INF));
	priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq;
	//first : 가중치(금액) second.first: 연결된 좌표의 row, second.second : 연결된 좌표의 col
	//min_으로 구현 vector<pair<int, ci>>, greater<>

	//시작 위치 초기화
	dist[0][0] = board[0][0];//0,0부터 시작
	pq.push(make_pair(dist[0][0], make_pair(0, 0)));//우선순위 큐에 처음 시작 지점 넣어두고

	while (!pq.empty()) {
		int weight = pq.top().first;//금액
		int row = pq.top().second.first;//좌표 row
		int col = pq.top().second.second;//좌표 col
		pq.pop();

		if (row == n - 1 && col == n - 1)//n-1, n-1 도착지점 왔으면 최소 금액 리턴
			return weight;

		if (weight > dist[row][col])//이미 확인했던 좌표
			continue;

		for (int i = 0; i < 4; i++) {
			int nr = row + dr[i];//연결된 좌표 row
			int nc = col + dc[i];//연결된 좌표 col

			if (nr < 0 || nr >= n || nc < 0 || nc >= n)//갈 수 있는 범위 벗어난다면
				continue;

			int next_weight = weight + board[nr][nc];//시작점으로부터 연결된 좌표까지의 거리
			if (dist[nr][nc] > next_weight)//더 짧은 경로로 갈 수 있다면
			{
				dist[nr][nc] = next_weight;
				pq.push({ next_weight,{nr,nc} });
			}
		}
	}
}
/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */
int main() {
	int n, total = 0;
	vector<int> result;
	while (1) {
		cin >> n;
		if (n == 0) break;

		vector<vector<int>> board(n, vector<int>(n, 0));//각 좌표가 가중치(금액)인 좌표

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		cout << "Problem " << ++total << ": " << dijkstra(n, board) << '\n';
	}
}