#include <bits/stdc++.h>

// X부터 시작하는 Tic Tac Toe 게임의 현재 상태가 주어질 때, 그 상태가 가능한 상태인지 판별하는 문제

// 승리 조건을 판별하는 함수
bool isWin(const std::vector<std::string>& board, char c) {
	// horizontal
	for (int i = 0; i < 3; ++i) {
		if (board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return true;
	}

	// vertical
	for (int i = 0; i < 3; ++i) {
		if (board[0][i] == c && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return true;
	}

	// diagonal
	if (board[0][0] == c && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
		board[0][2] == c && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;

	return false;
}

int main() {
	int N; std::cin >> N;

	for (int t = 0; t < N; ++t) {
		int numX = 0, numO = 0;
		std::vector<std::string> board(3);
		bool isPossible = true;

		for (int i = 0; i < 3; ++i) {
			std::string line; std::cin >> line;

			for (int j = 0; j < 3; ++j) {
				if (line[j] == 'O')
					numO++;
				else if (line[j] == 'X')
					numX++;
			}
			board[i] = line;
		}

		// x부터 두기 때문에 x의 수는 o의 수와 같거나 반드시 하나가 많아야 함
		if (!(numO == numX || numO + 1 == numX))
			isPossible = false;

		// o와 x 둘 다 이기는 것은 불가능
		else if (isWin(board, 'O') && isWin(board, 'X'))
			isPossible = false;

		// o가 이겼음에도 x와 o의 수가 다른 경우는 불가능
		// 즉, o가 이길 경우는 o와 x의 수가 같아야만 함
		else if (isWin(board, 'O') && numO != numX)
			isPossible = false;

		// x가 이겼음에도 (x의 수 + 1)과 o의 수가 다른 경우는 불가능
		// 즉, x가 이길 경우는 x의 수가 o의 수보다 반드시 하나가 많아야 함
		else if (isWin(board, 'X') && numO + 1 != numX)
			isPossible = false;

		// 위 네 가지를 제외하고는 모두 가능함
		std::cout << (isPossible ? "yes" : "no") << '\n';
	}

	return 0;
}