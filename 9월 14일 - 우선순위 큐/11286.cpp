#include<iostream>
#include<queue>
using namespace std;

struct cmp {
	bool operator()(int num1, int num2) {
		if (abs(num1) == abs(num2)) return num1 > num2;
		return abs(num1) > abs(num2); //우선순위 큐의 오름차순은 스택의 오름차순과 반대!!!
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;

	priority_queue<int, vector<int>, cmp> pq; //오름차순 정렬

	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x) pq.push(x); // 0 아니면 집어넣기
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
	}
}