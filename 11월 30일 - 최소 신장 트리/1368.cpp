#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
typedef tuple<int, int, int> tp;
vector<int> parent;//음수는 루트 입장 : 가지고 있는 자식 개수, 양수는 자식입장 : 최종 루트

//find연산
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);//루프 정점 찾기
}
//union연산(cycle 생성여부를 위해 리턴형 bool)
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)//같은 집합에 있으면 cycle
		return false;

	if (parent[xp] < parent[yp]) {// xp루트
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {//yp루트
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

int kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
	int cnt = 0, sum = 0;//사용간선 개수, 간선 가중치 총합

	while (cnt < v) {//v간선 개수만큼 돌기(새로운 0루트 노드 추가 했으니 v개)
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
	int n, w;//n:논 수, w:비용
	priority_queue<tp, vector<tp>, greater<>> graph;//최소힙
	vector<vector<int>> farm;

	cin >> n;
	parent.assign(n + 1, -1);//부모는 다 -1로 초기화
	farm.assign(n+1,vector<int>(n+1,0));

	//각 노드의 비용을 간선으로 치고, 새로운 루트 0(바다!) 과 이어진 그래프로 만든 후, MST
	for (int i = 1; i <= n; i++) {
		cin >> w;
		graph.push({ w, 0,i });
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin>>farm[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			graph.push({farm[i][j],i,j});

	cout << kruskal(n, graph);
}