#include <bits/stdc++.h>

int N;
char field[64][64];

std::string Partition(int start_y, int start_x, int end_y, int end_x) {
	bool isEqual = true;
	
	for (int i = start_y; i <= end_y; ++i) {
		for (int j = start_x; j <= end_x; ++j) {
			if (field[start_y][start_x] != field[i][j]) {
				isEqual = false;
				break;
			}
		}
		if (!isEqual)
			break;
	}

	if (isEqual && field[start_y][start_x] == '0')
		return "0";
	else if (isEqual && field[start_y][start_x] == '1')
		return "1";
	else if (!isEqual) {
		int mid_x = (start_x + end_x) / 2;
		int mid_y = (start_y + end_y) / 2;
		
		return '(' + Partition(start_y, start_x, mid_y, mid_x)
		 + Partition(start_y, mid_x + 1, mid_y, end_x)
		 + Partition(mid_y + 1, start_x, end_y, mid_x)
		 + Partition(mid_y + 1, mid_x + 1, end_y, end_x) + ')';
	}
}

int main() {
	std::cin >> N;
	std::string answer = "";

	for (int i = 0; i < N; ++i) {
		std::string input; std::cin >> input;

		for (int j = 0; j < input.length(); ++j) {
			field[i][j] = input[j];
		}
	}

	answer = Partition(0, 0, N - 1, N - 1);

	std::cout << answer;
	return 0;
}