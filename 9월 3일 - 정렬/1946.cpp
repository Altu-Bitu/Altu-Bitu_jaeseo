#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct score
{
	int docu, inter;
};
int main() {
	int t;
	cin >> t;

	while(t--)
	{
		int n, tmp, result = 1;//서류면접 1등
		cin >> n;
		vector<pair<int, int>> employ(n);

		for (int j = 0; j < n; j++)
			cin >> employ[j].first >> employ[j].second;

		sort(employ.begin(), employ.end());

		tmp = employ[0].second;
		for (int j = 1; j < n; j++)
			if (tmp > employ[j].second) {
				tmp = employ[j].second;
				result++;
			}

		cout << result << '\n';
	}
}