#include<iostream>
#include<cmath>
using namespace std;
int n, r, c;//2^n,  행r, 열c
int ans;//결과값
void check_visit(int size, int row, int col) {
	//conquer : 원하는 곳에 도착했는가?
	if (row == r && col == c) {
		cout << ans;
		return;
	}

	//divide : 1,2,3,4분면으로 4등분해서 해당 분면에 원하는 곳이 있는 지 확인한다.
	// => 원하는 곳이 3사분면에 있다면 1사분면, 2사분면은 분할을 하지 않아도 된다.

	// n=2)
	// (0,0) (0,1) (0,2) (0,3)
	// (1,0) (1,1) (1,2) (1,3)
	// (2,0) (2,1) (2,2) (2,3)
	// (3,0) (3,1) (3,2) (3,3)

	// 찾으려는 곳이 (2,2)라면
	// 현재 위치 row가 2, col이 2를 넘어가면 분할하지 않아도 된다.
	// 분할하지 않는 대신, 분할하지 않는 사분면의 크기만큼 ans를 세어준다.
	// + 반대로 1사분면에 있다면 2사분면이나 3사분면을 분할하지 않아도 된다.
	// + 분할을 계속 하다보면 size가 1이 되는 때가 오는데 1*1=1이기 때문에 size=1일 때 굳이 제어를 안해줘도 됨!
	if (row + size <= r || col + size <= c || row > r || col > c) {
		ans += size * size;
	}
	else {
		int sub_size = size / 2;
		check_visit(sub_size, row, col);//2사분면 (0,0)
		check_visit(sub_size, row, col + sub_size);//1사분면 (0,1)
		check_visit(sub_size, row + sub_size, col);//3사분면 (1,0)
		check_visit(sub_size, row + sub_size, col + sub_size);//4사분면(1,1)
	}
}
int main() {
	cin >> n >> r >> c;

	check_visit(pow(2, n), 0, 0);
}