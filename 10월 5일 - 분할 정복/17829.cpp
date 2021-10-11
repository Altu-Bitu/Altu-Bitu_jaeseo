#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> x;

int secondMax(int i, int j) {
	vector<int> result;

	for (int k = 0; k < 2; k++)
		for (int l = 0; l < 2; l++)
			result.push_back(x[i+k][j+l]);

	//두 번째로 큰 수 구하기
	sort(result.begin(),result.end());
	return  result[2];
}
void divide(int size) {
	//conquer : size가 1인가?
	if (size == 1) return;

	// (0,0) (0,1) (0,2) (0,3)
	// (1,0) (1,1) (1,2) (1,3)
	// (2,0) (2,1) (2,2) (2,3)
	// (3,0) (3,1) (3,2) (3,3)
	// => (0,0) (0,1) 새로운 값으로 갱신된 matrix
	//    (1,0) (1,1)
	// => (0,0) 결과값

	//divide : 작은 행렬로 쪼개기
	for (int i = 0; i < size; i += 2)
		for (int j = 0; j < size; j += 2)
			x[i / 2][j / 2] = secondMax(i, j);

	divide(size / 2);
}
int main() {
	int n;
	cin >> n;

	x.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> x[i][j];

	divide(n);

	cout << x[0][0];
}