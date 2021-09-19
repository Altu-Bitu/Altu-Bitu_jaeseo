#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<char> value;

void javaToCpp(string s) {
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') value.push_back('_');
		value.push_back(tolower(s[i]));
	}
}
void cppToJava(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '_') {
			value.push_back(toupper(s[i + 1]));
			i++;
		}
		else value.push_back(s[i]);
}

int main() {
	string str;
	cin >> str;

	int size = str.length() - 1;

	//1. 첫 문자가 대문자 또는 _
	//2. 마지막 문자가 _ 일 때 오류
	if (str[0] >= 'A' && str[0] <= 'Z' || str[0] == '_' || str[size] == '_') {
		cout << "Error!" << '\n';
		return 0;
	}

	//3. 연속으로 _ 나올 때 오류
	for (int i = 0; i < size; i++)
		if (str[i] == '_' && str[i + 1] == '_') {
			cout << "Error!" << '\n';
			return 0;
		}

	if (str.find('_') != string::npos)
	{
		//4. C++에서 대문자 있을 때 오류
		for (int i = 0; i <= size; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				cout << "Error!" << '\n';
				return 0;
			}
		}
		//자바에서 C++
		cppToJava(str);
	}
	else //C++에서 자바
		javaToCpp(str);

	for (auto iter : value) cout << iter;
}