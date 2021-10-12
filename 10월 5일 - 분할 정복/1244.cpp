#include<iostream>
#include<vector>
using namespace std;
vector<int> swit;

void boy(int num, int n) {
	for (int i = num; i <= n; i += num)
		swit[i] = !swit[i]; //0->1, 1->0
}

void girl(int num, int n) {
	int l = num - 1;
	int r = num + 1;

	//중심 0->1, 1->0
	swit[num] = !swit[num];

	// 좌우 대칭일 때 0->1, 1->0
	// l과 r의 범위 주의
	while (l > 0 && r <= n && swit[l] == swit[r]) {
		swit[l] = !swit[l];
		swit[r] = !swit[r];
		l--;
		r++;
	}
}
int main() {
	int n, m, sex, num;//스위치 개수n, 스위치 바꿀 횟수m, 성별sex, 바꿀 스위치 num

	cin >> n;
	swit.assign(n + 1, 0);
	//꺼진 스위치 : 0, 켜짐 : 1
	//스위치 번호는 1번부터..
	for (int i = 1; i <= n; i++)
		cin >> swit[i];

	cin >> m;
	for (int i = 0; i < m; i++) {
		//남자는 1, 여자는 2
		cin >> sex >> num;
		if (sex == 1) boy(num, n);
		else girl(num, n);
	}

	//20개씩 출력
	for (int i = 1; i <= n; i++) {
		cout << swit[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
}