#include <bits/stdc++.h>

int N, M;
std::vector<int> path;
std::vector<int> vec;

void DFS(int depth, int mask) {
	if (depth == M) {
		for (int x : path) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
		return;
	}
	
	for (int i = 0; i < N; ++i) {
		if (mask & (1 << i))
			continue;
		path.push_back(vec[i]);
		DFS(depth + 1, mask | (1 << i));
		path.pop_back();
	}
}

int main() {
	std::cin >> N >> M;
	vec.resize(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());

	DFS(0, 0);
}