#include<iostream>
#include<vector>
using namespace std;

vector<int> snack;
int m, n;//조카 수m, 과자 수n
bool check(int mid) {
	int cnt = 0;
	// left와 right의 중간 길이(줄 수 있는 과자의 최대 길이)만큼
	// 주어진 과자들을 잘라본다
	// 잘라서 나올 수 있는 과자의 개수를 센다
	// 중간 길이만큼 나온 과자의 개수가 조카들 수보다 많은지 확인한다
	for (int i = 0; i < n; i++)
		cnt += snack[i] / mid;

	return cnt >= m;
}

int divide(int left, int right) {
	int ans;
	while (left <= right) {//이분탐색
		int mid = (left + right) / 2;
		// 각 과자를 최대 길이만큼 잘라서 나온 과자의 수가 조카 수보다 많은 지 확인하고
		// 많으면 더 긴 길이만큼 잘라서 나올 수 있는 과자의 개수를 줄이면 되는 거니까
		// 많으면 left를 갱신하여, 중간 길이(줄 수 있는 과자의 최대 길이)를 늘린다
		if (check(mid)) {
			// 과자 수가 조카 수보다 많이 나온 것일 뿐이지, 나눠는 줄 수 있기 때문에 ans에 대입해 놓는다
			ans = mid;
			left = mid + 1;
		}
		// 적으면 right를 갱신하여, 중간 길이(줄 수 있는 과자의 최대 길이)를 줄인다
		else right = mid - 1;
	}
	return ans;
}

int main() {
	int left = 1, right = 0;// 최소길이 left, 최대길이 right

	cin >> m >> n;
	snack.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> snack[i];
		right = max(right, snack[i]);
	}
	// 줄 수 있는 과자의 최대 길이 구하기
	cout << divide(left, right);
}