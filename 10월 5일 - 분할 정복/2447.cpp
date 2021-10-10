#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> star;

void divide(int size, int i, int j) {
	//conquer : size가 0인가?
	if (size == 0) star[i][j] = '*';

	//공백찍기
	// n=3일 때, (1,1)에서 공백
	// n=9일 때, (1,1),(1,4),(1,7)..(7,1)..(7,7)에서 공백
	// => i%3==1 && j%3==1 일 때 공백
	// 더 나아가, 한 가운데 (3,3),(3,4),(3,5),(4,3)...(5,5) 공백
	// 9/3 = 3 == (size / sub_size)
	// => (i/3)%3==1 && (j/3)%3==1 일 때 공백
	else if ((i / size) % 3 == 1 && (j / size) % 3 == 1) star[i][j] = ' ';

	//divide : 작은 별로 쪼개기
	else divide(size / 3, i, j);
}

int main() {
	int n;
	cin >> n;

	star.assign(n, vector<char>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			divide(n, i, j);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << star[i][j];
		cout << '\n';
	}
}