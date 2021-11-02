#include<iostream>
#include<queue>
using namespace std;
const int MAX = 100000 + 1;
queue<int> q;//갈 수 있는 위치 큐
bool visited[MAX] = { false };//방문 확인 배열

void findPos(int pos) {
	//위치 케이스 : X+1, X-1, X*2
	int pcase[] = { 1,-1,2 };

	for (int i = 0; i < 3; i++) {
		int np;//갈 수 있는 위치
		if (i != 2) np = pos + pcase[i];//케이스 1,2
		else np = pos * pcase[i];//케이스 3

		if (np <= MAX && np >= 0 && !visited[np]) {//갈 수 있는 위치 범위, 방문 안한 곳
			q.push(np);
			visited[np] = true;//방문 체크
		}
	}
}

int bfs(int n, int k) {
	q.push(n);//처음 위치
	visited[n] = true;
	int time = 0;//초

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int pos = q.front();//현재 탐색하려는 위치
			q.pop();

			if (pos == k)//목적지 달성
				return time;

			findPos(pos);
		}
		time++;
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);
}