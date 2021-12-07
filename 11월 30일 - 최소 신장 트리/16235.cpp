#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;
typedef tuple<int, int, int> tp;

queue<tp> spring(matrix& land, deque<tp>& tree, queue<pair<int, int>>& breeding_tree) {
    //하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
    //각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음

    queue<tp> dead_tree;//죽은 나무
    int size = tree.size();//현재 남은 나무 개수
    while (size--) { //모든 나무 검사
        int age = get<0>(tree.front()); //나이
        int row = get<1>(tree.front()); //행
        int col = get<2>(tree.front()); //열
        tree.pop_front();//pop하여 삭제

        if (land[row][col] < age) { //자신의 나이만큼 양분을 먹을 수 없다면
            dead_tree.push({ age, row, col });//죽은 나무로 저장
            continue;
        }

        // 자신의 나이만큼 양분을 먹을 수 있다면
        land[row][col] -= age; // 땅에 있는 양분을 나이만큼 먹고
        tree.emplace_back(age + 1, row, col); // 나이 한 살 증가한 나무로 저장
        if ((age + 1) % 5 == 0) // 나이 한 살 증가한 후 나이가 5의 배수라면
            breeding_tree.push({ row, col });//번식하는 나무로 저장
    }
    return dead_tree;
}

void summer(queue<tp>& dead_tree, matrix& land) {
    // 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)

    while (!dead_tree.empty()) { // 죽은 나무들 모두 검사
        int age = get<0>(dead_tree.front()); //죽은 나무의 나이
        int row = get<1>(dead_tree.front()); //죽은 나무의 행 위치
        int col = get<2>(dead_tree.front()); //죽은 나무의 열 위치
        dead_tree.pop();//pop하여 삭제
        land[row][col] += (age / 2); // 양분으로 변함
    }
}

void fall(int n, deque<tp>& tree, queue<pair<int, int>>& breeding_tree) {
    // 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김

    // (r-1, c), (r+1, c), (r, c-1), (r, c+1), (r-1, c-1), (r-1, c+1), (r+1, c-1), (r+1, c+1)
    int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    while (!breeding_tree.empty()) { // 번식할 나무 모두 검사
        int row = breeding_tree.front().first; //번식할 나무의 행
        int col = breeding_tree.front().second; //번식할 나무의 열
        breeding_tree.pop();//pop하여 삭제

        for (int j = 0; j < 8; j++) { // 인접한 8개 칸에
            int nr = row + dr[j];
            int nc = col + dc[j];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //범위 벗어날 시 continue
                continue;
            tree.push_front({ 1, nr, nc }); // 새로 생긴 나이가 1인 나무
        }
    }
}

void winter(int n, matrix& a, matrix& land) {
    // 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            land[i][j] += a[i][j]; // 입력해놨던 A[r][c]만큼 땅에 양분 추가
}

/**
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * a: 로봇(S2D2)가 겨울에 주는 양분의 양
 * land: 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */

int main() {
    int n, m, k, x, y, z;//n: 땅 크기, m: 나무개수, k: k년

    //입력
    cin >> n >> m >> k;
    matrix a(n, vector<int>(n, 0));
    matrix land(n, vector<int>(n, 5)); //처음 양분 모든 칸에 5
    queue<pair<int, int>> breeding_tree; //번식할 트리
    deque<tp> tree;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];// 로봇이 겨울에 주는 양분의 양 저장
    while (m--) {
        cin >> x >> y >> z;//x,y: 나무 위치, z : 나무의 나이
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    sort(tree.begin(), tree.end()); //어린 나이 순으로 정렬
    while (k--) {
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land);//여름
        fall(n, tree, breeding_tree);//가을
        winter(n, a, land);//겨울
    }

    //출력
    cout << tree.size();//k년이 지나고 살아남은 나무의 수
}