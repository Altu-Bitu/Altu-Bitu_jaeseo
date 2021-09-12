#include<iostream>
#include<set>
using namespace std;
int main() {
	int n, m, cnt = 0;
	string str;
	cin >> n >> m;

	set<string> name;
	set<string> result;

	//듣도 못한
	while (n--) {
		cin >> str;
		name.insert(str);
	}

	//보도 못한
	while (m--) {
		cin >> str;

		//듣도 보도 못한
		if (name.end() != name.find(str)) { //Search
			result.insert(str);
			cnt++;
		}
	}

	cout << cnt << '\n';
	for (auto iter : result) cout << iter << '\n';
}