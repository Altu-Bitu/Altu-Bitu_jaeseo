#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int n, m;// 배열 크기n, 구간 개수m

bool check(int mid) {
	int minn = arr[0], maxn = arr[0];
	int cnt = 1;
	// 주어진 배열의 순서대로 최소와 최댓값을 갱신해가면서
	// 갱신한 최소와 최대의 차이가 left와 right의 중간값 (최댓값과 최솟값 차이의 최대 = 최대 구간 점수) 보다 커지면
	// 그 전까지의 구간을 한 구간으로 센다
	// 최대, 최소는 그 구간부터 다시 갱신하여 반복하며 구간을 나눈다

	for (int i = 1; i < n; i++) {
		if (arr[i] < minn) minn = arr[i]; //최솟값 갱신
		if (arr[i] > maxn) maxn = arr[i]; //최댓값 갱신

		// left와 right의 중간값 (최댓값과 최솟값 차이의 최대 = 최대 구간 점수) 을 넘어가면
		if (maxn - minn > mid)
		{
			// 최대 구간 점수가 더 커질 수 있다는 거니까 새로운 구간을 시작한다
			cnt++;
			maxn = arr[i];
			minn = arr[i];
		}
	}
	return m >= cnt; // m개 이하 개수만큼 구간이 나누어졌는지 확인
}

int findMin(int left, int right) {
	int ans = 987654321;

	while (left <= right) {
		int mid = (left + right) / 2;
		// m개 이하 개수만큼 구간이 잘 나누어졌는 지 확인한 후
		if (check(mid)) {
			// 각 구간에서 최대값, 최소값의 최대 차이가 최소인 값으로 갱신
			// 최대 차이를 더 줄일 수 있다면, right를 갱신해서 줄인다
			ans = min(ans, mid);
			right = mid - 1;
		}
		// m개보다 많이 나누어졌다면 left를 갱신해서 최대 차이를 늘린다
		else
			left = mid + 1;
	}
	return ans;
}

int main() {
	int left = 0, right = 0;// 최솟값 left, 최댓값 right
	cin >> n >> m;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	//구간의 점수의 최댓값의 최솟값 구하기
	cout << findMin(left, right);
}