#include<iostream>
#include<deque>
#include<cctype>
#include<string>
using namespace std;

deque<int> dequeAssign(deque<int> dq, string data) {
	string tmp = ""; // 십의자리수 넘어가는 숫자들 고려
	for (int i = 0; i < data.size(); i++) {
		if (isdigit(data[i])) tmp += data[i];
		else {  //'[' ']' ','
			if (tmp == "") continue; //빈문자열 넣으면 에러
			dq.push_back(stoi(tmp));
			tmp = "";
		}
	}
	return dq;
}

deque<int> operation(deque<int> dq, string fun, bool& funR, bool& error) {
	for (int i = 0; i < fun.size(); i++)
	{
		if (fun[i] == 'R') funR = !funR; // R 나오면 지금 상태의 역순으로
		else if (fun[i] == 'D') {
			if (dq.empty()) { //D인데 비어있으면 에러
				error = true;
				break;
			}

			funR ? dq.pop_back() : dq.pop_front(); // 역순으로 : 원래대로
		}
	}
	return dq;
}

int main() {
	int t, n;
	string fun, data;
	cin >> t;

	while (t--) {
		deque<int> dq;
		bool funR = false, error = false; //역순, 에러 여부

		cin >> fun >> n >> data;

		//data의 수들을 덱에 대입
		dq = dequeAssign(dq, data);

		//명령어 처리 된 덱
		dq = operation(dq, fun, funR, error);

		//출력
		if (error) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (dq.empty()); // 비었을 때
		else if (funR) { //역순
			while (dq.size() > 1) {
				cout << dq.back() << ",";
				dq.pop_back();
			}
			cout << dq.back();
		}
		else { //원래대로
			while (dq.size() > 1) {
				cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << dq.front();
		}
		cout << "]\n";

	}
}