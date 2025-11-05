#include <bits/stdc++.h>

int dir_x[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int dir_y[8] = { -2, -2, -1, 1, 2, 2, -1, 1 };

bool visited[6][6];

int main() {
	std::string prev;
	std::string start;
	bool isValid = true;

	for (int i = 0; i < 36; ++i) {
		std::string cur;
		std::cin >> cur;

		int cur_col = cur[0] - 'A';
		int cur_row = cur[1] - '1';

		if (visited[cur_row][cur_col]) {
			isValid = false;
		}
		visited[cur_row][cur_col] = true;

		if (i == 0) {
			prev = cur;
			start = cur;
		}
		else if (i > 0 && i < 36) {
			bool isAccess = false;

			int prev_col = prev[0] - 'A';
			int prev_row = prev[1] - '1';

			for (int j = 0; j < 8; ++j) {
				int nx = prev_col + dir_x[j];
				int ny = prev_row + dir_y[j];

				if (nx == cur_col && ny == cur_row) {
					isAccess = true;
					break;
				}
			}

			if (!isAccess)
				isValid = false;
			prev = cur;

			if (i == 35) {
				bool canReturn = false;
				int start_col = start[0] - 'A';
				int start_row = start[1] - '1';
				for (int j = 0; j < 8; ++j) {
					int nx = cur_col + dir_x[j];
					int ny = cur_row + dir_y[j];
					if (nx == start_col && ny == start_row) {
						canReturn = true;
						break;
					}
				}
				if (!canReturn)
					isValid = false;
			}
		}
	}

	if (isValid)
		std::cout << "Valid";
	else
		std::cout << "Invalid";
	return 0;
}