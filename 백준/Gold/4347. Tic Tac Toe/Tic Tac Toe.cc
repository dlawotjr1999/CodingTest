#include <bits/stdc++.h>

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

		if (!(numO == numX || numO + 1 == numX))
			isPossible = false;

		else if (isWin(board, 'O') && isWin(board, 'X'))
			isPossible = false;

		else if (isWin(board, 'O') && numO != numX)
			isPossible = false;

		else if (isWin(board, 'X') && numO + 1 != numX)
			isPossible = false;

		std::cout << (isPossible ? "yes" : "no") << '\n';
	}

	return 0;
}