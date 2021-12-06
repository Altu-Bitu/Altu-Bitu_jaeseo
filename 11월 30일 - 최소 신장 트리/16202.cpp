#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;//음수는 루트 입장 : 가지고 있는 자식 개수, 양수는 자식입장 : 최종 루트
//find연산
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);//그래프 압축하며 루프 정점 찾기
}
//union연산(cycle 생성여부를 위해 리턴형 bool)
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)//같은 집합에 있으면 cycle
		return false;

	if (parent[xp] < parent[yp]) {//더많이 갖고있는 루트 속으로 머지 xp루트
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {//더많이 갖고있는 루트 속으로 머지 yp루트
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

int kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
	int cnt = 0, sum = 0;//사용간선 개수, 간선 가중치 총합

	while (cnt < v - 1) {//v-1간선 개수만큼 돌기 
		if (pq.empty()) return 0;//돌다가 간선이 없으면 mst존재 안하니까 점수 0

		int weight = get<0>(pq.top());//tuple에서 값 뺴오기
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (unionInput(x, y)) {//사이클 없이 유니온 했다면
			cnt++;
			sum += weight;
		}
	}
	return sum;
}
int main() {
	int n, m, k, a, b;//n:정점 수, m: 간선 수, k: 턴의 수
	vector<pair<int, int>> edge; //간선
	cin >> n >> m >> k;

	for (int i = 0; i < m;i++) {
		cin >> a >> b;
		edge.emplace_back(a,b);
	}

	for (int i = 0; i < k; i++) {
		priority_queue<tp, vector<tp>, greater<>> pq;//최소힙
		parent.assign(n + 1, -1);//부모는 다 -1로 초기화

		//최소간선 한 개씩 없애가면서 pq 채우고 MST
		for (int j = i; j < m; j++)
			pq.push({ j + 1, edge[j].first, edge[j].second });

		cout << kruskal(n, pq) << " ";
	}
}