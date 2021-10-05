#include<iostream>
#include<vector>
using namespace std;

void getDP(vector<vector<int>>& dp, vector<vector<int>>& cost, int n) {
	for (int i = 1; i < n; i++) {
		// 빨강으로 칠해지기 위해서, 전이 초록, 파랑
		// 초록으로 칠해지기 위해서, 전이 빨강, 파랑
		// 파랑으로 칠해지기 위해서, 전이 빨강, 초록
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
}

int costRGB(int n) {
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	vector<vector<int>> cost(n + 1, vector<int>(3, 0)); //빨강0, 초록1, 파랑2 으로 칠하는 비용

	//dp[i][0]: i번째 집을 빨강
	//dp[i][1]: i번째 집을 초록
	//dp[i][2]: i번째 집을 파랑 으로 칠했을 때의 최소비용

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	int ans = 987654321;//큰 수
	for (int j = 0; j < 3; j++) {
		//첫 번째 집은 각각의 색으로 시작
		dp[0][0] = ans;
		dp[0][1] = ans;
		dp[0][2] = ans;
		// 이번에 칠할 색상(첫 번째 집에 칠해져 있는 색 제외한 색)
		dp[0][j] = cost[0][j];

		//최소비용 dp구하기
		getDP(dp, cost, n);

		//첫 번째 집 색깔이 j인 경우, 마지막 집은 j가 아닌 색깔로 칠함
		for (int i = 0; i < 3; i++)
			if (i != j) ans = min(ans, dp[n - 1][i]);//최솟값
	}

	return ans;
}

int main() {
	//RGB거리1과 다르게 집들이 서로 원형으로 이어져 있음 (시작 조건 모름)
	int n;
	cin >> n;

	cout << costRGB(n);
}