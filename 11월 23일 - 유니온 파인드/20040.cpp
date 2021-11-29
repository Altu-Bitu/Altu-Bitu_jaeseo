#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;

int find(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = find(parent[node]);
}

bool unionInput(int x, int y) {
	int xp = find(x);
	int yp = find(y);

	if (xp == yp) //사이클 생성 true리턴
		return true;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return false;//사이클 생성 안되고 잘 union됐다면 false리턴
}

int main() {
	int n, m, a, b, t = 0;//t: 사이클 생성된 단계
	cin >> n >> m;

	parent.assign(n + 1, -1);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (unionInput(a, b)) {
			t = i;
			break;
		}
	}
	cout << t;
}