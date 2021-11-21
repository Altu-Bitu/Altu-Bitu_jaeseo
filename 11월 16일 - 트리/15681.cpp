#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> tree;
vector<int> treeNum;
vector<bool> visited;

//dfs
int dfs(int root) {
	if (treeNum[root])//해당 정점에, subtree있을 시
		return treeNum[root];//연결된 subtree의 정점 개수 리턴

	//처음방문
	visited[root] = true;
	treeNum[root] = 1;//자신도 자신을 루트로 하는 서브트리에 포함되므로 1부터 시작
	for (int i = 0; i < tree[root].size(); i++) {
		int child = tree[root][i];//자식노드
		if (!visited[child])//방문안했을 경우
			treeNum[root] += dfs(child);
	}

	return treeNum[root];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, q;//n: 정점수, r: 루트번호, q:쿼리수
	int u, v, input;

	cin >> n >> r >> q;

	//할당
	tree.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);
	treeNum.assign(n + 1, 0);

	//tree생성
	n--;
	while (n--) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	//dfs
	treeNum[r] = dfs(r);//찾을 루트번호

	while (q--) {
		cin >> input;
		cout << treeNum[input] << '\n';
	}
}