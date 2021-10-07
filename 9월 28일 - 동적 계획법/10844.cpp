#include<iostream>
#include<vector>

using namespace std;
const int MOD = 1000000000;//상수 대문자표기!!

int num(int n) {
	vector<vector<int>> dp(n+1, vector<int>(10,0));
	
	// n=2 : 10,21,12,32,,23,43,34,,,
	// 마지막 자리가 3으로 끝난다면 3앞에 올 수 있는 숫자는 3-1, 3+1
	// n-1의 자리수를 가지면서 2와 4로 끝나는 숫자의 경우를 가지고 온다.
	//i의 길이를 가지며 j로 끝나는 수의 경우의 수
	// ex.dp[2][2]: 2 길이를 가지며 2로 끝나는 수의 경우의 수 => 12, 32
	// 그래서 길이가 1이며 1과 3으로 끝날 때의 경우의 수를 구하면 된다. = dp[1][1]+dp[1][3]

	for (int i = 1; i <10; i++)
		dp[1][i] = 1;//0을 제외한 한 자리 숫자는 모두 계단 수

	for(int i=2;i<=n;i++)
		for (int j = 0; j <10; j++) {
			// 주의할 점은 0으로 끝나는 수 : 앞에 1큰 수만
			// 9로 끝나는 수 : 앞에 1 작은 수만
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j - 1]+dp[i-1][j+1]);

			dp[i][j] %= MOD;
		}

	int ans=0;
	for (int i = 0; i <10; i++)
		ans = (ans+dp[n][i])% MOD;

	return ans;
}
int main() {
	int n;
	cin >> n;

	cout << num(n);
}