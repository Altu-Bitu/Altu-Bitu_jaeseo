#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;
int dr[2] = { 1, 0 };// 오른쪽, 아래
int dc[2] = { 0, 1 };// 오른쪽, 아래

int cntCandy(int n, int row, int col, int dir) {
    int ans = 0, cnt = 0;//ans: 먹을 수 있는 최대 개수
    char cur = ' ';
    for (int i = 0; i < n; i++) {
        if (cur == board[row][col]) { //연속된 사탕
            cnt++;
            ans = max(ans, cnt); // 가장 긴 연속 부분
        }
        else { //불연속
            cnt = 1;
            cur = board[row][col];// 불연속된 색으로 갱신
        }
        //같은 열 또는 행에서 다음으로
        row += dr[dir];
        col += dc[dir];
    }
    return ans;
}

int findCandy(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cntCandy(n, 0, i, 0)); //같은 열에 대해
        ans = max(ans, cntCandy(n, i, 0, 1)); //같은 행에 대해
    }
    return ans;
}

int switchCandy(int n, int row, int col, char candy) {
    int ans = 0;
    for (int i = 0; i < 2; i++) { //오른쪽, 아래에 있는 사탕과 바꿔보기
        int nr = row + dr[i], nc = col + dc[i];
        if (nr < n && nc < n && candy != board[nr][nc]) {//사탕의 색이 다른 인접한 두 칸을 고른다.
            swap(board[row][col], board[nr][nc]);// 고른 칸에 들어있는 사탕을 서로 교환한다.
            ans = max(ans, findCandy(n));// 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.
            swap(board[row][col], board[nr][nc]);// 다시 원위치로
        }
    }
    return ans;
}

/**
 * 입력 범위가 크지 않으므로 바꿀 수 있는 사탕을 모두 바꿔보며 먹을 수 있는 사탕 계산
 * 오른쪽, 아래에 있는 사탕과만 바꿔도 모든 경우 고려 가능(왼쪽, 위 고려 X)
 *
 * 1. 사탕의 색이 다른 사탕만 교환하기
 * 2. 각 열, 행이 모두 같은 사탕일 때 사탕의 개수가 갱신되지 않도록 주의 (ans 갱신을 line 18~21에서 하는 경우)
 */
int main() {
    int n, max_candy = 0;

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' '));//보드 nxn 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];// 사탕 색 입력

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j]));// 먹을 수 있는 최대개수
    }

    //출력
    cout << max_candy;
}