#include<iostream>
#include<queue>
using namespace std;
const int SIZE = 101;
struct Pos {//위치 정보
	int y, x;
};
struct Dir {//방향 전환 정보
	int t;// t초가 끝난 뒤에
	char c;//왼쪽:L 오른쪽: D 으로 90도 회전한다.
};
struct Joint {//뱀의 꺾인 부분
	int y, x, d;
};

//방향 : 0 왼쪽, 1 위, 2 오른쪽, 3 아래
int dy[4] = { 0,-1,0,1 }; //y방향으로 갔을 때
int dx[4] = { -1,0,1,0 }; //x방향으로 갔을 때
queue<Dir> direction;//방향전환
int board[SIZE][SIZE];//보드 배열

int n, k;//보드크기n, 사과개수k
int y, x;//행y , 열x
int l, t;//뱀의 방향 변환 횟수l, 시간t
char c; //방향c

bool isEnd(int y, int x) {
	if (y > n || y <= 0 || x <= 0 || x > n) return true;//벽에 부딪혔을 때
	if (board[y][x]==1) return true;//자기자신 몸한테 부딪혔을 때
	return false;
}

int turnRight(int d) {//오른쪽으로 회전
	d++;
	return d >= 4 ? d - 4 : d;
}
int turnLeft(int d) {//왼쪽으로 회전
	d--;
	return d < 0 ? d + 4 : d;
}

void tailPos(Pos &tail, int& tail_dir) {//꼬리 이동
	board[tail.y][tail.x] = 0;
	tail.y += dy[tail_dir];
	tail.x += dx[tail_dir];
}

int resultTime() {
	int t = 0;//결과 시간
	int head_dir = 2, tail_dir = 2;//뱀은 처음에 오른쪽을 향한다.
	Pos head = { 1,1 }, tail = { 1,1 };//처음에 맨위 맨좌측에 위치
	queue<Joint> joint;//꺾인 부분 저장
	board[1][1] = 1; //왼쪽 위 시작(뱀 머리 있는 곳은 1)

	while (true) {
		t++;//시간 경과

		//몸길이를 늘려 머리 이동
		head.y += dy[head_dir];
		head.x += dx[head_dir];

		//머리가 부딪힌 경우 종료;
		if (isEnd(head.y, head.x))
			break;

		// 이동한 곳에 사과 없으면 꼬리 한 칸 앞으로
		if (board[head.y][head.x] != 2)
			tailPos(tail, tail_dir);
		// 이동한 곳에 사과 있으면 꼬리변화 없음
		board[head.y][head.x] = 1;//머리가 있는 곳은 1로

		// 머리 방향 전환
		if (!direction.empty() && t == direction.front().t) {//방향 남았고, 경과시간 올바를 때
			if (direction.front().c == 'L')//방향이 왼쪽
				head_dir = turnLeft(head_dir);
			else//오른쪽
				head_dir = turnRight(head_dir);

			joint.push({ head.y, head.x, head_dir });//꺾인 부분
			direction.pop();
		}

		//꼬리가 뱀의 꺾인 부분에 도달했을 시, 꼬리 방향 전환
		if (!joint.empty() && tail.y == joint.front().y && tail.x == joint.front().x) {
			tail_dir = joint.front().d;
			joint.pop();
		}
	}
	return t;
}

int main() {
	cin >> n >> k;
	//사과위치 입력
	while (k--) {
		cin >> y >> x;
		board[y][x] = 2;//뱀이 있는 곳은 2
	}

	cin >> l;
	//뱀의 방향 변환 입력
	while (l--) {
		cin >> t >> c;
		direction.push({ t,c });
	}

	//게임이 몇 초에 끝나는 지
	cout << resultTime();
}