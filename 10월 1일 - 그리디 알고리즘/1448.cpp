#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int triangle(vector<int>& straw) {
	//삼각형 만들기 : 가장 긴 변 < 나머지 변 합
	for (int i = 0; i < straw.size()-2; i++) {
		// 제일 큰 수 바로 뒤에 있는 두 a,b의 합이 큰 수보다 작으면
		// 어차피 뒤에 있는 수들도 작으니까 바로 뒤 2개씩만 조사
		int c = straw[i], a = straw[i+1], b = straw[i+2];
		if (c < a + b) return a + b + c;
	}
	return -1;
}

int main() {
	int n,i,j,k;
	cin >> n;

	vector<int> straw(n, 0);
	for (int i = 0; i < n; i++)
		cin >> straw[i];

	sort(straw.begin(), straw.end(), greater<>());//큰 수부터 해서 최댓값

	cout << triangle(straw);
}