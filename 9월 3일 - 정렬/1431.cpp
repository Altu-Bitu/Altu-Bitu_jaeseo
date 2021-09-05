#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int sum(string str) {
	int s = 0;

	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i])) s += str[i] - '0';

	return s;
}
bool cmp(const string i1, const string i2) {
	if (i1.length() != i2.length()) return i1.length() < i2.length();

	int sum1 = sum(i1), sum2 = sum(i2);
	if (sum1 != sum2) return sum1 < sum2;

	return i1 < i2;
}

int main() {
	int n;
	cin >> n;

	vector<string> num(n);

	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num.begin(), num.end(), cmp);

	for (int i = 0; i < n; i++) cout << num[i] << '\n';

}