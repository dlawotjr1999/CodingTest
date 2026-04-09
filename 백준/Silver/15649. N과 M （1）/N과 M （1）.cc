#include <bits/stdc++.h>

int N, M;
std::vector<int> vec;

void DFS(int depth, int mask) {
	if (depth == M) {
		for (int x : vec) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
		return;
	}
	
	for (int i = 0; i < N; ++i) {
		if (mask & (1 << i))
			continue;
		vec.push_back(i + 1);
		DFS(depth + 1, mask | (1 << i));
		vec.pop_back();
	}
}

int main() {
	std::cin >> N >> M;
	DFS(0, 0);
}