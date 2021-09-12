#include<iostream>
#include<set>
using namespace std;
int main() {
	int n, m, cnt = 0;
	string s;
	set<string> str;

	cin >> n >> m;

	//집합 S에 포함된 문자열
	while (n--) {
		cin >> s;
		str.insert(s);
	}

	//포함 된 문자열 개수 검사
	while (m--) {
		cin >> s;
		cnt += str.count(s);
	}
	cout << cnt;
}