#include<iostream>
#include<stack>
using namespace std;

bool check(char c1, char c2) {
	//-,+면 '(' 나올 때까지만 pop하면 되니까 true
	if (c1 == '-' || c1 == '+') return true;

	//*,/ 는 다음 *,/ 오면 또 pop해야 되니까 true
	if ((c1 == '*' || c1 == '/') && (c2 == '*' || c2 == '/')) return true;

	else return false;
}

int main() {
	string str;
	stack<char> s;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		//문자 먼저 출력
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
			continue;
		}

		switch (str[i])
		{
		case '(': s.push(str[i]); break;
		case ')':
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop(); //'(' 팝
			break;
		default:
			while (!s.empty() && check(str[i], s.top()) && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty()) { //남은 거
		cout << s.top();
		s.pop();
	}
}