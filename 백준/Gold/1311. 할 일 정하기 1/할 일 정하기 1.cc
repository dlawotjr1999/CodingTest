#include <bits/stdc++.h>

const int MAX = 1e9;

int N;
std::vector<std::vector<int>> field;
std::vector<std::vector<int>> DP;

int DFS(int cur, int mask) {
	if (cur == N)
		return 0;
	
	int& ret = DP[cur][mask];

	if (ret != -1)
		return DP[cur][mask];

	ret = MAX;
	for (int i = 0; i < N; ++i) {
		if (mask & (1 << i))
			continue;
		ret = std::min(ret, field[cur][i] + DFS(cur + 1, mask | (1 << i)));
	}
	
	return ret;
}

int main() {
	std::cin >> N;
	field.resize(N, std::vector<int>(N));
	DP.resize(N, std::vector<int>(1 << N, -1));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
		}
	}
	
	std::cout << DFS(0, 0);
	return 0;
}