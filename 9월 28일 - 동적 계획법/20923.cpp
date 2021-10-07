#include<iostream>
#include<queue>
using namespace std;

deque<int> deck[2], ground[2];//0은 도도꺼, 1은 수연꺼

int bellWin() {
	//그라운드가 어느 쪽도 비어있으면 안된다.
	//그라운드에 있는 카드 더미에서 가장 위에 위치한 카드의 숫자가 5 : 도도 종침
	if (!ground[0].empty() && ground[0].front() == 5 || ground[1].size() && ground[1].front() == 5) return 0;
	//그라운드에 있는 카드 더미에서 가장 위에 위치한 카드의 숫자 합이 5 : 수연이 종침
	if (!ground[0].empty() && ground[1].size() && ground[0].front() + ground[1].front() == 5) return 1;
	return -1;
}
void mergeCard(int w) {
	int opp = 1 - w;//상대방

	while (ground[opp].size()) {//상대방 그라운드 카드 뒤집어서 자신 덱 아래로 가져오기
		deck[w].push_back(ground[opp].back());
		ground[opp].pop_back();
	}
	while (ground[w].size()) { //자신 그라운드 카드 가져오기
		deck[w].push_back(ground[w].back());
		ground[w].pop_back();
	}
}
void game(int m) {
	bool turn = false;//도도부터 시작
	while (m--) {
		//2. 그라운드에 자신이 가진 덱에서 가장 위에 위치한 카드를 내려놓는다
		ground[turn].push_front(deck[turn].front());
		deck[turn].pop_front();

		//덱에 있는 카드 수가 0개 되는 즉시 게임 끝
		if (deck[turn].empty()) break;

		//3. 종 치기
		int w = bellWin();

		//4. 카드 가져오기
		if (w != -1)
			mergeCard(w);

		turn = !turn; //상대방 차례
	}
}
int main() {
	int n, m;//도도와 수연이가 가지는 카드개수n, 게임 진행 횟수m
	cin >> n >> m;

	//1. 덱 배분
	while (n--) {
		int dodo, su;
		cin >> dodo >> su;
		deck[0].push_front(dodo);//도도카드
		deck[1].push_front(su);//수연카드
	}

	//게임 진행
	game(m);

	//게임 끝, 결과 
	if (deck[0].size() > deck[1].size()) cout << "do" << '\n';
	else if (deck[0].size() < deck[1].size()) cout << "su" << '\n';
	else cout << "dosu" << '\n';
}