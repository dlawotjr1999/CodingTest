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

// 각 순열에 해당하는 회전 연산 후 변환된 원소들의 최솟값을 구함
void GetAnswer() {
	for (int i = 0; i < N; ++i) {
		int sum = 0;

		for (int j = 0; j < M; ++j) 
			sum += rotated[i][j];
		answer = std::min(answer, sum);
	}
}

void RotateField(int r, int c, int s) {
	// 0-based correction;
	int top = r - s - 1;
	int left = c - s - 1;
	int bottom = r + s - 1;
	int right = c + s - 1;

	while (top < bottom && left < right) {
		// 회전 범위 중 좌측 최상단 원소를 임시 저장
		int saved = rotated[top][left];

		// 가장 왼쪽 열의 원소들을 한 칸씩 위쪽으로 이동
		for (int i = top; i < bottom; ++i) 
			rotated[i][left] = rotated[i + 1][left];
		// 가장 아래쪽 행의 원소들을 한 칸씩 왼쪽으로 이동
		for (int j = left; j < right; ++j) 
			rotated[bottom][j] = rotated[bottom][j + 1];
		for (int i = bottom; i > top; --i) 
		// 가장 오른쪽 열의 원소들을 한 칸씩 아래쪽으로 이동
			rotated[i][right] = rotated[i - 1][right];
		// 가장 위쪽 행의 원소들을 한 칸씩 오른쪽으로 이동
		// 단, 이 행의 두 번째 원소부터 옮겨야 함
		for (int j = right; j > left + 1; --j) 
			rotated[top][j] = rotated[top][j - 1];

		// 이후 빈 칸에 임시 저장된 원소를 채워놓고 범위 보정
		rotated[top][left + 1] = saved;
		++top; ++left; --bottom; --right; 
	}
}

// 입력된 (r, c, s) 순서쌍의 순열을 구하는 backtracking 진행
// ops 배열의 모든 순열을 생성해 그 순서대로 회전 연산을 적용
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