#include<iostream>
#include<queue>
using namespace std;
const int MAX=200000+1;

int rumor[MAX];//루머 믿기 시작한 시간
vector<int> spread;//처음 유포자
vector<int> persons[MAX];//주변인들 관계

void dfs() {
	queue<int> q;

}

int main() {
	int n, m, p;//n: 사람 수, m: 최초유포자 번호, p: 주변인들
	cin >> n;

	for (int i = 1; i <= n; i++)//주변인들 관계 입력
		while (true) {
			cin >> p;
			if (p == 0) break;
			persons[i].push_back(p);//i번째 줄의 i번 주변사람들
		}

	cin >> m;
	spread.assign(m,0);
	for (int i = 0; i < m; i++) {
		cin >> spread[i];
		rumor[spread[i]] = 0;//유포자는 0분부터 믿기 시작
	}

	dfs();

}