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
		int t= test[i] - viewer;
		cnt++;

		if (t > 0) {
			int tVS = t / viewerSub;
			if (t%viewerSub==0) cnt += tVS;
			else cnt += tVS + 1;
		}
	}
	cout << cnt;
}