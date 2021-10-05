#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cutting(int& m, int cake) {
	int sum = 0;//각 케이크마다 길이가 10 인 케이크 개수

	while (cake >= 10) {// 케이크 길이가 여전히 10 이상일 때
		if (cake == 10) {
			sum++;
			break;// 길이가 10인 케이크는 더 이상 자를 필요 없으니 break
		}
		else {//자를 횟수 있으면 자름
			if (m <= 0) break;
			m--;
			sum++;
			cake -= 10;
		}
	}
	return sum;
}

int main() {
	int n, m, tmp;//롤케이크 개수n, 자를 수 있는 최대 횟수m
	cin >> n >> m;

	int sum = 0;//길이가 10 인 케이크 개수

	vector<int> cakeTen, cake;//10의 배수인 케이크, 나머지 케이크

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		if (tmp % 10 == 0)
			cakeTen.push_back(tmp);
		else
			cake.push_back(tmp);
	}

	sort(cake.begin(), cake.end());
	sort(cakeTen.begin(), cakeTen.end());

	//10의 배수 케이크가 자르는 횟수가 1 적으니까 먼저 처리
	for (int i = 0; i < cakeTen.size(); i++)
		sum += cutting(m, cakeTen[i]);

	for (int i = 0; i < cake.size(); i++)
		sum += cutting(m, cake[i]);

	cout << sum;
}