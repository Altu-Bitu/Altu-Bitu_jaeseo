#include<iostream>
#include<vector>
using namespace std;
bool broke[11] = { false }; //버튼들

int num_button(int n) {
	if (n == 100) return 0; //현재 채널인 100 이면 바로 0 리턴
	
	//채널 누를 수 있는 지
	int len = 0;
	while (n >= 10) {
		if (broke[n % 10]) return 1000000; //고장난 버튼이면 패스
		n /= 10;
		len++;
	}
	if (broke[len]) return 10000000;

	return len+1;
}

int main() {
	int n, m, input;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		broke[input] = true;//고장난 버튼
	}

	int ans = abs(n - 100); //현재 채널 빼주기

	// 바로 +,-로 채널 찾는 경우
	// 숫자버튼 누르고 찾는 경우, 둘 중 작은 수로 출력
	for (int i = 0; i < n + ans; i++)
		ans = min(ans, num_button(i) + abs(n - i));

	cout << ans;
}