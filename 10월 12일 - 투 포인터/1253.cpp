#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findGood(vector<int> arr, int left, int right) {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		int l = left, r = right;
		while (l < r) {
			int sum = arr[l] + arr[r];
			//합이 찾으려는 수와 같고, 인덱스가 겹치지 않을 때 숫자 합이 같아야 '좋다'
			if (sum == arr[i] && l != i && r != i) {
				ans++;
				break;
			}
			if (l == i || sum < arr[i]) l++;//합이 찾으려는 수보다 작거나 left와 인덱스가 겹칠 때, left 증가
			else r--;//크거나 right와 인덱스가 겹칠 때, right 감소
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	cout << findGood(arr, 0, n - 1);
}