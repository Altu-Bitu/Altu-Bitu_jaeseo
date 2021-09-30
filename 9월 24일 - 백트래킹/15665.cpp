#include<iostream>
#include<set>
using namespace std;

const int SIZE = 7;
int n, m;
set<int> inNum; //입력된 숫자
int outNum[SIZE]; //출력할 숫자

void backtracking(int cnt) {
	if (cnt == m) { //백트래킹 하면서 완성된 수열 출력
		for (int i = 0; i < cnt; i++)
			cout << outNum[i] << ' ';
		cout << '\n';
		return;
	}

	for (auto iter : inNum) { //처음 백트래킹 돌아올 때마다 inNum[0]부터 시작해서 중복, 사전 순으로 대입
		outNum[cnt] = iter;

		backtracking(cnt+1);
	}

}
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) { //set으로 중복제거, 오름차순
		int tmp;
		cin >> tmp;
		inNum.insert(tmp);
	}

	backtracking(0);
}