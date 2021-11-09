#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 8;

map<string, int> direction = { {"L",  0},  //상
                              {"R",  1},  //하
                              {"B",  2},  //좌
                              {"T",  3},  //우
                              {"LT", 4},  //우상향
                              {"LB", 5},  //좌상향
                              {"RT", 6},  //우하향
                              {"RB", 7} }; //좌하향

string pointToString(ci point) {
    string ans;
    ans = (point.first + 'A');//마지막 좌표 0, 0 => A
    ans += (point.second + '1');// => 1
    return ans;//=>A1
}

pair<ci, ci> moveKing(string move, ci point_k, ci point_r) {
    //상, 하, 좌, 우, 우상향, 좌상향, 우하향, 좌하향
    int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dc[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
    int d = direction[move]; //방향 인덱스 저장

    int king_nr = point_k.first + dr[d];//king 갈 수 있는 row방향
    int king_nc = point_k.second + dc[d];//king 갈 수 있는 col방향
    if (king_nr < 0 || king_nr >= SIZE || king_nc < 0 || king_nc >= SIZE) //킹이 범위를 벗어나는 경우
        return { point_k, point_r };//범위 벗어나기 전 그대로인 킹, 돌의 좌표를 리턴

    if (king_nr != point_r.first || king_nc != point_r.second) //킹이 움직이는 방향에 돌이 없는 경우
        return { {king_nr, king_nc}, point_r };//움직인 킹의 좌표와 그대로인 돌의 좌표 리턴

    //돌이 있다면
    int rock_nr = point_r.first + dr[d];//king이 움직인 row 방향
    int rock_nc = point_r.second + dc[d];//king이 움직인 col 방향
    if (rock_nr < 0 || rock_nr >= SIZE || rock_nc < 0 || rock_nc >= SIZE) //돌이 범위를 벗어나면
        return { point_k, point_r };//범위 벗어나기 전 그대로인 킹, 돌의 좌표를 리턴

    return { {king_nr, king_nc}, {rock_nr, rock_nc} };//king이 움직인 방향대로 돌을 움직인 경우
}

/**
 * 체스판을 편하게 구현하기 위해 왼쪽 아래를 시계방향으로 90도 회전한 체스판으로 구현
 * [방향 바꿔서 생각]
 *  T:상 -> 우       B:하 -> 좌       L:좌->상         R:우->하
 * RT:오위 -> 오아   LT:왼위 -> 오위   RB:오아 -> 왼아   LB:왼아 -> 왼위
 *
 * => 바뀐 방향대로 입력에 따라 킹과 돌을 움직임
 * 방향 구현을 효율적으로 하기 위해 탐색 시간복잡도가 logN인 map 사용
 *
 * [경우의 수]
 * 1. 킹이 범위를 벗어나는 경우
 * 2. 킹이 움직이는 방향에 돌이 없는 경우
 * 3. 킹이 움직이는 방향에 돌이 있고, 돌이 범위를 벗어나는 경우
 * 4. 킹이 움직이는 방향에 돌이 있고, 둘 다 범위를 벗어나지 않는 경우
 *
 */

int main() {
    string king, rock, move;//king : king위치, rock: rock위치, move: 어떻게 움직여야 하는지
    int n;//n : 움직이는 횟수

    //입력 & 연산
    cin >> king >> rock >> n;
    //방향 바꿔서 생각해서
    //first: row, second: col
    ci point_k = { king[0] - 'A', king[1] - '1' }; //초기 킹 위치 //A1 => 0,0 왼쪽 위 코너
    ci point_r = { rock[0] - 'A', rock[1] - '1' }; //초기 돌 위치 //A2 => 0,1 오른쪽 옆 칸
    pair<ci, ci> point = { point_k, point_r };// 초기 킹과 돌 위치 저장
    while (n--) {
        cin >> move;
        point = moveKing(move, point.first, point.second);//가는 방법에 따라 돌이 있는지 없는지 확인하며 움직인다.
    }

    //출력
    cout << pointToString(point.first) << '\n' << pointToString(point.second) << '\n';//킹의 마지막 위치, 돌의 마지막 위치
    return 0;
}