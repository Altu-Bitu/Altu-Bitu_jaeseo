#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
vector<ll> times;
ll n, m;//입국심사대 n개, 상근이와 친구들 m명

bool check(ll mid) {
	ll cnt = 0;
	// left와 right의 중간 시간(심사 마치는 데 걸리는 시간의 최솟값)에
	// 각 심사대에서 몇 명을 검사할 수 있는지 구한다.
	// 총 검사할 수 있는 사람이 m명 이상인지 확인한다.
	for (int i = 0; i < n; i++)
		cnt += mid / times[i];

	return cnt >= m;
}

ll test(ll left, ll right) {
	ll ans = 987654321;
	while (left <= right) {
		ll mid = (left + right) / 2;
		// 검사할 수 있는 사람이 m명 이상이면
		// 걸리는 시간의 최솟값으로 갱신을 한다.
		if (check(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}

int main() {
	ll left = 0, right = 0;// 최소시간 left, 최대시간 right
	cin >> n >> m;
	times.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> times[i];
		right = max(right, times[i]);
	}
	// 심사를 마치는 데 걸리는 최소시간
	// 각자 걸리는 시간*m
	cout << test(left, right * m);
}