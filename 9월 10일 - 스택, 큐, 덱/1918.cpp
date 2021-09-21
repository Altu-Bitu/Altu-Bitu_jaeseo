#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

int check(char c) {
	switch (c) {
	case '*': case '/': return 1; // 우선순위 가장 높음
	case '+': case '-': return 2; // 우선순위 낮음
	case '(': case ')': return 3; // 우선순위 없음
	}
}

int main() {
	string str;
	stack<char> s;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		//문자 먼저 출력
		if (isupper(str[i])) {
			cout << str[i];
			continue;
		}

		switch (str[i])
		{
		case '(': s.push(str[i]); break;
		case ')':
			while (!s.empty() && s.top() != '(') { //스택의 top값이 '('일 때까지 pop
				cout << s.top();
				s.pop();
			}
			s.pop(); //'(' 팝
			break;
		default:
			while (!s.empty() && check(s.top()) <= check(str[i])) { //현재 우선순위와 같거나 더 높다면 pop
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