#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;

int find(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = find(parent[node]);
}

void unionInput(int x, int y) {
	int xp = find(x);
	int yp = find(y);

	if (xp == yp) //사이클 생성
		return;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}
bool check(vector<int> plan) {
	for (int i = 1; i < plan.size(); i++)
		if (find(plan[i - 1]) != find(plan[i]))//입력된 도시끼리 루트가 같은 지 확인
			return false;

	return true;
}
int main() {
	int n, m, input;//n:도시 수, m:여행에 속한 도시 수
	vector<int> plan;//여행 계획

	cin >> n >> m;
	parent.assign(n + 1, -1);
	plan.assign(m, 0);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input)
				unionInput(i, j);//도시 연결 정보
		}

	for (int i = 0; i < m; i++)
		cin >> plan[i];//여행 계획

	if (check(plan)) cout << "YES";
	else cout << "NO";
}