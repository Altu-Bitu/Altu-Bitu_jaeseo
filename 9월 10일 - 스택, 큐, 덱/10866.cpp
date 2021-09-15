#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<int> dq;
	int n, k;
	string str;
	cin >> n;

	while (n--)
	{
		cin >> str;

		if (str == "push_front") {
			cin >> k;
			dq.push_front(k);
			continue;
		}
		if (str == "push_back") {
			cin >> k;
			dq.push_back(k);
			continue;
		}
		if (str == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			continue;
		}
		if (str == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			continue;
		}
		if (str == "size") {
			cout << dq.size() << '\n';
			continue;
		}
		if (str == "empty") {
			cout << dq.empty() << '\n';
			continue;
		}
		if (str == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
			continue;
		}
		if (str == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
			continue;
		}
	}
}