#include <iostream>
#include <vector>
#include <climits>

int N, M, K;
int answer = INT_MAX;

typedef struct {
	int r, c, s;
} op;

int field[51][51];
int rotated[51][51];

std::vector<op> ops;
std::vector<int> order;
std::vector<bool> visited;

void GetAnswer() {
	for (int i = 0; i < N; ++i) {
		int sum = 0;

		for (int j = 0; j < M; ++j) 
			sum += rotated[i][j];
		answer = std::min(answer, sum);
	}
}

void RotateField(int r, int c, int s) {
	int top = r - s - 1;
	int left = c - s - 1;
	int bottom = r + s - 1;
	int right = c + s - 1;

	while (top < bottom && left < right) {
		int saved = rotated[top][left];

		for (int i = top; i < bottom; ++i) 
			rotated[i][left] = rotated[i + 1][left];
		for (int j = left; j < right; ++j) 
			rotated[bottom][j] = rotated[bottom][j + 1];
		for (int i = bottom; i > top; --i) 
			rotated[i][right] = rotated[i - 1][right];
		for (int j = right; j > left + 1; --j) 
			rotated[top][j] = rotated[top][j - 1];

		rotated[top][left + 1] = saved;
		++top; ++left; --bottom; --right; 
	}
}

void DFS(int cnt) {
	if (cnt == K) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				rotated[i][j] = field[i][j];

		for (int i = 0; i < K; ++i) {
			int r = ops[order[i]].r;
			int c = ops[order[i]].c;
			int s = ops[order[i]].s;

			RotateField(r, c, s);
		}
		GetAnswer();
		return;
	}

	for (int i = 0; i < K; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			order[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M >> K;
	order.resize(K);
	visited.resize(K);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 0; i < K; ++i) {
		int r, c, s;
		std::cin >> r >> c >> s;
		ops.push_back({ r, c, s });
	}

	DFS(0);

	std::cout << answer;
	return 0;
}