#include <iostream>

int maze[101][101];  
char command[51];

int dx[4] = { 1, 0, -1, 0 };  
int dy[4] = { 0, -1, 0, 1 };

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> command[i];
	}

	int x = 50, y = 50;
	int dir = 0;

	maze[x][y] = 1;

	int min_x = x, max_x = x;
	int min_y = y, max_y = y;

	for (int i = 0; i < n; ++i) {
		if (command[i] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (command[i] == 'R') {
			dir = (dir + 1) % 4;
		}
		else if (command[i] == 'F') {
			x += dx[dir];
			y += dy[dir];

			maze[x][y] = 1;

			min_x = std::min(min_x, x);
			max_x = std::max(max_x, x);
			min_y = std::min(min_y, y);
			max_y = std::max(max_y, y);
		}
	}

	for (int i = min_x; i <= max_x; ++i) {
		for (int j = min_y; j <= max_y; ++j) {
			std:: cout << (maze[i][j] ? '.' : '#');
		}
		std::cout << '\n';
	}

	return 0;
}