#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string str;
	double n=0.0;
	map<string, double> name;
	
	//입력 없을 때까지(ctrl+Z) 입력
	while (getline(cin, str)) {
		name[str]++;
		n++;
	}

	//소수점 4자리(반올림)까지 표현 고정
	cout << fixed;
	cout.precision(4);

	for (auto iter : name) cout << iter.first << ' '<<iter.second / n * 100.0 << '\n';
}