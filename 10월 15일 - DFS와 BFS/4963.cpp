#include<iostream>
#include<queue>
using namespace std;

vector<vector<int>> island;//지도
vector<vector<bool>> visited;//방문확인
queue<pair<int, int>> q;//first : y, second : x
	//방향 케이스
	//(y-1,x-1) (y-1, x ) (y-1,x+1)
	//( y ,x-1) ( y , x ) ( y ,x+1)
	//(y+1,x-1) (y+1, x ) (y+1,x+1)
//우부터 반시계방향으로
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void bfs(int w, int h) {
	while (!q.empty()) {
		int y = q.front().first;//현재 탐색하려는 노드 좌표
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int posy = y + dy[i];//다음으로 이동할 좌표
			int posx = x + dx[i];
			if (0 <= posx && posx < w && 0 <= posy && posy < h) {
				if (island[posy][posx] && !visited[posy][posx]) {
					q.push(make_pair(posy, posx));
					visited[posy][posx] = true;
				}
			}
		}
	}
}

int islandNum(int w, int h) {
	int num = 0;//섬 개수
	visited.assign(h, vector<bool>(w, false));

	//지도를 bfs로 탐색
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (island[i][j] && !visited[i][j]) {//방문 안한 곳, 실제 섬
				q.push(make_pair(i, j));
				visited[i][j] = true;//방문체크
				bfs(w, h);
				num++;
			}
	return num;
}

int main() {
	int w, h;//w :너비, h: 높이

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;//0 0이면 종료

		island.assign(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> island[i][j];

		cout << islandNum(w, h) << '\n';//섬개수 구하기
	}
}