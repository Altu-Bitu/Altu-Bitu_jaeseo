#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> tree;
vector<int> treeNum;

//dfs
int dfs(int root) {
	if (treeNum[root])//해당 정점에, subtree있을 시
		return 0;//더할 필요 없으니 0 리턴

	//처음방문
	treeNum[root] = 1;//자신도 자신을 루트로 하는 서브트리에 포함되므로 1부터 시작
	for (int i = 0; i < tree[root].size(); i++)
		treeNum[root] += dfs(tree[root][i]);//자식노드로 들어감

	return treeNum[root];//현재까지 subtree 개수 리턴
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, q;//n: 정점수, r: 루트번호, q:쿼리수
	int u, v, input;

	cin >> n >> r >> q;

	//할당
	tree.assign(n + 1, vector<int>());
	treeNum.assign(n + 1, 0);

	//tree생성
	while (n-- > 1) {
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