#include <iostream>
#include <queue>

constexpr int MAX = 5000001;

int T, A, B;
int answer;
bool visited[2][MAX];

void BFS(int drink, int fullness) {
	std::queue<std::pair<int, int>> q;
	q.push({ drink, fullness });
	visited[drink][fullness] = true;

	while (!q.empty()) {
		auto [d, f] = q.front();
		q.pop();

		answer = std::max(answer, f);

		for (int fruit : {A, B}) {
			int cur_f = f + fruit;
			if (cur_f <= T && !visited[d][cur_f]) {
				visited[d][cur_f] = true;
				q.push({d, cur_f});
			}
		}

		if (d == 0) {
			int cur_f = f / 2;
			if (!visited[1][cur_f]) {
				visited[1][cur_f] = true;
				q.push({ 1, cur_f });
			}
		}
	}
}

int main() {
	std::cin >> T >> A >> B;
	BFS(0, 0);

	std::cout << answer;
	return 0;
}