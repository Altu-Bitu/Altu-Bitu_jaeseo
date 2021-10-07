#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cutting(int& m, int cake) {
	int sum = 0;//각 케이크마다 길이가 10 인 케이크 개수

	if (cake < 10) return 0;//케이크 길이가 10 미만인 건 못 먹음

	//10 이상인 케이크 중에서
	//길이가 10인 케이크
	if (cake == 10) return 1;

	// 길이가 10 초과인 케이크
	// 자를 기회가 남았다면
	if (m > 0) {
		int tmp = (cake / 10);
		if (cake % 10 == 0) tmp--;//10 배수는 1번 덜 잘라도 됨

		//자르려는 케이크 길이가 횟수보다 길면
		//남은 횟수만큼만 자르기
		if (m- tmp < 0) {
			sum = m;
			m = 0;
		}
		//케이크 잘라서 길이 10 만들기
		else {
			sum += cake/10;
			m -= tmp;
		}
	}
	return sum;
}

bool cmp(const int& c1, const int& c2) {
	if (c1 % 10 == 0 && c2 % 10 == 0) return c1 < c2; //10의 배수 중에도 같아도 작은 숫자

	// 1. 둘 중 c1이 10 의 배수 : swap안됨
	// 2. 둘 중 c2이 10 의 배수 : swap됨
	// 3. 둘 다 10의 배수가 아님 : swap됨(10의 배수 아닌 수는 swap되든 상관 없음)
	return (c1 % 10 == 0);
}

int main() {
	int n, m;//롤케이크 개수n, 자를 수 있는 최대 횟수m
	cin >> n >> m;

	int sum = 0;//길이가 10 인 케이크 개수

	vector<int> cake(n, 0);

	for (int i = 0; i < n; i++)
		cin >> cake[i];

	sort(cake.begin(), cake.end(), cmp);//10의 배수이며, 작은 숫자 정렬로

	for (int i = 0; i < n; i++)
		sum += cutting(m, cake[i]);

	cout << sum;
}