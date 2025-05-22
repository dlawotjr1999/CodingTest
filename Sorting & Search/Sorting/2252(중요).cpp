#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> vec;
std::vector<int> degrees;
std::queue<int> queue;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	vec.resize(N + 1);
	degrees.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		std::cin >> s >> e;
		vec[s].emplace_back(e);
		degrees[e]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (degrees[i] == 0)
			queue.emplace(i);
	}

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();

		std::cout << cur << " ";
		for (int& next : vec[cur]) {
			degrees[next]--;
			if (degrees[next] == 0)
				queue.emplace(next);
		}
	}

}