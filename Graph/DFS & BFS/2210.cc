#include <bits/stdc++.h>

// 5*5 크기의 숫자판이 있고, 숫자판 내 임의의 칸에서 인접해 있는 네 방향으로 이동할 수 있음
// 그 칸에서 다섯 번 이동하면서 각 칸에 적혀있는 숫자를 차례로 붙여 6자리의 수를 만들고자 함
// 이 때, 만들 수 있는 서로 다른 여섯 자리 수들의 갯수를 구하는 문제

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

char field[5][5];

// 중복되는 문자열을 막기 위해 set 사용
std::unordered_set<std::string> s;

void DFS(int y, int x, std::string str) {
	// 만들어진 문자의 길이 6일 경우 조건을 만족하는 문자열
	if (str.length() == 6) {
		s.insert(str);
		return;
	}

	// 현재 위치를 기준으로 사방을 탐색하며 문자열 생성
	for (int d = 0; d < 4; ++d) {
		int nx = x + dir_x[d];
		int ny = y + dir_y[d];

		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;

		std::string cur = str + field[ny][nx];
		DFS(ny, nx, cur);
	}
}

int main() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cin >> field[i][j];
		}
	}

	// 모든 칸에 대해서 탐색
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::string init;
			init += field[i][j];
			DFS(i, j, init);
		}
	}

	std::cout << s.size();
	return 0;
}