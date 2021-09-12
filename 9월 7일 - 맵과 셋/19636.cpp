#include<iostream>
using namespace std;
int main() {

	//다이어트 전 1 : 체중, 일일 에너지 섭취량, 일일 기초대사량
	//다이어트 중 2 : 기간, 일일 에너지 섭취량, 일일 활동 대사량

	int w1, i1, t1, day, i2, a2;
	cin >> w1 >> i1 >> t1 >> day >> i2 >> a2;

	// 기초 대사량 변화 고려x
	pair<int, int> noncon = make_pair(w1, i1);

	// 고려o
	pair<int, int> con = make_pair(w1, i1);

	bool danger1 = 0, danger2 = 0;//위험 여부

	while (day--) {
		noncon.first += i2 - (noncon.second + a2);//체중변화
		con.first += i2 - (con.second + a2);

		if (abs(i2 - (con.second + a2)) > t1) con.second += (i2 - (con.second + a2) - 1) / 2;// -5 / 2= -2 나오길래 -1

		if (noncon.first <= 0 || noncon.second <= 0) danger1 = true;
		if (con.first <= 0 || con.second <= 0) danger2 = true;
	}

	if (danger1 == 1) cout << "Danger Diet\n";
	else cout << noncon.first << ' ' << noncon.second << '\n';

	if (danger2 == 1) cout << "Danger Diet\n";
	else {
		cout << con.first << ' ' << con.second << ' ';

		if (i1 - con.second > 0) cout << "YOYO";
		else cout << "NO";
	}
}