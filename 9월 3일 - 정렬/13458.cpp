#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, viewer, viewerSub;
	long long cnt = 0;

	cin >> n;
	vector<int> test(n);
	for (int i = 0; i < n; i++) cin >> test[i];
	cin >> viewer >> viewerSub;

	for (int i = 0; i < test.size(); i++)
	{
		test[i] -= viewer;
		cnt++;

		if (test[i] > 0) {
			if (test[i] % viewerSub == 0) cnt += test[i] / viewerSub;
			else cnt += test[i] / viewerSub + 1;
		}
	}
	cout << cnt;
}