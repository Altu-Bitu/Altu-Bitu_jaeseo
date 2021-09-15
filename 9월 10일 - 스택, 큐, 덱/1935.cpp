#include<iostream>
#include<stack>
using namespace std;
const int SIZE = 26;
int alph[SIZE];

double operation(char c, double n1, double n2) {
	switch (c)
	{
	case '+': return n2 + n1;
	case '-': return n2 - n1;
	case '*': return n2 * n1;
	case '/': return n2 / n1;
	}
}

int main() {
	int n;
	string str;
	stack<double> s;

	cin >> n;
	cin >> str;

	//각 알파벳 순서에 숫자 입력
	for (int i = 0; i < n; i++) cin >> alph[i];

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(alph[str[i] - 'A']); //'A'-'A'= 0
			continue;
		}

		//계산할 숫자
		double num1 = s.top();
		s.pop();
		double num2 = s.top();
		s.pop();

		//계산
		s.push(operation(str[i], num1, num2));
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}