#include<iostream>
using namespace std;

bool check(string str) {
	bool al[26] = { false };

	for (int i = 0; i < str.length(); i++) {
		if (i && str[i] == str[i - 1]) continue; //전 문자와 같을 경우 continue
		else {
			if (!al[str[i] - 'a'])
				al[str[i] - 'a'] = true;
			else return false;
		}
	}
	return true;
}

int main() {
	int n, cnt = 0;
	string str;

	cin >> n;
	while(n--) {
		cin >> str;

		if (check(str)) cnt++;
	}

	cout << cnt;
}