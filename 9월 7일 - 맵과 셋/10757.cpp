#include<iostream>
#include<vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int carry = 0;//캐리여부

	int m = max(a.size(), b.size());// 길이가 더 긴 숫자 길이로
	vector<int> sum;

	for (int i = 0; i < m; i++)
	{
		int tmp = carry;

		if (a.size() > i) tmp += (a[a.size() - 1 - i] - '0');
		if (b.size() > i) tmp += (b[b.size() - 1 - i] - '0');

		if (tmp / 10) carry = 1;//캐리 여부
		else carry = 0;

		sum.push_back(tmp % 10);
	}

	if (carry == 1) sum.push_back(1);//제일 마지막에 캐리 있었으면 1 추가

	for (int i = sum.size() - 1; i >= 0; i--) cout << sum[i];
}