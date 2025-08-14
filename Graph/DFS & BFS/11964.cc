#include <iostream>
#include <queue>

// 레몬과 오렌지를 먹으면서 배를 채울 때, 최대치로 가능한 포만도를 구하는 문제
// 중간에 물을 한 번 마시면 지금까지의 포만감을 반으로 줄일 수 있음 

constexpr int MAX = 5000001;

int T, A, B;
int answer;

// 물을 마셨을 때와 마시지 않았을 때를 구분하기 위해 visited 배열을 2차원으로 선언
bool visited[2][MAX];

// 각 레벨은 오렌지를 먹은 경우, 레몬을 먹은 경우, 물을 마시는 경우 세 가지의 트랜지션으로 구성됨
void BFS(int drink, int fullness) {
	std::queue<std::pair<int, int>> q;
	q.push({ drink, fullness });
	visited[drink][fullness] = true;

	while (!q.empty()) {
		auto [d, f] = q.front();
		q.pop();

		answer = std::max(answer, f);

		// 먹은 과일에 따라 경우의 수를 탐색함
		for (int fruit : {A, B}) {
			int cur_f = f + fruit;
			if (cur_f <= T && !visited[d][cur_f]) {
				visited[d][cur_f] = true;
				q.push({d, cur_f});
			}
		}

		// 물을 마시지 않은 경우
		// 물을 마시고, 그 flag를 표시한 다음 다시 queue에 삽입 
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