#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

map<string, int> cnt; //영어단어 나온 횟수

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
	if (p1.second != p2.second) return p1.second > p2.second;
	if (p1.first.size() != p2.first.size()) return p1.first.size() > p2.first.size();
	return p1.first < p2.first;
}

int main() {
	int n, m;
	string word;

	cin >> n >> m;

	while (n--)
	{
		cin >> word;
		if (m <= word.size()) cnt[word]++;
	}

	vector<pair<string, int>> voca(cnt.begin(), cnt.end());
	sort(voca.begin(), voca.end(), cmp);// 정렬된 단어장

	for (int i = 0; i < voca.size(); i++) cout << voca[i].first << '\n';
}