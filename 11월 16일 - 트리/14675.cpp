#include<iostream>
#include<vector>
using namespace std;

void is_true(int n) {
	if (n > 1) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;//n : 정점 개수, q : 질의 개수
	int a, b;

	cin >> n;
	vector<int> tree(n+1,0);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a]++;//연결됐다 하면, 개수 늘리기
		tree[b]++;
	}

	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (a == 1)//단절점이냐?
			is_true(tree[b]);//연결된 정점이 2개 이상이면 단절점

		else//단절선이냐?
			is_true(n);//총 노드 수가 2개 이상이기만 하면, 뭐든 단절선
	}
}