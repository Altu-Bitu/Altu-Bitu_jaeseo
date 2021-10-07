#include<iostream>
#include<vector>
using namespace std;

int costRGB(int n) {
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	int cost[3]; //빨강0, 초록1, 파랑2 으로 칠하는 비용

	//dp[i][0]: i번째 집을 빨강
	//dp[i][1]: i번째 집을 초록
	//dp[i][2]: i번째 집을 파랑 으로 칠했을 때의 최소비용
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];

		// 빨강으로 칠해지기 위해서, 전이 초록, 파랑
		// 초록으로 칠해지기 위해서, 전이 빨강, 파랑
		// 파랑으로 칠해지기 위해서, 전이 빨강, 초록
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}

	//최소비용
	return 	min(dp[n][0], min(dp[n][1], dp[n][2]));//비교할 요소가 3개면 if쓰지 않고 이렇게 하는 게 효율적?!
}

int main() {
	int n;
	cin >> n;

	cout << costRGB(n);
}