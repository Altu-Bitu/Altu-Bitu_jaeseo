#include <iostream>
#include <vector>

using namespace std;

struct info { //내구도와 로봇 존재 여부
    int power;
    bool is_on;
};

vector<info> belt;  //컨테이너 벨트 정보 : 내구도, 로봇 존재 여부
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소
    if (--pos >= 0)
        return pos;
    return n * 2 - 1;
}

void second(int n, int start, int end) {
    int cur = end;
    while (cur != start) { //end - 1 부터 start 까지 검사
        cur = minusPosition(n, cur);
        int next = (cur + 1) % (n * 2); //다음 위치
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없고, 내구성 1이상인 경우에 로봇 옮김
            belt[cur].is_on = false;
            belt[next].power--;
            if (next != end) //내리는 위치 아닐 경우
                belt[next].is_on = true; //로봇 옮기기
            if (belt[next].power == 0)
                zero_power++;
        }
    }
}

void third(int start) {
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니면 로봇 올림
        belt[start].is_on = true;
        belt[start].power--;
        if (belt[start].power == 0)
            zero_power++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;
    belt.assign(n * 2, { 0, false });
    for (int i = 0; i < n * 2; i++)
        cin >> belt[i].power;

    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수
    while (true) {
        start = minusPosition(n, start);
        end = minusPosition(n, end);
        if (belt[end].is_on) //벨트 회전 후에 로봇이 내리는 위치에 있으면 내리기
            belt[end].is_on = false;
        second(n, start, end);
        third(start);
        step++;
        if (zero_power >= k)
            break;
    }

    cout << step << '\n';


    return 0;
}