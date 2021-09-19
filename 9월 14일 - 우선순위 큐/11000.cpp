#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<>> pq;
	vector<pair<int, int>> time(n);

	for (int i = 0; i < n; i++)
		cin >> time[i].first >> time[i].second; //시작시간, 종료시간 저장
	sort(time.begin(), time.end());//오름차순으로 정렬

	pq.push(time[0].second);//첫 수업 종료시간

	for (int i = 1; i < n; i++)
	{
		if (pq.top() <= time[i].first) pq.pop(); //종료시간보다 시작시간이 크면 수업 이어서 할 수 있으니까 pop
		pq.push(time[i].second);
	}
	cout << pq.size();
}