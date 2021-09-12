#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m, cnt = 0;
	string str;
	cin >> n >> m;

	vector<string> name;
	vector<string> result;

	//듣도 못한
	while (n--) {
		cin >> str;
		name.push_back(str);
	}

	//사전 순으로 정렬
	sort(name.begin(), name.end());

	//보도 못한
	while (m--) {
		cin >> str;

		//듣도 보도 못한
		if (binary_search(name.begin(), name.end(), str)) { //Search
			result.push_back(str);
			cnt++;
		}
	}
	//사전 순으로 정렬
	sort(result.begin(), result.end());

	cout << cnt << '\n';
	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';

}