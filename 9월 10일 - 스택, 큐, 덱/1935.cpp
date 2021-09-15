#include<iostream>
#include<stack>
using namespace std;
const int SIZE = 26;
int alph[SIZE];

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

		switch (str[i])
		{
		case '+': s.push(num2 + num1); break;
		case '-': s.push(num2 - num1); break;
		case '*': s.push(num2 * num1); break;
		case '/': s.push(num2 / num1);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}