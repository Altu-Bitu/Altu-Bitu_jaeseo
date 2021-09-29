#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool is_vowel(char c) {
	switch (c)
	case 'a': case 'e': case 'i': case'o': case'u': return true;
	return false;
}
int main() {
	int l, c;
	cin >> l >> c;
	vector<char> alph(c, 0);
	vector<bool> check(c, false);

	for (int i = 0; i < c; i++)
		cin >> alph[i];// 알파벳 입력
	sort(alph.begin(), alph.end()); // 알파벳 오름차순 정렬

	for (int i = 0; i < l; i++)
		check[i] = true;// l개 알파벳 true로 셋팅

	do {
		string s = ""; //암호
		int vo = 0, co = 0;//모음과 자음 개수

		for (int i = 0; i < c; i++)
			if (check[i]) {
				if (is_vowel(alph[i]))
					vo++;
				else
					co++;
				s += alph[i];
			}
		if (vo >= 1 && co >= 2)	//단어가 되는 조건 모음이 적어도 하나, 자음이 적어도 두 개
			cout << s << '\n';
	} while (prev_permutation(check.begin(), check.end()));
}