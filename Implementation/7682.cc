#include <bits/stdc++.h>

// 틱택토 게임이 즉시 끝나는 조건은 아래와 같음
// 1. 한 사람이 가로, 세로, 대각선 방향으로 3칸을 잇는데 성공함
// 2. 게임판이 가득 차는 경우
// 첫 번째 사람이 X를 놓고 두 번째 사람이 O를 놓을 때, 주어진 문자열이 틱택토 게임에서 발생할 수 있는 최종 상태인지를 구하는 문제

bool isWin(const std::string& str, char c) {
	// 같은 행에 세 개가 연속으로 있으면 승리
	for (int i = 0; i < 9; i += 3) {
		if (str[i] == c && str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {
			return true;
		}
	}

	// 같은 열에 세 개가 연속으로 있으면 승리
	for (int i = 0; i < 3; ++i) {
		if (str[i] == c && str[i] == str[i + 3] && str[i + 3] == str[i + 6]) {
			return true;
		}
	}

	// 두 종류의 각 대각선에 세 개가 연속으로 있으면 승리 
	if ((str[0] == c && str[0] == str[4] && str[4] == str[8]) || (str[2] == c && str[2] == str[4] && str[4] == str[6])) {
		return true;
	}

	return false;
}

int main() {

	while (true) {
		std::string str;
		std::cin >> str;

		if (str == "end")
			break;

		int o_cnt = 0;
		int x_cnt = 0;

		// O와 X의 갯수를 각각 세어 계산
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == 'O')
				o_cnt++;
			else if (str[i] == 'X')
				x_cnt++;
		}

		bool o_win = isWin(str, 'O');
		bool x_win = isWin(str, 'X');

		// X가 O보다 하나 더 많은 상태에서 X가 이기면 유효함
		if (x_win && !o_win && x_cnt == o_cnt + 1)
			std::cout << "valid";
		// X와 O의 갯수가 같은 상태에서, O가 이기면 유효함(X가 먼저 두기 때문)
		else if (o_win && !x_win && o_cnt == x_cnt)
			std::cout << "valid";
		// X와 O 둘 다 이기지 못한 상태에서 판이 모두 차면 유효함
		else if (!o_win && !x_win && (o_cnt == 4 && x_cnt == 5))
			std::cout << "valid";
		// 나머지 경우는 모두 최종 상태가 아님 
		else
			std::cout << "invalid";

		std::cout << '\n';
	}

	return 0;
}