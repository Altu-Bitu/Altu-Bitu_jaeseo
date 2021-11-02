#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& people, vector<int>& init, int n) {
    vector<int> believer(n + 1, 0); //주변인들이 몇 명 믿는지
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;//루머 믿는 사람 넣는 큐

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0;//최초유포자는 루머를 0분부터 믿기 시작한다.
        q.push(init[i]);//최초 유포자 사람 번호 푸시
    }

    //각자 루머 믿는 과정
    while (!q.empty()) {
        int v = q.front(); //현재 사람
        int t = ans[v]; //루머 믿은 시간
        q.pop();

        for (int i = 0; i < people[v].size(); i++) {//현재 큐에 있는 사람(주변인까지) 모두 탐색
            int next = people[v][i];//주변인
            believer[next]++; //next의 주변에서 루머를 믿는 사람 증가
            if (ans[next] != -1) //이미 루머를 믿는 다면
                continue;
            if ((people[next].size() + 1) / 2 <= believer[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1;//시간이 지나는 중
                q.push(next);//주변인 푸시
            }
        }
    }
    return ans;
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main() {
    int n, m, input;//n: n명의 사람들, m: 최초 유포자 수

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>());//동적 할당
    for (int i = 1; i <= n; i++) {//1번 사람부터 n번 사람의 관계
        while (true) {
            cin >> input;//관계 입력받고
            if (!input)//0 으로 마지막
                break;
            people[i].push_back(input);//각각 관계된 사람들
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0);//동적 할당
    for (int i = 0; i < m; i++)
        cin >> init[i];//최초 유포자 사람의 번호

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}