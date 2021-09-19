#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, x;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //pair로 절댓값, 원래 값 저장, 오름차순 정렬

	while (n--)
	{
		cin >> x;
		if (x) pq.push(make_pair(abs(x), x));
		else if (!pq.empty()) {
			cout << pq.top().second << '\n';
			pq.pop();
		}
		else cout << 0 << '\n';
	}
}