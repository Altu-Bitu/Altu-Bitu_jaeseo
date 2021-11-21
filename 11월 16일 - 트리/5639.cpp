//참고풀이 : https://imnotabear.tistory.com/224
#include<iostream>
using namespace std;
const int SIZE = 10000;
void post(int* arr, int start, int end) {
	if (start >= end)//항상 start가 end보다 왼쪽에 있도록
		return;

	int idx = start+1;
	while (idx < end && arr[idx] < arr[start])//start+1~end에서, start에 있는 값보다 큰 걸 발견 할 때까지
		idx++;

	post(arr, start+1 , idx);//left subtree
	post(arr, idx, end);//right subtree

	cout << arr[start] << "\n";//root
}

int main() {
	int input, idx = 0;
	int tree[SIZE];

	//입력
	while (true) {
		cin >> input;
		if (cin.eof()) break;
		tree[idx++] = input;
	}
	//분할정복, 후위
	post(tree, 0, idx);
}