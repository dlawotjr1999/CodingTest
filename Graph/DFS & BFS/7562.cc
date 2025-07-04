#include <iostream>
#include <cstring>
#include <queue>

// 체스판에 현재 나이트가 있는 칸, 이동하고자 하는 칸이 있을 때 최소 이동횟수를 구하는 문제
// 최소 횟수를 구해야함 -> BFS 이용

int field[300][300];
bool visited[300][300];

// 좌표와 움직인 횟수를 저장하는 구조체 이용
typedef struct Node {
	int x;
	int y;
	int cnt;
};

int BFS(int x, int y, int target_x, int target_y, int l) {
	std::queue<Node> q;
	// 현재 위치와 횟수 0으로 초기화
	q.push({ x, y, 0 });
	visited[x][y] = true;

	// 나이트가 움직일 수 있는 좌표
	int knight_x[8] = { 1,2,2,1,-1,-2,-2,-1 };
	int knight_y[8] = { -2,-1,1,2,2,1,-1,-2 };

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (cur_x == target_x && cur_y == target_y)
			return cnt;

		for (int i = 0; i < 8; ++i) {
			int new_x = cur_x + knight_x[i];
			int new_y = cur_y + knight_y[i];

			if ((0 <= new_x && new_x < l) && (0 <= new_y && new_y < l) && !visited[new_x][new_y]) {
				visited[new_x][new_y] = true;
				q.push({ new_x, new_y, cnt + 1 });
			}
		}
	}

	return 0;
}

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int l;
		std::cin >> l;

		memset(field, 0, sizeof(field));
		memset(visited, 0, sizeof(visited));

		int cur_x, cur_y;
		std::cin >> cur_x >> cur_y;

		int target_x, target_y;
		std::cin >> target_x >> target_y;

		std::cout << BFS(cur_x, cur_y, target_x, target_y, l) << '\n';
	}

	return 0;
}