#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool checkFirstAndEnd(string str) {
	if (isupper(str[0]) || str[0] == '_' || str[str.length() - 1] == '_') return true;
	return false;
}

bool continue_(string str) {
	for (int i = 0; i < str.length() - 1; i++)
		if (str[i] == '_' && str[i + 1] == '_') return true;
	return false;
}

string javaToCpp(string s) { //C++로
	string result;
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) result += '_'; //대문자라면 앞에 '_' 넣고나서
		result += tolower(s[i]); //소문자로 바꿔서 넣기
	}
	return result;
}
string cppToJava(string s) { // Java로
	string result;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '_') {
			result += toupper(s[i + 1]); // '_' 뒤에 나오는 문자 대문자로 바꿔서 넣기
			i++;
		}
		else result += s[i]; // 나머지는 그냥 넣기

	return result;
}

int main() {
	string str;
	cin >> str;

	int size = str.length() - 1;

	//1. 첫 문자가 대문자 또는 _ 일 때 오류
	//2. 마지막 문자가 _ 일 때 오류
	//3. 연속으로 _ 나올 때 오류
	if (checkFirstAndEnd(str) || continue_(str)) {
		cout << "Error!" << '\n';
		return 0;
	}

	if (str.find('_') != string::npos)
	{
		//4. C++에서 대문자 있을 때 오류
		for (int i = 0; i <= size; i++) {
			if (isupper(str[i])) {
				cout << "Error!" << '\n';
				return 0;
			}
		}
		//자바에서 C++
		cout << cppToJava(str);
	}
	else //C++에서 자바
		cout << javaToCpp(str);
}