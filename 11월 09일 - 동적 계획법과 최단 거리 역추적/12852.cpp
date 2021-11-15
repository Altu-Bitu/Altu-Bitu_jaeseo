#include<iostream>
#include<vector>
using  namespace std;

//역추적
vector<int> back(int x, vector<int>& path) {
	vector<int> result;

	while (x != 1) {//1 찾을 때까지
		result.push_back(x);
		x = path[x];
	}
	result.push_back(1);
	return result;
}

int findOne(int x, vector<int>& path) {
	vector<int> dp(x + 1, 0);

	//1. x가 3으로 나누어 떨어지면, 3으로 나눔
	//2. x가 2로 나누어 떨어지면, 2로 나눔
	//3. 1을 뺌.
	//bottom up으로 3->2->1순으로 처리

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;//경로 저장

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;//경로 저장
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;//경로 저장
		}
	}
	return dp[x];//x번째에 남은 연산 횟수
}

int main() {
	int x;

	cin >> x;
	vector<int> path(x + 1, 0);//경로(1로 만드는 과정 수)저장
	
	cout << findOne(x, path) << '\n';
	vector<int> result = back(x, path);

	for (int i =0; i < result.size(); i++)
		cout << result[i] << ' ';
}