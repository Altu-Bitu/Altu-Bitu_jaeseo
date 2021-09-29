#include<iostream>
using namespace std;

const int SIZE = 21;
int n;
int team[SIZE][SIZE];
bool check[SIZE]; //백트래킹으로 나눈 팀은 true(start팀), 나머지 팀은 false(link팀)
int result = 2147483647; //최솟값을 구하기 위한 int에서 최댓값

void statMin(int cnt) {
	if (cnt == n) {
		int start = 0, link = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (check[i] && check[j]) start += team[i][j];
				if (!check[i] && !check[j])link += team[i][j];
			}

		int tmp = abs(start - link);
		if (tmp < result) result = tmp;//최솟값..
	}

	for (int i = cnt; i <= n; i++)
		if (!check[i]) {
			check[i] = true;

			statMin(i);
			check[i] = false;
		}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> team[i][j];

	statMin(1);
	cout << result;
}