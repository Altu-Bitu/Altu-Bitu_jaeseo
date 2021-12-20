#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;
//      -1,0
//0,-1          0,1
//       1,0
int dr[4] = { -1, 1, 0, 0 };//row좌표 상 하 좌 우
int dc[4] = { 0, 0, -1, 1 };//col좌표 상 하 좌 우

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col];//cnt: 붙이는 횟수, min_block: 값이 가장 작은 블럭, sum: 블럭 합

    //가운데에 상하좌우로 블럭을 4개 붙이는 반복문
    for (int i = 0; i < 4; i++) {
        //상하좌우에 붙일 수 있는지 확인하기 위한 좌표
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc];// 범위에 들어오면 붙이기
        cnt++;
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;//그대로 리턴
    //+ 인 경우는 상하좌우 중에 가장 값이 작은 블럭 하나 뺴주고 리턴
    return sum - min_block;
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum);//합이 더 큰 걸로 갱신 후 리턴
        return;
    }
    //깊이가 4인 블럭이니까 4번 반복문으로 블럭붙이기
    for (int i = 0; i < 4; i++) {
        //상하좌우에 붙일 수 있는지 확인하기 위한 좌표
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;
        int save = board[nr][nc];//방문체크를 위해 값은 우선 저장해놓고
        board[nr][nc] = 0;//방문체크
        backtracking(nr, nc, cnt + 1, sum + save);//블럭 붙여나가면서, 붙인 횟수 늘려가며 재귀
        board[nr][nc] = save;//다시 넣어주기
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m;//n: 종이 세로크기, m: 종이 가로크기
    board.assign(n, vector<int>(m, 0));//n개 줄에 종이에 쓸 수를 위한 할당
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];//종이에 수 쓰기
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; //방문체크를 위해 값은 우선 저장해놓고

            board[i][j] = 0;//방문체크
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save;//다시 넣어주기
        }
    }

    //출력
    cout << ans;
}