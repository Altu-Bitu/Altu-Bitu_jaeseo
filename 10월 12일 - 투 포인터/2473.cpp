#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

typedef struct concen {
	ll l, c, r;
};

concen liquid(vector<ll> arr, int left, int right) {
	concen ans;

	ll min_diff = 3e9;

	for (int l = left; l < right; l++) {
		int c = l + 1;
		int r = right;

		while (c < r) {
			ll mix = arr[l] + arr[c] + arr[r];
			if (mix == 0) {//0이면 이보다 0에 가까워질 수 없으니 바로 리턴
				ans.l = arr[l];
				ans.c = arr[c];
				ans.r = arr[r];
				return ans;
			}
			if (abs(mix) < min_diff) {//0에 가까운 값을 갱신할 수 있는 지 확인
				min_diff = abs(mix);
				ans.l = arr[l];
				ans.c = arr[c];
				ans.r = arr[r];
			}
			if (mix > 0)
				r--;//0보다 크니까 더 작은 값을 만들어야함
			else
				c++;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	concen ans = liquid(arr, 0, n - 1);
	cout << ans.l << " " << ans.c << " " << ans.r;
}