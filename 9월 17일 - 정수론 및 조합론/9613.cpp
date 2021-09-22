#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int t, n, input;
	int gcdList[101];

	cin >> t;
	while (t--) {
		long long sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++) 
			cin >> gcdList[i];

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)//테스트 케이스마다 가능한 모든 쌍의 합
				sum += gcd(max(gcdList[i], gcdList[j]),min(gcdList[i], gcdList[j]));

		cout << sum << '\n';
	}
}