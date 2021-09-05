#include<iostream>
using namespace std;

bool check(string str) {
	bool al[26] = { false };

	for (int i = 0; i < str.length(); i++) {
		if (!al[str[i] - 'a']) {
			al[str[i] - 'a'] = true;
			char tmp = str[i];

			while (tmp == str[++i]);
			i--;
		}
		else return false;
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