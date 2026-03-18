#include <bits/stdc++.h>

const int MAX = 100000;
int answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<bool> visited(MAX + 1, false);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	pq.emplace(0, N);
	visited[N] = true;

	while (!pq.empty()) {
		auto [cur_time, cur_pos] = pq.top();
		pq.pop();

		if (cur_pos == K) {
			answer = cur_time;
			break;
		}

		if (cur_pos * 2 <= MAX && !visited[cur_pos * 2]) {
			visited[cur_pos * 2] = true;
			pq.emplace(cur_time, cur_pos * 2);
		}

		if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {
			visited[cur_pos - 1] = true;
			pq.emplace(cur_time + 1, cur_pos - 1);
		}

		if (cur_pos + 1 <= MAX && !visited[cur_pos + 1]) {
			visited[cur_pos + 1] = true;
			pq.emplace(cur_time + 1, cur_pos + 1);
		}

	}

	std::cout << answer;
	return 0;
}