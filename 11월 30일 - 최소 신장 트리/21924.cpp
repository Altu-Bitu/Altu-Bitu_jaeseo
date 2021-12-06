#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
typedef long long ll;
typedef tuple < ll, ll, ll > tp;
vector<ll> parent;//음수는 루트 입장 : 가지고 있는 자식 개수, 양수는 자식입장 : 최종 루트
//find연산
ll findParent(ll node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);//그래프 압축하며 루프 정점 찾기
}
//union연산(cycle 생성여부를 위해 리턴형 bool)
bool unionInput(ll x, ll y) {
	ll xp = findParent(x);
	ll yp = findParent(y);

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
ll kruskal(ll v, priority_queue<tp, vector<tp>, greater<>>& pq) {
	ll cnt = 0, sum = 0;//사용간선 개수, 간선 가중치 총합

	while (cnt < v - 1) {
		if (pq.empty()) return -1;

		ll weight = get<0>(pq.top());//tuple에서 값 뺴오기
		ll x = get<1>(pq.top());
		ll y = get<2>(pq.top());
		pq.pop();

		if (unionInput(x, y)) {//사이클 없이 유니온 했다면
			cnt++;
			sum += weight;
		}
	}
	return sum;
}

int main() {
	ll n, m, a, b, c, sum = 0;
	cin >> n >> m;

	priority_queue<tp, vector<tp>, greater<>> pq;//최소힙
	parent.assign(n + 1, -1);//부모는 다 -1로 초기화

	while (m--) {
		cin >> a >> b >> c;
		sum += c;
		pq.push({ c,a,b });
	}

	ll ans = kruskal(n, pq);
	if (ans == -1)
		cout << -1;
	else
		cout << sum - ans;
}