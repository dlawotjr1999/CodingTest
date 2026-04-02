#include <bits/stdc++.h>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> vec(N + 1);
	std::vector<int> degree(N + 1);
	std::queue<int> q;
	std::vector<int> result;
	
	for (int i = 1; i <= M; ++i) {
		int n;	std::cin >> n;

		std::vector<int> info(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> info[j];
		}

		for (int j = 0; j < n - 1; ++j) {
			int u = info[j];
			int v = info[j + 1];
			vec[u].push_back(v);	
			degree[v]++;
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		result.push_back(cur);

		for (int next : vec[cur]) {
			degree[next]--;
			if (degree[next] == 0)
				q.push(next);
		}
	}

	if ((int)result.size() != N) {
		std::cout << 0;
	}
	else {
		for (int x : result)
			std::cout << x << '\n';
	}
}
