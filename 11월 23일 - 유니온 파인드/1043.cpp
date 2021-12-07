#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<vector<int>> party;//파티
vector<int> truth;//진실을 알고 있는 사람

int find(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = find(parent[node]);
}

void unionInput(int x, int y) {
	int xp = find(x);
	int yp = find(y);

	if (xp == yp)
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

void adjParty() {
	for (int i = 0; i < party.size(); i++)
		for (int j = 1; j < party[i].size(); j++)
			unionInput(party[i][j - 1], party[i][j]);
}
int cntParty() {
	int ans = 0;

	for (int i = 0; i < party.size(); i++) {
		bool go = true;
		for (int j = 0; j < party[i].size(); j++)
			for (int k = 0; k < truth.size(); k++)
				if (find(party[i][j]) == find(truth[k])) {//진실을 아는 사람이 그 파티에 있을 경우
					go = false;
					break;
				}
		if (go == true)
			ans++;
	}
	return ans;
}
int main() {
	int n, m, t, num;//n: 사람 수, m: 파티 수, t:진실을 아는 사람 수
	cin >> n >> m >> t;

	parent.assign(n + 1, -1);
	truth.assign(t, 0);

	//진실을 아는 사람 입력
	for (int i = 0; i < t; i++)
		cin >> truth[i];

	//파티마다 오는 사람들 정보 입력
	for (int i = 0; i < m; i++) {
		cin >> num;
		vector<int> temp(num,0);
		for (int j = 0; j < num; j++)
			cin >> temp[j];
		party.push_back(temp);
	}

	//연산
	int ans = 0;//파티 수

	//각 파티 사람들 다 연결해놓기
	adjParty();

	//파티 수 세기
	cout << cntParty();
}