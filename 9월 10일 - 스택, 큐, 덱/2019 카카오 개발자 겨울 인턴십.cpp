#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s; //바구니
	vector<stack<int>> col(board.size());// board 열

	for (int i = 0; i < board.size(); i++)
		for (int j = board.size() - 1; j >= 0; j--) {
			if (board[j][i] != 0 && isdigit(board[j][i])) col[i].push(board[j][i]);
		}//[]때문에 말썽,,

	for (int i = 0; i < moves.size(); i++)
	{
		if (col[moves[i] - 1].top() == 0) continue;

		if (!s.empty() && s.top() == col[moves[i] - 1].top())
		{
			s.pop();
			answer += 2;//2개씩 터지니까
		}
		else s.push(col[moves[i] - 1].top());

		col[moves[i] - 1].pop();

	}
	return answer;
}