#include <iostream>
 
// 입력된 커맨드를 통해 미로의 모습을 구현하는 문제
// F는 앞으로 한 칸, L과 R은 왼쪽 또는 오른쪽으로의 전환을 의미함

// 커맨드의 0~50의 길이를 가지며, 시작점이 정해져있지 않기 때문에 -50~50을 표현할 수 있도록 크기를 잡음
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

	int x = 50, y = 50;	// 필드의 중간 지점을 시작 지점으로 잡음
	int dir = 0;		// 남쪽을 0으로 표현

	// 현재 위치를 표시
	maze[x][y] = 1;

	int min_x = x, max_x = x;
	int min_y = y, max_y = y;

	for (int i = 0; i < n; ++i) {

		// 시계 방향으로 방위를 표현
		if (command[i] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (command[i] == 'R') {
			dir = (dir + 1) % 4;
		}

		// F인 경우 한 칸 전진
		else if (command[i] == 'F') {
			x += dx[dir];
			y += dy[dir];

			maze[x][y] = 1;

			// x방향의 최소, 최댓값과 y방향의 최소, 최댓값을 통해 표현되어야 하는 필드를 범위를 정함
			min_x = std::min(min_x, x);
			max_x = std::max(max_x, x);
			min_y = std::min(min_y, y);
			max_y = std::max(max_y, y);
		}
	}

	for (int i = min_x; i <= max_x; ++i) {
		for (int j = min_y; j <= max_y; ++j) {

			// 지나간 곳은 .으로, 아닌 곳은 #으로 표현
			std:: cout << (maze[i][j] ? '.' : '#');
		}
		std::cout << '\n';
	}

	return 0;
}