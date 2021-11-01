#include<iostream>
#include<vector>
using namespace std;
int findMax(vector<vector<int>> squ) {
	int sum = 0;


	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> squ(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> squ[i][j];

	cout << findMax(squ);
}