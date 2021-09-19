#include<iostream>
#include<cstring>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool s[21] = {false}; //20개의 숫자에 체크/언체크
	int m, x;
	string str;

	cin >> m;
	while (m--)
	{
		cin >> str;

		if (str == "add") {
			cin >> x;
			s[x] = true;
		}
		if (str == "remove") {
			cin >> x;
			s[x] = false;
		}
		if (str == "check") {
			cin >> x;
			cout << s[x] << '\n';
		}
		if (str == "toggle") {
			cin >> x;
			s[x] = !s[x];
		}
		if (str == "all")
			memset(s, true, sizeof(s));
		if (str == "empty")
			memset(s, false, sizeof(s));
	}
}