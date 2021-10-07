#include<iostream>
#include<vector>
using namespace std;

long long minPrice(vector<long long> &road, vector<long long>& gas) {
	long long sum = gas[0] * road[0], tmp = gas[0];//처음에 가긴 가야하기 때문에

	for (int i = 1; i < road.size(); i++) {
		if (gas[i] < tmp)
			tmp = gas[i];//가격 최소인 주유소 구하기
		sum += tmp * road[i];//가격 최소인 주유소에서 앞으로 갈 길이만큼 곱해서 더하기
	}
	return sum;
}

int main() {
	int n;
	cin >> n;

	// 1,000,000,000 이하의 자연수를 대비해서 long long
	vector<long long> road(n - 1, 0), gas(n, 0);//도시 연결하는 도로 길이, 각 도시 주유소 가격

	for (int i = 0; i < n - 1; i++)
		cin >> road[i];

	for (int i = 0; i < n; i++)
		cin >> gas[i];

	cout << minPrice(road, gas);
}