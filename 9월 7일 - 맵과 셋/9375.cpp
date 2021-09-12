#include<iostream>
#include<map>
using namespace std;

//옷고르기
int clothes(map<string, int> c) {
	//의상 종류에 그 의상 안 입은 경우 다 더해서 곱함 -1
	int cnt = 1;
	for (auto iter : c)
		cnt *= (iter.second + 1);

	return cnt - 1;
}

int main() {
	int t, n;
	string s, name;
	cin >> t;

	while (t--)
	{
		map<string, int> c;
		cin >> n;
		while (n--) {
			cin >> s >> name;
			c[name]++;
		}

		cout << clothes(c) << '\n';
	}
}