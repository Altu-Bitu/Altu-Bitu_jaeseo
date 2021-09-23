#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int SIZE = 1000000;

vector<bool> isPrime() {
	vector<bool> prime(SIZE);

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (!prime[i])
			for (int j = i * i; j <= SIZE; j += i)
				prime[j] = true;
	}
	return prime;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	bool check = false;//골드바흐 못 찾을 경우 체크

	//에라토스테네스의 체
	vector<bool> prime = isPrime();

	while (true) {
		cin >> n;
		if (n == 0) break;

		for (int i = 3; i <= n / 2; i++) //b-a가 가장 큰 것을 출력하기 위해 3(홀수)부터 시작
		{
			if (!prime[i] && !prime[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				check = true;
				break;
			}
		}
		if (!check) cout << "Goldbach's conjecture is wrong.\n"; //못 찾을 경우
	}
}