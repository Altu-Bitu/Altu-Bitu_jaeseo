#include<vector>
#include<stack>
#include<iostream>

using namespace std;

vector<stack<int>> dolls;// board에 있는 인형들

stack<int> dollStack(vector<vector<int>>& board, int i) {
	stack<int> col;// board 열
	for (int j = board.size() - 1; j >= 0; j--)// 바닥에 있는 인형부터 스택에 쌓기
		if (board[j][i] != 0) col.push(board[j][i]); // 인형 넣기

	return col;
}

int dollMove(vector<vector<int>>& board, vector<int>& moves) {
	stack<int> s; //옮긴 인형 담는 바구니
	int answer = 0; //사라진 인형 수

	for (int i = 0; i < moves.size(); i++) { //인형 옮기기
		int pos = moves[i] - 1;

		if (dolls[pos].empty()) continue; //옮길 인형이 없을 때

		//인형들기
		int doll = dolls[pos].top();
		dolls[pos].pop();

		if (!s.empty() && s.top() == doll) { //같은 인형이 연속해서 쌓였을 때
			s.pop();
			answer += 2;//2개씩 터지니까
		}
		else s.push(doll); //다른 인형이 쌓였을 떄
	}
	return answer;
}

int solution(vector<vector<int>> board, vector<int> moves) {
	for (int i = 0; i < board.size(); i++) //각 열의 인형들을 스택에 넣기
		dolls.push_back(dollStack(board, i));
	int answer = dollMove(board, moves); // 인형 옮기기

	return answer;
}