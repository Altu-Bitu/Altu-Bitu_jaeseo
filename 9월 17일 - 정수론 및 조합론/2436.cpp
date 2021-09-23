#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	//a는 최대공약수, b는 최소공배수, A,B는 찾을 서로소
	int a, b, A, B;

	//b=(A*B)a
	//b/a=A*B
	cin >> a >> b;

	//c=A*B
	int c = b / a;

	for (int i = 1; i * i <= c; i++)
		if (c % i == 0 && gcd(i, c / i) == 1) { //서로소일 때
			A = i;
			B = c / i;
			if (A - B > 0) break; // 차가 양수가 됐을 때 합이 최소가 되니까 break
		}

	cout << A * a << ' ' << B * a;
}