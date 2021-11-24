#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    int step = 0, ans = 0;//ans:: 청소하는 칸 개수
    while (true) {
        //현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터
        if (board[r][c] == 0) {//청소하지 않은 공간
            board[r][c] = 2;//청소한 공간으로 갱신
            ans++;
        }

        if (step == 4) {//네 방향 모두 청소가 이미 되었을 경우
            //바라보는 방향 유지한 채로 한 칸 후진했을 때,
            if (board[r - dr[d]][c - dc[d]] == 1)//벽일 경우
                return ans;//작동 멈추고, 답 리턴
            //벽 아닐 땐
            r -= dr[d];//한 칸 후진
            c -= dc[d];
            step = 0;//0으로 초기화하여 다시 현재 위치 청소시작
        }
        else {//아직 모든 방향 청소 안된 경우
            d = (d + 3) % 4;//네 방향을 돌며
            if (board[r + dr[d]][c + dc[d]]) {//청소할 공간이 없으면
                step++;//회전
                continue;
            }
            //그 방향으로 회전한 상태로,
            r += dr[d];//한 칸 전진
            c += dc[d];
            step = 0;//0으로 초기화하여 다시 현재 위치 청소시작
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;//n: 세로크기, m: 가로크기, r,c: 로봇청소기가 있는 row좌표, col좌표, d: 바라보는 방향
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];//장소 상태
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}