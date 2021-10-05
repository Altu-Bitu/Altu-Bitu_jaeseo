#include<iostream>
#include<vector>
#include<deque>
#include<map>

using namespace std;

typedef pair<int, int> ci;//방향좌표
ci dir[4] = { {0,  1},  //우
			 {-1, 0},  //상
			 {0,  -1}, //좌
			 {1,  0} }; //하

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
	deque<ci> snake;//뱀 deque로 구현
	snake.push_front(ci(0, 0));//맨위 맨좌측부터, 오른쪽을 향하여 시작
	board[0][0] = 1;//뱀 길이 처음은 1이니까 하나만 1

	int t = 0, head = 0;//시간, 뱀의 머리 방향

	while (true) {
		t++;//시간 경과

		//뱀의 머리가 위치하게 될 칸
		int nr = snake.front().first + dir[head].first;//머리의 y좌표
		int nc = snake.front().second + dir[head].second;//머리의 x좌표

		//게임 종료 조건 : 벽에 부딪히거나(board 범위를 벗어가거나)
		//자기자신의 몸과 부딪힘(board에서 1인 곳에 향하거나)
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
			break;

		if (board[nr][nc] != 2) {//이동한 칸에 사과가 없으면
			board[snake.back().first][snake.back().second] = 0;//꼬리가 위치했던 칸을 비움
			snake.pop_back();//몸길이를 줄여서
		}
		//사과가 있으면 몸길이 그대로

		//뱀의 이동
		snake.push_front(ci(nr, nc)); //뱀은 몸길이를 늘려서
		board[nr][nc] = 1; //머리를 다음칸에 위치시킴

		//지금 시간에 방향을 변환해야하는 지 확인
		//ex. 15 L 이었으면, 15초일 때 cmd[t]값은 L이니까 걸림
		if (cmd[t] == 'L')//왼쪽 회전
			head = (head + 1) % 4;
		if (cmd[t] == 'D')//오른쪽 회전
			head = (head + 3) % 4;
	}
	return t;
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */

int main() {
	int n, k, row, col, l, x;//보드크기 n, 사과개수k, 사과위치row,col , 방향변환횟수l, 게임시간x
	char c;//방향변환정보c

	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));//보드(사과:2, 뱀:1, 아무것도:0)

	//사과 각각 위치 입력
	while(k--) {
		cin >> row >> col;
		board[row - 1][col - 1] = 2;//사과가 있는 곳은 2
	}

	cin >> l;
	map<int, char> cmd;//x초에 어느 방향
	//뱀의 방향 변환 입력
	while (l--) {
		cin >> x >> c;
		cmd[x] = c;
	}

	//게임
	cout << playGame(n, board, cmd);
}