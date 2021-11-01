#include<iostream>
using namespace std;

bool comp(int a[], int b[]) {
	int sum = 0, check = 0;
	for (int i = 0; i < 26; i++) {
		sum += abs(a[i] - b[i]);//문자 구성 차이
		check += a[i] - b[i];//글자 길이 차이
	}

	//한 단어에서 하나 더하거나 빼거나 다른 문자로 바꿈-> 문자 구성 개수 차이가 1개 이하
	//같은 길이, 같은 구성
	if (sum < 2 || (sum == 2 && check == 0)) return true;
	return false;
}

int main() {
	int n, ans = 0;
	string s;

	cin >> n;
	int alph1[26] = { 0 };
	cin >> s;//첫 번째 단어
	for (int i = 0; i < s.size(); i++)
		alph1[s[i] - 'A']++;

	while (--n) {
		int alph2[26] = { 0 };
		cin >> s;//비교할 단어
		for (int i = 0; i < s.size(); i++)
			alph2[s[i] - 'A']++;
		if (comp(alph1, alph2)) ans++;
	}

	cout << ans;
}