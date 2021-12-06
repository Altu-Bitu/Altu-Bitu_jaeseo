#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {
    int dr[4] = { -1, 1, 0, 0 };//상 하 좌 우
    int dc[4] = { 0, 0, -1, 1 };

    int min_dist = INF;
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    //시작
    visited[shark.first][shark.second] = 1;//방문 체크 & 이동
    q.push(shark);//처음 상어가 갈 곳

    while (!q.empty()) {//q가 빌 때까지
        int row = q.front().first;//현재 row좌표
        int col = q.front().second;//현재 col좌표
        int dist = visited[row][col];//현재 거리
        q.pop();//pop처리

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];//갈 곳 row좌표
            int nc = col + dc[i];//갈 곳 col좌표
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)//범위 벗어났을 시 제어
                continue;

            visited[nr][nc] = visited[row][col] + 1;//우선, 이동 1초 증가(물고기 있든 없든)
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);//먹을 수 있는 물고기의 좌표
                min_dist = visited[nr][nc];//물고기 먹으면서 이동 1초 증가 갱신
                continue;
            }
            q.push({ nr, nc });//갈 곳 q에 push저장
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} };

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬 최소힙으로
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second < p2.second;
        });
    return { min_dist - 1, list[0] };//이동한 시간, 가장 가까운 곳에 있는 물고기의 좌표 리턴
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {
    int ans = 0, size = 2, cnt = 0;//ans: 물고기 잡아먹은 시간, size: 아기상어 크기(처음 2), cnt: 상어가 자라기 전까지 먹은 물고기 총 크기
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);//이동
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        ans += result.first;//이동 시간 더해주기
        cnt++;//물고기 먹음
        if (cnt == size) { //상어 크기 증가 // 자신의 크기와 같은 수의 물고기를 먹어서
            cnt = 0;//0으로 초기화
            size++;//상어 크기 증가
        }

        //상어 이동
        ci pos = result.second;
        board[shark.first][shark.second] = 0;//물고기 먹은 곳은 곳은 빈 칸이 된다.
        shark = pos;
    }
    return ans;//총 시간 리턴
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n;//공간의 크기
    pair<int, int> shark_pos;//상어 위치

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];//공간의 상태
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j);
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}