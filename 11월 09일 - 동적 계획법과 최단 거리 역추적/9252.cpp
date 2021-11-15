#include<iostream>
#include<vector>

using namespace std;
const int SIZE = 1e3 + 1;
string path[SIZE][SIZE];//경로(LCS 단어) 저장

int LCS(string s1, string s2) {
	int len2 = s2.length();
	int len1 = s1.length();

	vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 0));//LCS길이 저장

	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (s2[i - 1] == s1[j - 1]) {//문자 서로 같을 때
				dp[i][j] = dp[i - 1][j - 1] + 1;//해당 문자들이 포함되기 전의 길이 +1(좌상향 대각선)
				path[i][j]=path[i - 1][j - 1] + s2[i - 1];//전 LCS에 서로 같은 문자 덧붙여서 저장
			}
			else {//문자 서로 다를 때
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//그 전의 길이 최댓값 그대로(위쪽 or 왼쪽)
				
				if (path[i - 1][j].length() > path[i][j - 1].length())//긴 LCS 갖고오기
					path[i][j] = path[i - 1][j];//위쪽꺼
				else
					path[i][j] = path[i][j - 1];//왼쪽꺼
			}
		}
	}
	return dp[len2][len1];
}
int main() {
	string s1, s2;

	cin >> s1 >> s2;

	cout << LCS(s1, s2)<<'\n';
	cout << path[s2.length()][s1.length()];
}