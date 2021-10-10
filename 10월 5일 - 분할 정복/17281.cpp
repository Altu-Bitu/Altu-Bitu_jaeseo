#include<iostream>
#include<vector>
using namespace std;
const int MAX_PLAYER = 9 + 1;

int result;//최종결과
vector<vector<int>> inning;// 각 이닝에서 선수들이 낼 점수
vector<int> batter(MAX_PLAYER + 1, 0);// 타자 순서
vector<bool> check(MAX_PLAYER + 1, 0);// 이미 뽑은 선수인지 판단 

int play(int player, int& out, bool* base, int score) {
	switch (player) {
	case 0: out++; break;//아웃
	case 4: score++;//타자는 홈런 치면 홈으로 들어가기 때문에 점수+1
	default: //안타, 1루타, 2루타, 3루타
		for (int k = 3; k > 0; k--) {
			if (!base[k]) continue;//베이스에 선수가 안 서 있으면 continue

			int next = k + player;//현재 서있는 루에서 기록을 더한 루까지 전진
			if (next >= 4) score++;//홈으로 들어가면 점수+1
			else base[next] = true;//홈으로 못 들어가면 그냥 전진만

			base[k] = false;//원래 있던 루에선 떠남
		}
		base[player] = true;//타자가 선 루
	}
	return score;
}
void game(int n) {
	int score = 0;//이닝 당 점수
	int start_player = 1;// 전 이닝 이어서 시작하는 선수 start_player

	for (int i = 1; i <= n; i++) {// n 이닝 진행
		int out = 0;//아웃카운트 out
		bool next_inning = false;//다음 이닝으로 넘어가는 지 확인

		bool base[5] = { false };
		//base[1]: 1루, base[2]: 2루, base[3]: 3루에 선수가 서 있는 지 확인
		//base[0]==base[4] : 홈
		//base[i]==true : 선수가 서 있음, base[i]==false : 선수가 안 서 있음

		while (true) {
			for (int j = start_player; j < MAX_PLAYER; j++) {
				int player = inning[i][batter[j]];//타자 출전.

				//타자 볼 치는 중
				score = play(player, out, base, score);

				if (out == 3) {// 3 아웃되면 다음 이닝
					start_player = (j + 1) % MAX_PLAYER;//다음 이닝에 시작할 선수
					if (start_player == 0) start_player = 1;

					next_inning = true;
					break;
				}
			}
			if (next_inning) break;
			start_player = 1;
		}
	}
	result = (score > result ? score : result);
}
void backtracking(int cnt, int n) {
	//가장 점수가 높게 나올 수 있는 타자 순서를 세우기 위한 순열
	//다 정했으면 경기 시작
	if (cnt == MAX_PLAYER) {
		game(n);
		return;
	}

	for (int i = 1; i < MAX_PLAYER; i++) {
		if (check[i]) continue;//이미 타자로 결정된 선수
		check[i] = true;
		batter[i] = cnt;

		backtracking(cnt + 1, n);
		check[i] = false;
	}
}
int main() {
	int n;//이닝 수n
	cin >> n;
	inning.assign(n + 1, vector<int>(MAX_PLAYER, 0));

	//4 0 0 0 0 0 0 0 0 => inning[1][1]=4 : 1 이닝에서 1번 선수가 홈런을 친다.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < MAX_PLAYER; j++)
			cin >> inning[i][j];

	//1번 선수는 4번 타자로 고정
	check[4] = true; //4번 타자 골라짐.
	batter[4] = 1; //1번이 4번 타자

	//경기
	backtracking(2, n);//1번선수는 골랐으니까 2번 선수부터 타자 순서 정한 후, 경기시작

	//경기결과
	cout << result;
}