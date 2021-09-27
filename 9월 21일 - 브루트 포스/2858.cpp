#include<iostream>
using namespace std;
int main() {
	int r, b, w, l;
	cin >> r >> b;

	r += b;
	for (l = r; l >= 1; l--) {
		w = r / l;

		if ((l - 2) * (w - 2) == b) break; //가장자리를 뺀 타일을 곱하면 b가 나옴
	}
	cout << l << ' ' << w;
}