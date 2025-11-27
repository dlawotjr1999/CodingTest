#include <bits/stdc++.h>

// 6*6 체스판 위에서 나이트 투어가 가능한지를 구하는 문제
// 나이트 투어란 나이트가 모든 칸을 정확히 한 번씩만 방문하며, 마지막으로 방문하는 칸에서 시작점으로 돌아올 수 있는 경로를 의미함

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

		// 이미 방문한 칸에 도달했을 경우 invalid
		if (visited[cur_row][cur_col]) {
			isValid = false;
		}
		visited[cur_row][cur_col] = true;

		// 최초 이동인 경우, 마지막에 처음 지점으로 돌아올 수 있는 지 확인하기 위해 좌표 저장
		if (i == 0) {
			prev = cur;
			start = cur;
		}

		// 최초 이동과 마지막 이동을 제외한 모든 경우
		else if (i > 0 && i < 36) {
			bool isAccess = false;

			int prev_col = prev[0] - 'A';
			int prev_row = prev[1] - '1';

			// 나이트가 이동할 수 있는 모든 경로들 탐색
			for (int j = 0; j < 8; ++j) {
				int nx = prev_col + dir_x[j];
				int ny = prev_row + dir_y[j];

				if (nx == cur_col && ny == cur_row) {
					isAccess = true;
					break;
				}
			}

			// 칸을 벗어나는 경우 invalid하며, 현재 좌표를 기록
			if (!isAccess)
				isValid = false;
			prev = cur;

			// 마지막 이동 경우
			// 현재 지점에서 이동 가능한 8방향에서 시작 지점의 좌표로 이동할 수 있는지 확인
			// 이동할 수 없는 경우 invalid
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

	// 문제에 조건을 모두 충족하면 valid
	if (isValid)
		std::cout << "Valid";
	else
		std::cout << "Invalid";
	return 0;
}