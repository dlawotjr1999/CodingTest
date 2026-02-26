#include <bits/stdc++.h>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

char field[5][5];
std::unordered_set<std::string> s;

void DFS(int y, int x, std::string str) {
	if (str.length() == 6) {
		s.insert(str);
		return;
	}

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